#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


char* getNum(char* charNum);
bool valueinarray(char* val, char *arr[], size_t n);

int main(){
	
	FILE *file = fopen("input.txt", "r"); //140x140
	char line[256];
	char *ptr;
	int sum = 0;
	const int dem = 140;
	
	char nchars[] = "1234567890";
	
	char grid[dem*dem];
	
	int linen = 0;
	while(fgets(line, sizeof(line), file)){
		line[strcspn(line, "\n")] = 0;
		if(linen == 0){
			strcpy(grid, line);
			linen = 1;
		}else{
			strcat(grid, line);
		}
	}
	printf("%s\n", grid);
	char *p;

	for(p = grid; *p; p++){
		if(*p == '*'){
			char *ptrNums[8];
			int intNums[8];
			int currentNum = 0;
			//printf("DIGIT %c [%d,%d]\n", *p,(p-grid)/dem,(p-grid)%dem); 
				if(p > grid+dem){
					if((p-grid)%dem > 0){
						char *topLeft = p-dem-1;
						if(strchr(nchars, *topLeft)){
							printf("found char: %c\n", *topLeft);
							if(!valueinarray(getNum(topLeft), ptrNums, currentNum)){
								ptrNums[currentNum] = getNum(topLeft);
								intNums[currentNum] = strtol(getNum(topLeft), &topLeft, 10);
								currentNum ++;
							}
							printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
						}
					}
					if((p-grid)%dem < dem - 1){
						char *topRight = p-dem+1;
						if(strchr(nchars, *topRight)){
							printf("found char: %c\n", *topRight);
							if(!valueinarray(getNum(topRight), ptrNums, currentNum)){
								ptrNums[currentNum] = getNum(topRight);
								intNums[currentNum] = strtol(getNum(topRight), &topRight, 10);
								currentNum ++;
							}
							printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
						}
					}
					char *topMiddle = p-dem;
					if(strchr(nchars, *topMiddle)){
						printf("found char: %c\n", *topMiddle);
						if(!valueinarray(getNum(topMiddle), ptrNums, currentNum)){
								ptrNums[currentNum] = getNum(topMiddle);
								intNums[currentNum] = strtol(getNum(topMiddle), &topMiddle, 10);
								currentNum ++;
							}
						printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
					}
					
				}
				if(p-grid < dem*dem-dem){
					if((p-grid)%dem > 0){
						char *bottomLeft = p+dem-1;
						if(strchr(nchars, *bottomLeft)){
							printf("found char: %c\n", *bottomLeft);
							if(!valueinarray(getNum(bottomLeft), ptrNums, currentNum)){
								ptrNums[currentNum] = getNum(bottomLeft);
								intNums[currentNum] = strtol(getNum(bottomLeft), &bottomLeft, 10);
								currentNum ++;
							}
							printf("Adj. Nums: %d, Current Sum: %d\n", currentNum, sum);
						}
					}
					if((p-grid)%dem < dem - 1){
						char *bottomRight = p+dem+1;
						if(strchr(nchars, *bottomRight)){
							printf("found char: %c\n", *bottomRight);
							if(!valueinarray(getNum(bottomRight), ptrNums, currentNum)){
								ptrNums[currentNum] = getNum(bottomRight);
								intNums[currentNum] = strtol(getNum(bottomRight), &bottomRight, 10);
								currentNum ++;
							}
							printf("Adj. Nums: %d, Current Sum: %d\n", currentNum, sum);
						}
					}
					char *bottomMiddle = p+dem;
					if(strchr(nchars, *bottomMiddle)){
						printf("found char: %c\n", *bottomMiddle);
						if(!valueinarray(getNum(bottomMiddle), ptrNums, currentNum)){
								ptrNums[currentNum] = getNum(bottomMiddle);
								intNums[currentNum] = strtol(getNum(bottomMiddle), &bottomMiddle, 10);
								currentNum ++;
							}
						printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
					}
				}
				char *left = p-1;
				if((p-grid)%dem > 0){
					if(strchr(nchars, *left)){
						printf("found char: %c\n", *left);
						if(!valueinarray(getNum(left), ptrNums, currentNum)){
								ptrNums[currentNum] = getNum(left);
								intNums[currentNum] = strtol(getNum(left), &left, 10);
								currentNum ++;
							}
						printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
					}
				}
				char *right = p+1;
				if((p-grid)%dem < dem - 1){
					if(strchr(nchars, *right)){
						printf("found char: %c\n", *right);
						if(!valueinarray(getNum(right), ptrNums, currentNum)){
								ptrNums[currentNum] = getNum(right);
								intNums[currentNum] = strtol(getNum(right), &right, 10);
								currentNum ++;
							}
						printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
					}
				}
				if(currentNum == 2){
					sum += intNums[0]*intNums[1];
				}
			//currentNum = 0;
		}
	}
	printf("Sum: %d\n", sum);
	fclose(file);
	return 0;
}

char* getNum(char* charNum){
	char *startNum = charNum;
	while(isdigit(*startNum)){
		//printf("s:%c\n", *startNum);
		startNum -=1;
	}
	return startNum+1;
}

bool valueinarray(char* val, char *arr[], size_t n) {
    for(size_t i = 0; i < n; i++) {
        if(arr[i] == val)
            return true;
    }
    return false;
}