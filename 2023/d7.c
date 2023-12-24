#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HANDSIZE 1000 //5 1000

int cardValue(char c);
int getHandType(int h[7]);
int handSort(const void *a, const void *b);

int main(){
	
	FILE *file = fopen("input.txt", "r");
	char line[256];
	char *ptr;
	int sum = 0;

	int hands[HANDSIZE][7];

	int currentHand = 0;
	while(fgets(line, sizeof(line), file)){
		ptr = strtok(line, " ");//hand
		//printf("%s\n", ptr);
		//get hands
		//convert cards to nums
		int currentCard = 1;
		while(ptr != NULL && *ptr != '\0'){
			hands[currentHand][currentCard] = cardValue(*ptr);
			ptr++;
			currentCard++;
		}
		hands[currentHand][0] = getHandType(hands[currentHand]);
		ptr = strtok(NULL, "\n");//bet
		hands[currentHand][6] = strtol(ptr, &ptr, 10);
		
		/*for(int i = 0; i < 7; i++){
			printf("%d\n", hands[currentHand][i]);
		}*/
		//printf("Hand Val: %d, Card Nums: %d %d %d %d %d, Bet: %d\n", hands[currentHand][0], hands[currentHand][1], hands[currentHand][2], hands[currentHand][3], hands[currentHand][4], hands[currentHand][5], hands[currentHand][6]);
		currentHand++;

	//Array = {Hand, C1, C2, C3, C4, C5, Bet}
	//qsort
	//sort = hand type, then value of cards in order
	//mulitply bet by position
	}
	qsort(hands, sizeof hands / sizeof *hands, sizeof *hands, handSort);
	printf("\nSorted:\n");
	for(int i = 0; i < HANDSIZE; i++){
		printf("Hand Val: %d, Card Nums: %d %d %d %d %d, Bet: %d Multiplier: %d\n", hands[i][0], hands[i][1], hands[i][2], hands[i][3], hands[i][4], hands[i][5], hands[i][6], i+1);
		sum += (hands[i][6]*(i+1));
		//printf("bet %d, multiplier: %d, sum: %d\n", hands[i][6], i+1, sum);
	}
	
	printf("Sum: %d\n", sum);
	fclose(file);
	return 0;
}

int cardValue(char c){
	char cardStrength[13] = {'J', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'A'};
	for(int i = 0; i < 13; i++){
		if(c == cardStrength[i]){
			return i+2;
		}
	}
}

int getHandType(int h[7]){
	int handType = 0;
	
	int foundCards[5];
	
	//x of a kind
	int maxCardCount = 0;
	int pairCount = 0;
	int tripleCount = 0;
	int jokerCount = 0;
	for(int i = 1; i < 6; i++){//check each card
		int cardCount = 0;
		int found = 0;
		if(h[i] == 2){
			jokerCount++;
		}
		for(int f = 0; f < 5; f++){
			if(foundCards[f] == h[i]){
				found = h[i];
			}
		}
		if(found == 0){
			for(int j = 1; j < 6; j++){//compare to all cards
				if(h[i] == h[j]){
					cardCount++;
				}
			}
			
			if(cardCount == 2){
				pairCount++;
			}
			if(cardCount == 3){
				tripleCount++;
			}
			//printf("%d Count: %d \n", h[i], cardCount);
		}
		if(cardCount > maxCardCount){
			maxCardCount = cardCount;
		}
		foundCards[i] = h[i];
	}
	//printf("Max Card: %d\n", maxCardCount);
	
	switch(maxCardCount){
		case 5:
			handType = 6;
			break;
		case 4:
			if(jokerCount == 1 || jokerCount == 4){
				handType = 6;
			}else{
				handType = 5;
			}
			break;
		case 3:
			if(jokerCount == 2 || (jokerCount == 3 && pairCount == 1)){
				handType = 6;
			}else if(jokerCount == 3 || jokerCount == 1){
				handType = 5;
			}else{
				handType = 3;
			}
			break;
		case 2:
			if(jokerCount == 2 && pairCount == 2){
				handType = 5;
			}else if(jokerCount == 1 || jokerCount == 2){
				handType = 3;
			}else{
				handType = 1;
			}	
			break;
		default:
			if(jokerCount == 1){
				handType = 1;
			}
			break;
	} 
	if((pairCount == 2 || (pairCount == 1 && jokerCount == 1)) && handType < 2){
		handType = 2;
	}else if(((pairCount == 1 && tripleCount == 1) || (pairCount == 2 && jokerCount == 1) ||(pairCount == 2 && jokerCount == 2)) && handType < 4){
		handType = 4;
	}
	printf("Hand: %d-%d-%d-%d-%d HT: %d Pairs: %d Trips: %d Jokers: %d\n", h[1], h[2], h[3], h[4], h[5], handType, pairCount, tripleCount, jokerCount);
	return handType;
}

int handSort(const void *a, const void *b){
	const int * const ia = a, * const ib = b;
	int returnNum = 0;
	
	if(ia[0]==ib[0]){
		if(ia[1]==ib[1]){
			if(ia[2]==ib[2]){
				if(ia[3]==ib[3]){
					if(ia[4]==ib[4]){
						returnNum = ia[5]-ib[5];
					}else{
						returnNum = ia[4]-ib[4];
					}
				}else{
					returnNum = ia[3]-ib[3];
				}
			}else{
				returnNum = ia[2]-ib[2];
			}
		}else{
			returnNum = ia[1]-ib[1];
		}
	}else{
		returnNum = ia[0]-ib[0];
	}
	return returnNum;
}
