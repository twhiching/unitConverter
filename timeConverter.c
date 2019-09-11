#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"

double convertTime(char* originalUnit, char* desiredUnit, char* quantityOfUnit){

	double result = 0;
	double temp = atof(quantityOfUnit);
	
	if(strcmp(originalUnit,"second") == 0){
	
		if(strcmp(desiredUnit,"second") == 0)
			result = temp;
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp/60.0;
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp/3600.0;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp/86400.0;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp/604800.0;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp/2.628*pow(10,6);
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp/(3.154*pow(10,7));
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp/(3.154*pow(10,8));
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp/(3.154*pow(10,9));
	}else if(strcmp(originalUnit,"minute") == 0){

		if(strcmp(desiredUnit,"second") == 0)
			result = temp*60.0;
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp;
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp/60.0;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp/1440.0;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp/10080.0;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp/43800.048;
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp/525600;
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp/(5.256*pow(10,6));
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp/(5.256*pow(10,7));
	}else if(strcmp(originalUnit,"hour") == 0){

		if(strcmp(desiredUnit,"second") == 0)
			result = temp*3600.0;
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp*60.0;
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp/24.0;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp/168.0;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp/730.001;
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp/8760;
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp/87600;
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp/876000;
	}else if(strcmp(originalUnit,"day") == 0){

		if(strcmp(desiredUnit,"second") == 0)
			result = temp*86400.0;
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp*1440.0;
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp*24.0;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp/7.0;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp/30.417;
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp/365;
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp/3650;
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp/36500;
	}else if(strcmp(originalUnit,"week") == 0){

		if(strcmp(desiredUnit,"second") == 0)
			result = temp*604800.0;
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp*10080.0;
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp*168.0;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp*7.0;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp/4.345;
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp/52.143;
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp/521.429;
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp/5214.286;
	}else if(strcmp(originalUnit,"month") == 0){

		if(strcmp(desiredUnit,"second") == 0)
			result = temp*(2.628*pow(10,6));
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp*43800.048;
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp*730.001;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp*30.417;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp*4.345;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp;
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp/12.0;
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp/120.0;
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp/1199.999;
	}else if(strcmp(originalUnit,"year") == 0){

		if(strcmp(desiredUnit,"second") == 0)
			result = temp*(3.154*pow(10,7));
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp*525600.0;
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp*8760.0;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp*365.0;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp*52.143;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp*12.0;
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp;
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp/10.0;
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp/100;
	}else if(strcmp(originalUnit,"decade") == 0){

		if(strcmp(desiredUnit,"second") == 0)
			result = temp*(3.154*pow(10,8));
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp*526.0*pow(10,6);
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp*87600.0;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp*3650.0;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp*521.429;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp*120.0;
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp*10;
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp;
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp/10;
	}else if(strcmp(originalUnit,"century") == 0){

		if(strcmp(desiredUnit,"second") == 0)
			result = temp*(3.154*pow(10,9));
		else if (strcmp(desiredUnit,"minute") == 0)
			result = temp*526.0*pow(10,7);
		else if (strcmp(desiredUnit,"hour") == 0)
			result = temp*876000.0;
		else if (strcmp(desiredUnit,"day") == 0)
			result = temp*36500.0;
		else if (strcmp(desiredUnit,"week") == 0)
			result = temp*5214.286;
		else if (strcmp(desiredUnit,"month") == 0)
			result = temp*1199.999;
		else if (strcmp(desiredUnit,"year") == 0)
			result = temp*100;
		else if (strcmp(desiredUnit,"decade") == 0)
			result = temp*10;
		else if (strcmp(desiredUnit,"century") == 0)
			result = temp;
	}
	return result;
}
