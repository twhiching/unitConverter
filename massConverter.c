#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

double convertMass(char* originalUnit, char* desiredUnit, char* quantityOfUnit){

	double result = 0;
	double temp = atof(quantityOfUnit);
	
	char units = {"metric-ton","kilogram","gram","milligram","microgram","ton","ounce","pound","stone"};
	int massID = {1,1,1,1,1,1,0,0,0,0};
	int powerID = {6,3,1,-3,-6,0,0,0,0};
	int i,idFirst,idSecond,temp;

	idFirst = -1;
	idSecond = -1;
	temp = atof(desiredUnit);
	for(i = 0; i < 9; ++i){
		if(strcmp(originalUnit,units[i]) == 0){
			idFirst = i;
			break;
		}
	}
	for(i = 0; i < 9; ++i){
		if(strcmp(originalUnit,units[i]) == 0){
			idSecond = i;
			break;
		}
	}

	// Converting between metric units
	if(massID[idFirst] == massID[idSecond]){

		//Going from high to low unit of power, else vice-versa
		if(idFirst > 0){
			result = temp * pow(10,massID[idSecond]massID[idSecond]);
		}else{


		}


	}else{




	}
	return result;
}
