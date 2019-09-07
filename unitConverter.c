#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUMBER_OF_STRING 30
#define MAX_STRING_SIZE 50

char units[NUMBER_OF_STRING][MAX_STRING_SIZE] = 
{ "celsius","fahrenheit","kelvin",
  "kilogram","gram","milligram","microgram","ton","kiloton","ounce","pound","stone",
  "kilometer","meter","centimeter","millimeter","inch","foot","yard","mile" ,"league",
  "second","minute","hour","day","week","month","year","decade","century"
};

int isValid(char* unit);

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

	// 0 for Temperature, 1 for Mass, 2 for Distance and 3 for Time
	int id[30] =
	{ 0, 0, 0,
	  1, 1, 1, 1, 1, 1, 1, 1, 1,
	  2, 2, 2, 2, 2, 2, 2, 2, 2,
	  3, 3, 3, 3, 3, 3, 3, 3, 3
	};
	char oldUnit[MAX_STRING_SIZE];
	char newUnit[MAX_STRING_SIZE];
	char amount[MAX_STRING_SIZE];
	int c,i;

	// Main loop that process user input
	while(c != 'n'){

		i = 0;
		// Gather user input and store into appropriate arrays
		printf("Convert from: ");
		while((c = getchar()) != EOF && c != '\n'){

			oldUnit[i] = c;
			++i;
		}
		oldUnit[i] = '\0';
		printf("Is %s a valid unit: %d\n",oldUnit,isValid(oldUnit));
		i = 0;
		printf("\nInto: ");
		while((c = getchar()) != EOF && c != '\n'){

			newUnit[i] = c;
			++i;
		}
		newUnit[i] = '\0';
		i = 0;
		printf("\nBy how many: ");
		while((c = getchar()) != EOF && c != '\n'){

			amount[i] = c;
			++i;
		}
		amount[i] = '\0';
		printf("1: %s\n",oldUnit);
		printf("2: %s\n",newUnit);
		printf("3: %s\n",amount);

		do{
			printf("Do you want to do another conversion? (y/n): ");
			c = getchar();
			c = tolower(c);
			if(c != 'y' && c != 'n'){
				printf("\nInvalid response. Please try again.\n");
				// Consume the newline character
				c = getchar();
			}
		}while(c != 'y' && c != 'n');
		if(c == 'y'){
			// Consume the newline character
			c = getchar();
		}
	}
	return 0;
}

// Returns 1 as true and 0 as false
int isValid(char* unit){

	int size = strlen(unit) - 1;
	int i;

	if(strcmp("celsius",unit) == 0){
		return 1;
	}else{
		if(unit[size] == 's'){
			size = size - 1;
		}
		for(i = 0; i < NUMBER_OF_STRING; ++i){
			if(strncmp(units[i],unit,size) == 0)
				return 1;
		}
	}
	return 0;
}
