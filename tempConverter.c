#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Not converting correctly, check why
double convertTemp(char* originalUnit, char* desiredUnit, char* quantityOfUnit){

	double result = 0;
	double temp = atof(quantityOfUnit);

	printf("Im here!\n");
	printf("here is quantitiy of unit: %s\n",quantityOfUnit);
	if(strcmp(originalUnit,"fahrenheit") == 0){
		if(strcmp(desiredUnit,"celsius") == 0){
			result = (temp - 32)*(5/9);
			printf("Result is: %lu\n",result);
		}else{
			result =(temp - 32)*(5/9) + 273.15;
		}
	}else if(strcmp(originalUnit,"celsius") == 0){
		if(strcmp(desiredUnit,"fahrenheit") == 0){
			result =(temp * (9/5)) + 32;
		}else{
			result = temp + 273.15;
		}
	}else{
		if(strcmp(desiredUnit,"celsius") == 0){
			result = temp - 273.15;
		}else{
			result = (temp - 273.15)*(9/5) + 32;
		}
	}
	return result;
}
