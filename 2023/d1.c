#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* strlaststr(const char* haystack, const char* needle);

int main(){
	
	FILE *file = fopen("input.txt", "r");
	char line[256];
	char *ptr;
	int sum = 0;
	char digits[2];
	
	while(fgets(line, sizeof(line), file)){
		int num1 = 0;
		int num2 = 0;
		int num1pos = strlen(line);
		int num2pos = 0;
		for(int i =0; i < strlen(line); i++){
			if(isdigit(line[i])){
				//printf("num found %c\n", line[i]);
				num1 = line[i]-'0';
				num2 = line[i]-'0';
				num1pos = i;
				break;
			}				
		}
		for(int i =strlen(line); i >= 0; i--){
			if(isdigit(line[i])){
				//printf("num found %c\n", line[i]);
				num2 = line[i]-'0';
				num2pos = i;
				printf("num2pos: %d\n", num2pos);
				break;
			}				
		}
		if(strstr(line, "one")){
			char *pos = strstr(line, "one");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "one");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 1;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 1;
			}
			//printf("found @ %d\n", p);
		}
		if(strstr(line, "two")){
			char *pos = strstr(line, "two");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "two");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 2;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 2;
			}
			//printf("found @ %d\n", p);
		}
		if(strstr(line, "three")){
			char *pos = strstr(line, "three");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "three");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 3;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 3;
			}
			//printf("found @ %d\n", p);
		}
		if(strstr(line, "four")){
			char *pos = strstr(line, "four");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "four");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 4;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 4;
			}
			//printf("found @ %d\n", p);
		}
		if(strstr(line, "five")){
			char *pos = strstr(line, "five");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "five");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 5;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 5;
			}
			//printf("found @ %d\n", p);
		}
		if(strstr(line, "six")){
			char *pos = strstr(line, "six");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "six");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 6;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 6;
			}
			//printf("found @ %d\n", p);
		}
		if(strstr(line, "seven")){
			char *pos = strstr(line, "seven");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "seven");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 7;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 7;
			}
			//printf("found @ %d\n", p);
		}
		if(strstr(line, "eight")){
			char *pos = strstr(line, "eight");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "eight");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 8;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 8;
			}
			//printf("found 8 @ %d\n", p);
		}
		if(strstr(line, "nine")){
			char *pos = strstr(line, "nine");
			int p;
			p = pos - line;
			
			char *rpos = strlaststr(line, "nine");
			int rp;
			rp = rpos - line;
			if(p < num1pos){
				num1pos = p;
				num1 = 9;
			}
			if(rp > num2pos){
				num2pos = rp;
				num2 = 9;
			}
			//printf("found @ %d\n", p);
		}
	
		printf("1st num: %d  ", num1);
		printf("2nd num: %d\n", num2);
		
		digits[0] = num1 + '0';
		digits[1] = num2 + '0';
		printf("Digits: %s\n", digits);
		sum += strtol(digits, &ptr, 10);
		
	}
	printf("%d\n", sum);
	fclose(file);
	return 0;
}

char* strlaststr(const char* haystack, const char* needle){
	char* loc = 0;
	char* found = 0;
	size_t pos = 0;
	while((found = strstr(haystack + pos, needle)) != 0){
		loc = found;
		pos = (found-haystack) + 1;
	}
	return loc;
}
