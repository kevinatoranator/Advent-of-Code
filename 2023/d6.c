#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
	
	
	unsigned long long sum = 0;

	//int races[2] = {71530, 940200};
	unsigned long long races[2] = {46807866, 214117714021024};
	

	for(unsigned long long j = 0; j < races[0]; j++){
		unsigned long long distance = j*(races[0]-j);
		if(distance > races[1]){
			sum++;
		}
	}
			
	
	printf("Sum: %d\n", sum);
	return 0;
}

