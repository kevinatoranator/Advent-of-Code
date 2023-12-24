#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int matcher(int sn, int *da);

int main(){
	
	FILE *file = fopen("input.txt", "r");
	char line[256];
	char *ptr;
	int sum = 0;

	
	struct seed{
		int snum;
		int soil;
		int fert;
		int wate;
		int ligh;
		int temp;
		int humi;
		int loca;
	};
	
	struct seed seed0;
	struct seed seed1;
	struct seed seed2;
	struct seed seed3;
	
	struct seed seedarr[4] = {seed0, seed1, seed2, seed3};
	
	int tseeds[4] = {79, 14, 55, 13};
	//dest src range
	int tsoil[2][3] = {{50, 98, 2}, {52, 50, 48}};
	int tfertilizer[3][3] = {{0, 15, 37}, {37, 52, 2}, {39, 0, 15}};
	int twater[4][3] = {{49, 53, 8}, {0, 11, 42}, {42, 0, 7}, {57, 7, 4}};
	int tlight[2][3] = {{88, 18, 7}, {18, 25, 70}};
	int ttemp[3][3] = {{45, 77, 23} ,{81, 45, 19}, {68, 64, 13}};
	int thumid[2][3] = {{0, 69, 1}, {1, 0, 69}};
	int tloc[2][3] = {{60, 56, 37}, {56, 93, 4}};
	
	int soil[2][3] = {{50, 98, 2}, {52, 50, 48}};
	int fertilizer[3][3] = {{0, 15, 37}, {37, 52, 2}, {39, 0, 15}};
	int water[4][3] = {{49, 53, 8}, {0, 11, 42}, {42, 0, 7}, {57, 7, 4}};
	int light[2][3] = {{88, 18, 7}, {18, 25, 70}};
	int temp[3][3] = {{45, 77, 23} ,{81, 45, 19}, {68, 64, 13}};
	int humid[2][3] = {{0, 69, 1}, {1, 0, 69}};
	int loc[2][3] = {{60, 56, 37}, {56, 93, 4}};
	
	for(int i = 0; i < 4; i++){
		seedarr[i].snum = tseeds[i];
		printf("Seed Num: %d\n", seedarr[i].snum);
		
		seedarr[i].soil = seedarr[i].snum;
		for(int j = 0; j < sizeof(tsoil) / sizeof(tsoil[0]); j++){
			if(seedarr[i].snum >= tsoil[j][1] && seedarr[i].snum < (tsoil[j][1] + tsoil[j][2])){
				seedarr[i].soil = matcher(seedarr[i].snum, tsoil[j]);
			}
		}
		printf("Soil Num: %d\n", seedarr[i].soil);
		
		seedarr[i].fert = seedarr[i].soil;
		for(int j = 0; j < sizeof(tfertilizer) / sizeof(tfertilizer[0]); j++){
			if(seedarr[i].soil >= tfertilizer[j][1] && seedarr[i].soil < (tfertilizer[j][1] + tfertilizer[j][2])){
				seedarr[i].fert = matcher(seedarr[i].soil, tfertilizer[j]);
			}
		}
		printf("Fert Num: %d\n", seedarr[i].fert);
		
		seedarr[i].wate = seedarr[i].fert;
		for(int j = 0; j < sizeof(twater) / sizeof(twater[0]); j++){
			if(seedarr[i].fert >= twater[j][1] && seedarr[i].fert < (twater[j][1] + twater[j][2])){
				seedarr[i].wate = matcher(seedarr[i].fert, twater[j]);
			}
		}
		printf("Water Num: %d\n", seedarr[i].wate);
		
		seedarr[i].ligh = seedarr[i].wate;
		for(int j = 0; j < sizeof(tlight) / sizeof(tlight[0]); j++){
			if(seedarr[i].wate >= tlight[j][1] && seedarr[i].wate < (tlight[j][1] + tlight[j][2])){
				seedarr[i].ligh = matcher(seedarr[i].wate, tlight[j]);
			}
		}
		printf("Light Num: %d\n", seedarr[i].ligh);
		
		seedarr[i].temp = seedarr[i].ligh;
		for(int j = 0; j < sizeof(ttemp) / sizeof(ttemp[0]); j++){
			if(seedarr[i].ligh >= ttemp[j][1] && seedarr[i].ligh < (ttemp[j][1] + ttemp[j][2])){
				seedarr[i].temp = matcher(seedarr[i].ligh, ttemp[j]);
			}
		}
		printf("Temp Num: %d\n", seedarr[i].temp);
		
		seedarr[i].humi = seedarr[i].temp;
		for(int j = 0; j < sizeof(thumid) / sizeof(thumid[0]); j++){
			if(seedarr[i].temp >= thumid[j][1] && seedarr[i].temp < (thumid[j][1] + thumid[j][2])){
				seedarr[i].humi = matcher(seedarr[i].temp, thumid[j]);
			}
		}
		printf("Humid Num: %d\n", seedarr[i].humi);
		
		seedarr[i].loca = seedarr[i].humi;
		for(int j = 0; j < sizeof(tloc) / sizeof(tloc[0]); j++){
			if(seedarr[i].humi >= tloc[j][1] && seedarr[i].humi < (tloc[j][1] + tloc[j][2])){
				seedarr[i].loca = matcher(seedarr[i].humi, tloc[j]);
			}
		}
		printf("Loc Num: %d\n\n", seedarr[i].loca);
	}

	sum = seedarr[0].loca;
	for(int i = 1; i < 4; i++){
		if(seedarr[i].loca < sum){
			sum = seedarr[i].loca;
		}
	}
	
	printf("Sum: %d\n", sum);
	fclose(file);
	return 0;
}

int matcher(int sn, int *da){
	int dn = da[0] + sn - da[1];
	return dn;
}