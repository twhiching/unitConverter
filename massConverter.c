#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"

// TODO add conversion between mass id's of 1 and 0
double convertMass(char* originalUnit, char* desiredUnit, char* quantityOfUnit){

	double result = 0;
	double temp = atof(quantityOfUnit);
	
	char units[9][15] = {"metric-ton","kilogram","gram","milligram","microgram","ton","ounce","pound","stone"};
	int massID[9] = {1,1,1,1,1,0,0,0,0};
	int powerID[9] = {6,3,0,-3,-6,0,0,0,0};
	int i,idFirst,idSecond;
	idFirst = -1;
	idSecond = -1;
	
	for(i = 0; i < 9; ++i){
		if(strcmp(originalUnit,units[i]) == 0){
			idFirst = i;
			break;
		}
	}
	for(i = 0; i < 9; ++i){
		if(strcmp(desiredUnit,units[i]) == 0){
			idSecond = i;
			break;
		}
	}

	printf("id first:%d\nid second:%d\n",idFirst,idSecond);
	// Converting between metric units
	if(massID[idFirst] == 1 && massID[idSecond] ==1){
		//Going from high to low unit of power, else vice-versa
		if(powerID[idFirst] > powerID[idSecond]){
			
			result = temp * pow(10,(abs(powerID[idFirst])+abs(powerID[idSecond])));
		}else{
			result = temp/(pow(10,(abs(powerID[idFirst])+abs(powerID[idSecond]))));
		}
	}else if(massID[idFirst] == 0 && massID[idSecond] ==0){
		// Converting between Non metric units
		if(strcmp(originalUnit,"ounce") == 0){
			if(strcmp(desiredUnit,"pound") == 0){
				result = temp / 16;
			}else if(strcmp(desiredUnit,"ton") == 0){
				result = temp / 32000;
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp / 224;
			}else if(strcmp(desiredUnit,"ounce") == 0){
				result = temp / 1;
			}
		}else if(strcmp(originalUnit,"pound") == 0){
			if(strcmp(desiredUnit,"ounce") == 0){
				result = temp * 16;
			}else if(strcmp(desiredUnit,"ton") == 0){
				result = temp / 2000;
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp / 14;
			}else if(strcmp(desiredUnit,"pound") == 0){
				result = temp / 1;
			}

		}else if(strcmp(originalUnit,"ton") == 0){
			if(strcmp(desiredUnit,"pound") == 0){
				result = temp * 2000;
			}else if(strcmp(desiredUnit,"ounce") == 0){
				result = temp * 32000;
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp * 142.857;
			}else if(strcmp(desiredUnit,"ton") == 0){
				result = temp / 1;
			}

		}else if(strcmp(originalUnit,"stone") == 0){
			if(strcmp(desiredUnit,"pound") == 0){
				result = temp * 14;
			}else if(strcmp(desiredUnit,"ton") == 0){
				result = temp / 142.857;
			}else if(strcmp(desiredUnit,"ounce") == 0){
				result = temp * 224;
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp / 1;
			}
		}	
	}else{
		//Converting between a mixture of the two

	}
	return result;
}
