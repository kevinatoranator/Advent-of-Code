#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CARDS 196 //6 196
#define TICKETS 10 //5 10
#define WINNING 25 //8 25


int main(){
	
	FILE *file = fopen("input.txt", "r");
	char line[256];
	char *ptr;
	int sum = 0;

	
	
	int cardArray[CARDS] = {0};
	int ticketNum = 0;
	while(fgets(line, sizeof(line), file)){
		ptr = strstr(line, ":")+2;
				
		int ticketNums[TICKETS];
		int winningNums[WINNING];
		char *nums = strtok(ptr, " ");
		int entry = 0;
		while(nums != NULL){
			ticketNums[entry] = strtol(nums, &ptr, 10);
			printf("Num: %d\n", strtol(nums, &ptr, 10));
			nums = strtok(NULL, " ");
			entry++;
			
			if(*nums == '|'){
				//nums += 1;
				int wentry = 0;
				while(nums != NULL){
					if(strtol(nums, &ptr, 10) !=0){
						printf("Wins: %d\n", strtol(nums, &ptr, 10));
						winningNums[wentry] = strtol(nums, &ptr, 10);
						wentry++;
					}
					nums = strtok(NULL, " ");
				}
			}
		}
		int cardSum = 0;
		for(int i = 0; i < TICKETS; i++){
			for(int j = 0; j < WINNING; j++){
				//printf("TEST I:%d vs J: %d\n", ticketNums[i], winningNums[j]);
				if(ticketNums[i] == winningNums[j]){
					printf("Matched %d, %d\n", ticketNums[i], winningNums[j]);
					cardSum ++;
					break;
				}
			}
		}
		printf("Card Sum: %d\n", cardSum);
		for(int k = 0; k < cardArray[ticketNum]+1; k++){
			//printf("TN %d\n", cardArray[ticketNum]);
			for(int l = 0; l < cardSum; l++){
				if(l+ticketNum < CARDS){
					cardArray[l+ticketNum+1] = cardArray[l+ticketNum+1]+1;	
					//printf("Card %d has %d cards.\n", l+ticketNum+2, cardArray[l+ticketNum+1]);
				}
			}		
			sum += cardSum;
		}
		ticketNum++;
	}
	
	printf("Sum: %d\n", sum+CARDS);
	fclose(file);
	return 0;
}

