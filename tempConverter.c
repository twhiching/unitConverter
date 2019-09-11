#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

double convertTemp(char* originalUnit, char* desiredUnit, char* quantityOfUnit){

	double result = 0;
	double temp = atof(quantityOfUnit);

	if(strcmp(originalUnit,"fahrenheit") == 0){
		if(strcmp(desiredUnit,"celsius") == 0){
			result = (temp - 32.0)*(5.0/9.0);
		}else{
			result =(temp - 32.0)*(5/9.0) + 273.15;
		}
	}else if(strcmp(originalUnit,"celsius") == 0){
		if(strcmp(desiredUnit,"fahrenheit") == 0){
			result =(temp * (9.0/5.0)) + 32.0;
		}else{
			result = temp + 273.15;
		}
	}else{
		if(strcmp(desiredUnit,"celsius") == 0){
			result = temp - 273.15;
		}else{
			result = (temp - 273.15)*(9.0/5.0) + 32.0;
		}
	}
	return result;
}
