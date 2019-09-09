#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

#define NUMBER_OF_STRING 30
#define MAX_STRING_SIZE 50

char units[NUMBER_OF_STRING][MAX_STRING_SIZE] = 
{ "celsius","fahrenheit","kelvin",
  "kilogram","gram","milligram","microgram","ton","kiloton","ounce","pound","stone",
  "kilometer","meter","centimeter","millimeter","inch","foot","yard","mile" ,"league",
  "second","minute","hour","day","week","month","year","decade","century"
};

// 0 for Temperature, 1 for Mass, 2 for Distance and 3 for Time
int id[30] =
{ 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3, 3
};

int main(int argc, char *argv[]){

	char* help = "------------------------------------------------------------------------------\n"
		     "|   Temp            Mass            Volume            Distance        Time   |\n"
		     "|----------------------------------------------------------------------------|\n"
                     "| Celsius       Microgram      Cubic Millimeter       Milimeter       Second |\n"
		     "| Fahrenheit    Milligram      Cubic Centimeter       Centimeter      Minute |\n"
		     "| Kelvin        Gram           Cubic Decimeter        Meter           Hour   |\n"
		     "|               Kilogram       Cubic Meter            Kilometer       Day    |\n"
		     "|               Ton            Cubic Decameter        Inch            Week   |\n"
		     "|               Kiloton        Cubic Hectometer       Foot            Month  |\n"
		     "|               Ounce          Cubic Kilometer        Yard            Year   |\n"
		     "|               Pound          Ounce                  Mile            Decade |\n"
		     "|               Stone          Cup                    League          Century|\n"
		     "|                              Pint                                          |\n"
		     "|                              Quart                                         |\n"
		     "|                              Gallon                                        |\n"
		     "|                                                                            |\n"
		     " -----------------------------------------------------------------------------\n";

	char oldUnit[MAX_STRING_SIZE];
	char newUnit[MAX_STRING_SIZE];
	char amount[MAX_STRING_SIZE];
	char programResponse[3][MAX_STRING_SIZE] = {
		"Convert from: ", "Into: ", "By how many: "
	};
	char userResponse[3][MAX_STRING_SIZE];

	int c,i,j,k;
	int flag;
	int unitID;
	double result;
	// Main loop that process user input
	while(c != 'n'){
		for(i = 0; i < 3; ++i){
			flag = 0;
			do{
				j = 0;
				printf("%s",programResponse[i]);
				//Gather all input from the stdin
				while((c = getchar()) != EOF && c != '\n'){
					userResponse[i][j] = c;
					++j;
				}
				userResponse[i][j] = '\0';
				// Convert all leters to lowercase
				for(k = 0; k < j; ++k){
					userResponse[i][k] = tolower(userResponse[i][k]);
				}
				if(strcmp(userResponse[i],"quit") == 0)
					return 0;
				else if(strcmp(userResponse[i],"help") == 0)
					printf("%s",help);
				else if(!isValid(userResponse[i]) && i < 2){
					printf("\"%s\" is not a valid response. Please type in a valid response.\n",userResponse[i]);
					printf("For a list of valid options type \"help\". To exit the program type \"quit\"\n");
				}else if(isValid(userResponse[i])&& i == 1){ // Check to see if user is asking of a conversion of differnt units
					unitID = isSameUnit(userResponse[i-1],userResponse[i]);
					if(unitID < 0){
						printf("Can not convert \"%s\" into \"%s\". Please type in a valid response.\n",userResponse[i-1],userResponse[i]);
						printf("For a list of valid options type \"help\". To exit the program type \"quit\"\n");
					}else
						flag = 1;
				}else if(i == 2 && atof(userResponse[i]) == 0){
					printf("Please enter a valid number\n");
				}else
					flag = 1;
			}while(!flag);
		}

		printf("1: %s\n",userResponse[0]);
		printf("2: %s\n",userResponse[1]);
		printf("3: %s\n",userResponse[2]);
		printf("Unit id is: %d\n",unitID);
		switch (unitID){
	    		case 0: // Converison is of type Temperature
				printf("gonna call convert temp\n");
				result = convertTemp(userResponse[0],userResponse[1],userResponse[2]);
				break;
    			case 1: // Conversion is of type Mass
				//result = convertMass(userResponse[0],userResponse[1],userResponse[2]);
				break;
    			case 2: // Conversion is of type Distance
				//result = convertDistance(userResponse[0],userResponse[1],userResponse[2]);
				break;
    			case 3: // Conversion is of type Time
				//result = convertTime(userResponse[0],userResponse[1],userResponse[2]);
				break;
		}

		printf("Result: %.2lf %s's\n",result,userResponse[1]);
		do{
			printf("Do you want to do another conversion? (y/n): ");
			c = getchar();
			c = tolower(c);
			if(c != 'y' && c != 'n'){
				printf("Invalid response. Please try again.\n");
				// Consume all input in the stdin buffer
				while((c = getchar()) != EOF && c != '\n'){
					;
				}
			}
		}while(c != 'y' && c != 'n');
		if(c == 'y'){
			// Consume the newline character
			c = getchar();
		}
	}
	return 0;
}

// This helper function determines wether the input the user entered is a valid
// Returns 1 as true and 0 as false
int isValid(char* unit){

	int size = strlen(unit) - 1;
	int i;
	char temp[MAX_STRING_SIZE];

   	memset(temp, '\0', sizeof(temp));
	if(strcmp("celsius",unit) == 0){
		return 1;
	}else{
		if(unit[size] == 's'){
			size = size - 1;
		}
		strncpy(temp,unit,size+1);
		for(i = 0; i < NUMBER_OF_STRING; ++i){
			if(strcmp(units[i],temp) == 0)
				return 1;
		}
	}
	return 0;
}

// This helper function determines wether the passed in units are compatiable for a conversion
// Returns 1 as true and -1 as false
int isSameUnit(char* firstUnit, char* secondUnit){

	int firstUnitId, secondUnitId,i;

	for(i = 0; i < NUMBER_OF_STRING;++i){
		if(strcmp(firstUnit,units[i]) == 0){
			firstUnitId = id[i];
			break;
		}
	}
	for(i = 0; i < NUMBER_OF_STRING;++i){
		if(strcmp(secondUnit,units[i]) == 0){
			secondUnitId = id[i];
			break;
		}
	}
	if(firstUnitId == secondUnitId)
		return id[i];
	else
		return -1;
}
