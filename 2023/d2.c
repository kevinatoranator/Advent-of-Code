#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
	
	FILE *file = fopen("input.txt", "r");
	char line[256];
	char *ptr;
	char *op;
	int sum = 0;
	const int maxRed = 12;
	const int maxGreen = 13;
	const int maxBlue = 14;
	
	while(fgets(line, sizeof(line), file)){
		//printf("%s\n" , line);
		ptr = strstr(line, ":");
		size_t len = ptr - line;
		char gamestr[len];
		strncpy(gamestr, line, len);
		//printf("%s\n", gamestr);
		char gm[10];
		int gmnum;
		sscanf(gamestr, "%s %d", gm, &gmnum);
		printf("%s, %d\n", gm, gmnum);
		
		
		char *pulls[10];	
		char *token = strtok(ptr+1, ";");
		int currentPull = 0;
		while(token != NULL){
			printf("%s\n", token);
			pulls[currentPull] = token;
			currentPull += 1;

			
			token = strtok(NULL, ";");
		}
		int valid = 1;
		int redHigh = 0;
		int blueHigh = 0;
		int greenHigh = 0;
		for(int i = 0; i <currentPull; i++){
			//printf("Pull %d:%s\n", i,pulls[i]);
			char *pullt = strtok(pulls[i], ",");
			while(pullt != NULL){
				//printf("%s\n", pullt+1);
				int num = 0;
				char color[10];
				sscanf(pullt, "%d %s", &num, color);
				printf("Num %d, Color %s\n", num, color); 
				/*if(strcmp(color,"red") == 0 && num > maxRed){ #part 1
					//printf("bad red\n");
					valid = 0;
				}else if(strcmp(color, "blue") == 0 && num > maxBlue){
					//printf("bad blue\n");
					valid = 0;
				}else if(strcmp(color, "green") == 0 && num > maxGreen){
					//printf("bad green\n");
					valid = 0;
				}*/
				if(strcmp(color,"red") == 0){
					//printf(" red\n");
					if(num > redHigh){
						//printf("new rhgih\n");
						redHigh = num;
					}
					//valid = 0;
				}else if(strcmp(color, "blue") == 0){
					if(num > blueHigh){
						blueHigh = num;
					}
					//printf("bad blue\n");
					//valid = 0;
				}else if(strcmp(color, "green") == 0){
					if(num > greenHigh){
						greenHigh = num;
					}
					//printf("bad green\n");
					//valid = 0;
				}
				pullt = strtok(NULL, ",");
			}
		}
		printf("Red: %d, Blue: %d, Green %d\n", redHigh, blueHigh, greenHigh);
		sum += redHigh * blueHigh * greenHigh;
		//if(valid == 1){
			//printf("valid pulls\n");
			//printf("%d\n", gmnum);
			//sum += gmnum;
		//}
	}
	printf("\n%d\n", sum);
	fclose(file);
	return 0;
}

