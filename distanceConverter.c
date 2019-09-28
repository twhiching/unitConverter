#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"

double convertDistance(char* originalUnit, char* desiredUnit, char* quantityOfUnit){

	double result = 0;
	double temp = atof(quantityOfUnit);
	
	char units[9][15] = {"kilometer","meter","centimeter","millimeter","inch","foot","yard","mile"};
	int massID[9] = {1,1,1,1,0,0,0,0};
	int powerID[9] = {3,0,-2,-3,0,0,0,0};
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
		if(strcmp(originalUnit,"inch") == 0){
			if(strcmp(desiredUnit,"foot") == 0){
				result = temp / 12;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp / 36;
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp / 63360;
			}else if(strcmp(desiredUnit,"inch") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"foot") == 0){
			if(strcmp(desiredUnit,"foot") == 0){
				result = temp / 1;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp / 3;
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp / 5280;
			}else if(strcmp(desiredUnit,"inch") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"yard") == 0){
			if(strcmp(desiredUnit,"foot") == 0){
				result = temp * 3;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp;
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp / 1760;
			}else if(strcmp(desiredUnit,"inch") == 0){
				result = temp * 36;
			}

		}else if(strcmp(originalUnit,"mile") == 0){
			if(strcmp(desiredUnit,"foot") == 0){
				result = temp * 5280;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp * 1760;
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp;
			}else if(strcmp(desiredUnit,"inch") == 0){
				result = temp * 63360;
			}
		}
	}else{
		//Converting between a mixture of the two
		if(strcmp(originalUnit,"kilometer") == 0){
			if(strcmp(desiredUnit,"inch") == 0){
				result = temp * 39370.079;
			}else if(strcmp(desiredUnit,"foot") == 0){
				result = temp * 3280.84;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp * 1093.613;
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp / 1.609;
			}else if(strcmp(desiredUnit,"kilometer") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"meter") == 0){
			if(strcmp(desiredUnit,"inch") == 0){
				result = temp * 39.37;
			}else if(strcmp(desiredUnit,"foot") == 0){
				result = temp * 3.281;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp * 1.094;
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp / 1609.344;
			}else if(strcmp(desiredUnit,"meter") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"centimeter") == 0){
			if(strcmp(desiredUnit,"inch") == 0){
				result = temp / 2.54;
			}else if(strcmp(desiredUnit,"foot") == 0){
				result = temp / 30.48;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp / 91.44;
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp / 160934.4;
			}else if(strcmp(desiredUnit,"centimeter") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"millimeter") == 0){
			if(strcmp(desiredUnit,"inch") == 0){
				result = temp / 25.4;
			}else if(strcmp(desiredUnit,"foot") == 0){
				result = temp / 304.8;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp / 914.4;
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp / (1.609 * pow(10,6));
			}else if(strcmp(desiredUnit,"millimeter") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"inch") == 0){
			if(strcmp(desiredUnit,"kilometer") == 0){
				result = temp /39370.079;
			}else if(strcmp(desiredUnit,"meter") == 0){
				result = temp / 39.37;
			}else if(strcmp(desiredUnit,"centimeter") == 0){
				result = temp * 2.54;
			}else if(strcmp(desiredUnit,"millimeter") == 0){
				result = temp * 25.4;
			}else if(strcmp(desiredUnit,"inch") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"foot") == 0){
			if(strcmp(desiredUnit,"kilometer") == 0){
				result = temp / 3280.84;
			}else if(strcmp(desiredUnit,"meter") == 0){
				result = temp / 3.281;
			}else if(strcmp(desiredUnit,"centimeter") == 0){
				result = temp * 30.48;
			}else if(strcmp(desiredUnit,"millimeter") == 0){
				result = temp * 304.8;
			}else if(strcmp(desiredUnit,"foot") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"yard") == 0){
			if(strcmp(desiredUnit,"kilometer") == 0){
				result = temp / 1093.613;
			}else if(strcmp(desiredUnit,"meter") == 0){
				result = temp / 1.094;
			}else if(strcmp(desiredUnit,"centimeter") == 0){
				result = temp * 91.44;
			}else if(strcmp(desiredUnit,"millimeter") == 0){
				result = temp * 914.4;
			}else if(strcmp(desiredUnit,"yard") == 0){
				result = temp;
			}
		}else if(strcmp(originalUnit,"mile") == 0){
			if(strcmp(desiredUnit,"kilometer") == 0){
				result = temp * 1.609;
			}else if(strcmp(desiredUnit,"meter") == 0){
				result = temp * 1609.344;
			}else if(strcmp(desiredUnit,"centimeter") == 0){
				result = temp * 160934.4;
			}else if(strcmp(desiredUnit,"millimeter") == 0){
				result = temp * (1.609 * pow(10,6));
			}else if(strcmp(desiredUnit,"mile") == 0){
				result = temp;
			}
		}
	}
	return result;
}
