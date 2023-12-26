#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//struct of key - outL, outR all 3 char strings linked list

struct map{
	char node[4];
	char outLeft[4];
	char outRight[4];
	struct  map *next;
};

int main(){
	FILE *file = fopen("input.txt", "r");
	char line[512];
	char *ptr;
	
	struct map *first = NULL;
	
	int sum = 0;
	char pattern[512];
	fgets(pattern, sizeof(line), file);
	pattern[strcspn(pattern, "\n")]=0;
	printf("Pattern = %s\n", pattern);
	
	while(fgets(line, sizeof(line), file)){
		if(line[0] != '\n'){
			struct map *new = (struct map*)malloc(sizeof(struct map));
			ptr = strtok(line, " ");
			//ptr -> node
			strcpy(new->node, ptr);
		//	printf("%s, ", ptr);
			ptr = strtok(NULL, "(");
			ptr = strtok(NULL, ", ");
		//	printf("%s -", ptr);
			strcpy(new->outLeft, ptr);
			//ptr = strtok(NULL, "");
			ptr = strtok(NULL, ")");
		//	printf("%s\n", ptr);
			ptr = ptr+1;
			strcpy(new->outRight, ptr);
			//printf("Node: %s Left: %s Right: %s\n", new->node, new->outLeft, new->outRight);
			new->next = first;
			first = new;
			//free(new);
			
			
		}
	}
	struct map *current = first;
	while(current->next != NULL){
			//printf("Node: %s Left: %s Right: %s\n", current->node, current->outLeft, current->outRight);
		current = current->next;
	}
	//printf("%s\n", current->node);
	//get exit or current from last
	//pattern pointer++ if = null pattern pointer = pattern
	struct map *p = first;
	//printf("Node: %s Left: %s Right: %s\n", current->node, current->outLeft, current->outRight);
	//printf("P: %s Left: %s \n", current->node, current->outLeft);
	printf("Plen: %d \n", strlen(pattern));
	int patternChar = 0;
	while(strcmp(current->node, "ZZZ")){
		p = first;
		char currentDir = pattern[patternChar];
		//printf("cchar %c\n", currentDir);
		//printf("Dir: %c, Node: %s Left: %s Right: %s\n", currentDir, current->node, current->outLeft, current->outRight);
		if(currentDir == 'R'){
			while(strcmp(p->node, current->outRight)){
				//printf("Dir: %c, P: %s CR: %s \n", currentDir, p->node, current->outRight);
				p = p->next;
			}
		}else{
			while(strcmp(p->node, current->outLeft)){
				//printf("Dir: %c, P: %s CL: %s \n", currentDir, p->node, current->outLeft);
				p = p->next;
			}
		}
		current = p;
		sum++;
		if(patternChar < strlen(pattern)-1){
			patternChar++;
		}else{
			patternChar = 0;
		}
	}
	printf("%d", sum);
}