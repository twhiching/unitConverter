#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"

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
		if(strcmp(originalUnit,"kilogram") == 0){
			if(strcmp(desiredUnit,"ton") == 0){
				result = temp / 907.185;
			}else if(strcmp(desiredUnit,"ounce") == 0){
				result = temp * 35.274;
			}else if(strcmp(desiredUnit,"pound") == 0){
				result = temp * 2.205;
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp / 6.35;
			}
		}else if(strcmp(originalUnit,"gram") == 0){
			if(strcmp(desiredUnit,"ton") == 0){
				result = temp / 907184.74;
			}else if(strcmp(desiredUnit,"ounce") == 0){
				result = temp / 28.35;
			}else if(strcmp(desiredUnit,"pound") == 0){
				result = temp / 453.592;
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp / 6350.293;
			}

		}else if(strcmp(originalUnit,"milligram") == 0){
			if(strcmp(desiredUnit,"ton") == 0){
				result = temp / (9.072 * pow(10,8));
			}else if(strcmp(desiredUnit,"ounce") == 0){
				result = temp / 28349.523;
			}else if(strcmp(desiredUnit,"pound") == 0){
				result = temp / 453592.37;
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp / (6.35 * pow(10,6));
			}

		}else if(strcmp(originalUnit,"microgram") == 0){
			if(strcmp(desiredUnit,"ton") == 0){
				result = temp / (9.072 * pow(10,11));
			}else if(strcmp(desiredUnit,"ounce") == 0){
				result = temp / (2.835 * pow(10,7));
			}else if(strcmp(desiredUnit,"pound") == 0){
				result = temp / (4.536 * pow(10,8));
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp / (6.35 * pow(10,9));
			}

		}else if(strcmp(originalUnit,"metric-ton") == 0){
			if(strcmp(desiredUnit,"ton") == 0){
				result = temp * 1.12;
			}else if(strcmp(desiredUnit,"ounce") == 0){
				result = temp * 35840;
			}else if(strcmp(desiredUnit,"pound") == 0){
				result = temp * 2240;
			}else if(strcmp(desiredUnit,"stone") == 0){
				result = temp * 160;
			}

		}else if(strcmp(originalUnit,"ton") == 0){
			if(strcmp(desiredUnit,"kilogram") == 0){
				result = temp * 907.185;
			}else if(strcmp(desiredUnit,"gram") == 0){
				result = temp * 907184.74;
			}else if(strcmp(desiredUnit,"milligram") == 0){
				result = temp * (9.072 * pow(10,8));
			}else if(strcmp(desiredUnit,"microgram") == 0){
				result = temp * (9.072 * pow(10,11));
			}else if(strcmp(desiredUnit,"metric-ton") == 0){
				result = temp / 1.12;
			}
		}else if(strcmp(originalUnit,"ounce") == 0){
			if(strcmp(desiredUnit,"kilogram") == 0){
				result = temp / 35.274;
			}else if(strcmp(desiredUnit,"gram") == 0){
				result = temp * 28.35;
			}else if(strcmp(desiredUnit,"milligram") == 0){
				result = temp * 28349.523;
			}else if(strcmp(desiredUnit,"microgram") == 0){
				result = temp * (2.835 * pow(10,7));
			}else if(strcmp(desiredUnit,"metric-ton") == 0){
				result = temp / 35840;
			}
		}else if(strcmp(originalUnit,"pound") == 0){
			if(strcmp(desiredUnit,"kilogram") == 0){
				result = temp / 2.205;
			}else if(strcmp(desiredUnit,"gram") == 0){
				result = temp * 453.592;
			}else if(strcmp(desiredUnit,"milligram") == 0){
				result = temp * 453592.37;
			}else if(strcmp(desiredUnit,"microgram") == 0){
				result = temp * (4.536 * pow(10,8));
			}else if(strcmp(desiredUnit,"metric-ton") == 0){
				result = temp / 2240;
			}
		}else if(strcmp(originalUnit,"stone") == 0){
			if(strcmp(desiredUnit,"kilogram") == 0){
				result = temp * 6.35;
			}else if(strcmp(desiredUnit,"gram") == 0){
				result = temp * 6350.293;
			}else if(strcmp(desiredUnit,"milligram") == 0){
				result = temp * (6.35 * pow(10,6));
			}else if(strcmp(desiredUnit,"microgram") == 0){
				result = temp * (6.35 * pow(10,9));
			}else if(strcmp(desiredUnit,"metric-ton") == 0){
				result = temp / 160;
			}
		}
	}
	return result;
}
