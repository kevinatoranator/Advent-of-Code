#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <limits.h>

#define SEEDS 20 //4 20

unsigned long matcher(unsigned long sn, unsigned long *da);

int main(){
	
	FILE *file = fopen("input.txt", "r");
	char line[256];
	char *ptr;
	unsigned long sum = 0;

	
	unsigned long seedStart[SEEDS/2];
	unsigned long seedEnd[SEEDS/2];
	//dest src range
	
	unsigned long soil[37][3]; //2 37
	unsigned long fertilizer[19][3]; //3 19
	unsigned long water[9][3]; //4 9
	unsigned long light[26][3]; //2 26
	unsigned long temp[46][3]; //3 46
	unsigned long humid[25][3]; //2 25
	unsigned long loc[20][3]; //2 20
	
	fgets(line, sizeof(line), file);
	sscanf(line + strlen("seeds: "), "%lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", &seedStart[0], &seedEnd[0], &seedStart[1], &seedEnd[1], &seedStart[2], &seedEnd[2], &seedStart[3], &seedEnd[3], &seedStart[4], &seedEnd[4], &seedStart[5], &seedEnd[5], &seedStart[6], &seedEnd[6], &seedStart[7], &seedEnd[7], &seedStart[8], &seedEnd[8], &seedStart[9], &seedEnd[9]);

	int currentEntry = 0;
	while(!strstr(line, "seed-to-soil map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%lu %lu %lu", &soil[currentEntry][0], &soil[currentEntry][1], &soil[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	currentEntry = 0;
	while(!strstr(line, "soil-to-fertilizer map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%lu %lu %lu", &fertilizer[currentEntry][0], &fertilizer[currentEntry][1], &fertilizer[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	
	currentEntry = 0;
	while(!strstr(line, "fertilizer-to-water map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%lu %lu %lu", &water[currentEntry][0], &water[currentEntry][1], &water[currentEntry][2]);
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
		sscanf(line, "%lu %lu %lu", &light[currentEntry][0], &light[currentEntry][1], &light[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	
	currentEntry = 0;
	while(!strstr(line, "light-to-temperature map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%lu %lu %lu", &temp[currentEntry][0], &temp[currentEntry][1], &temp[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	
	currentEntry = 0;
	while(!strstr(line, "temperature-to-humidity map:")){
		fgets(line, sizeof(line), file);
	}
	fgets(line, sizeof(line), file);
	while(isdigit(line[0])){
		sscanf(line, "%lu %lu %lu", &humid[currentEntry][0], &humid[currentEntry][1], &humid[currentEntry][2]);
		currentEntry++;
		fgets(line, sizeof(line), file);
	}
	
	currentEntry = 0;
	while(!strstr(line, "humidity-to-location map:")){
		fgets(line, sizeof(line), file);
	}

	while(fgets(line, sizeof(line), file)){
		sscanf(line, "%lu %lu %lu", &loc[currentEntry][0], &loc[currentEntry][1], &loc[currentEntry][2]);
		currentEntry++;
	}
	/*for(int i = 0; i < 2; i++){
		printf("loc %d: %ld %ld %ld\n", i, loc[i][0], loc[i][1], loc[i][2]);
	}*/

	for(int i = 0; i < SEEDS/2; i++){
		printf("%d\n", i);
		for(unsigned long s = seedStart[i]; s < seedStart[i]+seedEnd[i]; s++){
			unsigned long locNum = s;
			//printf("Seed Num: %lu\n", s);
			for(int j = 0; j < sizeof(soil) / sizeof(soil[0]); j++){
				if(locNum >= soil[j][1] && locNum < (soil[j][1] + soil[j][2])){
					locNum = matcher(locNum, soil[j]);
					break;
				}
			}
			//printf("Soil Num: %lu\n", locNum);

			for(int j = 0; j < sizeof(fertilizer) / sizeof(fertilizer[0]); j++){
				if(locNum >= fertilizer[j][1] && locNum < (fertilizer[j][1] + fertilizer[j][2])){
					locNum = matcher(locNum, fertilizer[j]);
					break;
				}
			}
			//printf("Fert Num: %lu\n", locNum);
			
			for(int j = 0; j < sizeof(water) / sizeof(water[0]); j++){
				if(locNum >= water[j][1] && locNum < (water[j][1] + water[j][2])){
					locNum = matcher(locNum, water[j]);
					break;
				}
			}
			//printf("Water Num: %lu\n", locNum);
			
			for(int j = 0; j < sizeof(light) / sizeof(light[0]); j++){
				if(locNum >= light[j][1] && locNum < (light[j][1] + light[j][2])){
					locNum = matcher(locNum, light[j]);
					break;
				}
			}
			//printf("Light Num: %lu\n", locNum);

			for(int j = 0; j < sizeof(temp) / sizeof(temp[0]); j++){
				if(locNum >= temp[j][1] && locNum < (temp[j][1] + temp[j][2])){
					locNum = matcher(locNum, temp[j]);
					break;
				}
			}
			//printf("Temp Num: %lu\n", locNum);
			
			for(int j = 0; j < sizeof(humid) / sizeof(humid[0]); j++){
				if(locNum >= humid[j][1] && locNum < (humid[j][1] + humid[j][2])){
					locNum = matcher(locNum, humid[j]);
					break;
				}
			}
			
			//printf("Humid Num: %lu\n", locNum);
			
			for(int j = 0; j < sizeof(loc) / sizeof(loc[0]); j++){
				if(locNum >= loc[j][1] && locNum < (loc[j][1] + loc[j][2])){
					locNum = matcher(locNum, loc[j]);
					break;
				}
			}
			//printf("Loc Num: %lu\n\n", locNum);
			
			if(locNum < sum || sum == 0){
				sum = locNum;
			}
		}
	}
	printf("Sum: %lu\n", sum);
	return 0;
}

unsigned long matcher(unsigned long sn, unsigned long *da){
	//printf("sn %ld\n", sn);
	unsigned long dn = da[0] + sn - da[1];
	return dn;
}