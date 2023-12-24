#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SEEDS 4

long int matcher(long int sn, long int *da);

int main(){
	
	FILE *file = fopen("test.txt", "r");
	char line[256];
	char *ptr;
	int sum = 0;

	
	long int tseeds[SEEDS];
	
	long int seedStart[SEEDS/2];
	long int seedEnd[SEEDS/2];
	//dest src range
	
	long int soil[2][3]; //2
	long int fertilizer[3][3];
	long int water[4][3];
	long int light[2][3];
	long int temp[3][3];
	long int humid[2][3];
	long int loc[2][3];
	
	fgets(line, sizeof(line), file);
	sscanf(line + strlen("seeds: "), "%ld %ld %ld %ld", &seedStart[0], &seedEnd[0], &seedStart[1], &seedEnd[1]);

	int currentEntry = 0;
	while(!strstr(line, "seed-to-soil map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%ld %ld %ld", &soil[currentEntry][0], &soil[currentEntry][1], &soil[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	currentEntry = 0;
	while(!strstr(line, "soil-to-fertilizer map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%ld %ld %ld", &fertilizer[currentEntry][0], &fertilizer[currentEntry][1], &fertilizer[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	
	currentEntry = 0;
	while(!strstr(line, "fertilizer-to-water map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%ld %ld %ld", &water[currentEntry][0], &water[currentEntry][1], &water[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
		//printf("%ld %ld %ld\n", water[currentEntry][0], water[currentEntry][1], water[currentEntry][2]);
	}
	
	currentEntry = 0;
	while(!strstr(line, "water-to-light map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%ld %ld %ld", &light[currentEntry][0], &light[currentEntry][1], &light[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	
	currentEntry = 0;
	while(!strstr(line, "light-to-temperature map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%ld %ld %ld", &temp[currentEntry][0], &temp[currentEntry][1], &temp[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	
	currentEntry = 0;
	while(!strstr(line, "temperature-to-humidity map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%ld %ld %ld", &humid[currentEntry][0], &humid[currentEntry][1], &humid[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	
	currentEntry = 0;
	while(!strstr(line, "humidity-to-location map:")){
		fgets(line, sizeof(line), file);
	}

	while(fgets(line, sizeof(line), file)){
		sscanf(line, "%ld %ld %ld", &loc[currentEntry][0], &loc[currentEntry][1], &loc[currentEntry][2]);
		currentEntry++;
	}
	/*for(int i = 0; i < 2; i++){
		printf("loc %d: %ld %ld %ld\n", i, loc[i][0], loc[i][1], loc[i][2]);
	}*/

	for(int i = 0; i < SEEDS/2; i++){
		for(int s = seedStart[i]; s < seedStart[i]+seedEnd[i]; s++){
			int locNum = s;
			printf("Seed Num: %ld\n", s);
			for(int j = 0; j < sizeof(soil) / sizeof(soil[0]); j++){
				if(locNum >= soil[j][1] && locNum < (soil[j][1] + soil[j][2])){
					locNum = matcher(locNum, soil[j]);
					break;
				}
			}
			printf("Soil Num: %ld\n", locNum);

			for(int j = 0; j < sizeof(fertilizer) / sizeof(fertilizer[0]); j++){
				if(locNum >= fertilizer[j][1] && locNum < (fertilizer[j][1] + fertilizer[j][2])){
					locNum = matcher(locNum, fertilizer[j]);
					break;
				}
			}
			printf("Fert Num: %ld\n", locNum);
			
			for(int j = 0; j < sizeof(water) / sizeof(water[0]); j++){
				if(locNum >= water[j][1] && locNum < (water[j][1] + water[j][2])){
					locNum = matcher(locNum, water[j]);
					break;
				}
			}
			printf("Water Num: %ld\n", locNum);
			
			for(int j = 0; j < sizeof(light) / sizeof(light[0]); j++){
				if(locNum >= light[j][1] && locNum < (light[j][1] + light[j][2])){
					locNum = matcher(locNum, light[j]);
					break;
				}
			}
			printf("Light Num: %ld\n", locNum);

			for(int j = 0; j < sizeof(temp) / sizeof(temp[0]); j++){
				if(locNum >= temp[j][1] && locNum < (temp[j][1] + temp[j][2])){
					locNum = matcher(locNum, temp[j]);
					break;
				}
			}
			printf("Temp Num: %ld\n", locNum);
			
			for(int j = 0; j < sizeof(humid) / sizeof(humid[0]); j++){
				if(locNum >= humid[j][1] && locNum < (humid[j][1] + humid[j][2])){
					locNum = matcher(locNum, humid[j]);
					break;
				}
			}
			
			printf("Humid Num: %ld\n", locNum);
			
			for(int j = 0; j < sizeof(loc) / sizeof(loc[0]); j++){
				if(locNum >= loc[j][1] && locNum < (loc[j][1] + loc[j][2])){
					locNum = matcher(locNum, loc[j]);
					break;
				}
			}
			printf("Loc Num: %ld\n\n", locNum);
			
			if(locNum < sum || sum == 0){
				sum = locNum;
			}
		}
	}
	printf("Sum: %ld\n", sum);
	return 0;
}

long int matcher(long int sn, long int *da){
	//printf("sn %ld\n", sn);
	long int dn = da[0] + sn - da[1];
	return dn;
}