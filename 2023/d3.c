#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* getNum(char* charNum);

int main(){
	
	FILE *file = fopen("test.txt", "r"); //140x140
	char line[256];
	char *ptr;
	int sum = 0;
	const int dem = 10;
	
	char nchars[] = "1234567890.";
	
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
		if(isdigit(*p)){
			int currentNum = *p;
			//printf("DIGIT %c [%d,%d]\n", *p,(p-grid)/dem,(p-grid)%dem); 
				if(p-dem > grid+dem){
					if((p-grid)%dem > 0){
						if(!strchr(nchars, *(p-dem-1))){
							printf("found char: %c\n", *(p-dem-1));
							currentNum = strtol(getNum(p), &p, 10);
							sum += abs(currentNum);
							printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
						}
					}
					if((p-grid)%dem < dem - 1){
						if(!strchr(nchars, *(p-dem+1))){
							printf("found char: %c\n", *(p-dem+1));
							currentNum = strtol(getNum(p), &p, 10);
							sum += abs(currentNum);
							printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
						}
					}
					if(!strchr(nchars, *(p-dem))){
						printf("found char: %c\n", *(p-dem));
						currentNum = strtol(getNum(p), &p, 10);
						sum += abs(currentNum);
						printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
					}
					
				}
				if(p-grid < dem*dem-dem){
					if((p-grid)%dem > 0){
						if(!strchr(nchars, *(p+dem-1))){
							printf("found char: %c\n", *(p+dem-1));
							currentNum = strtol(getNum(p), &p, 10);
							sum += abs(currentNum);
							printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
						}
					}
					if((p-grid)%dem < dem - 1){
						if(!strchr(nchars, *(p+dem+1))){
							printf("found char: %c\n", *(p+dem+1));
							currentNum = strtol(getNum(p), &p, 10);
							sum += abs(currentNum);
							printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
						}
					}
					if(!strchr(nchars, *(p+dem))){
						printf("found char: %c\n", *(p+dem));
						currentNum = strtol(getNum(p), &p, 10);
						sum += abs(currentNum);
						printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
					}
				}
				if((p-grid)%dem > 0){
					if(!strchr(nchars, *(p-1))){
						printf("found char: %c\n", *(p-1));
						currentNum = strtol(getNum(p), &p, 10);
						sum += abs(currentNum);
						printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
					}
				}
				if((p-grid)%dem < dem - 1){
					if(!strchr(nchars, *(p+1))){
						printf("found char: %c\n", *(p+1));
						currentNum = strtol(getNum(p), &p, 10);
						sum += abs(currentNum);
						printf("Whole Num TL: %d\nCurrent Sum: %d\n", currentNum, sum);
					}
				}
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