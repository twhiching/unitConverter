#include <stdio.h>
#include <ctype.h>

#define NUMBER_OF_STRING 42
#define MAX_STRING_SIZE 50

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

	char* units[NUMBER_OF_STRING][MAX_STRING_SIZE] = 
	{ "Celsius","Fahrenheit","Kelvin",
	  "Kilogram","Gram","Milligram","Microgram","Ton","Kiloton","Ounce","Pound","Stone",
	  "Kilometer","Meter","Centimeter","Millimeter","Inch","Foot","Yard","Mile" ,"League",
	  "Second","Minute","Hour","Day","Week","Month","Year","Decade","Century"
	};
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

	i = 0;
	//Main loop that process user input
	while(c != 'y'){

		//Gather user input and store into appropriate arrays
		printf("Convert from: ");
		while((c = getchar()) != EOF || c != '\n'){

			oldUnit[i] = c;
			++i;
		}
		oldUnit[i] = '\0';
		i = 0;
		printf("\nInto: ");
		while((c = getchar()) != EOF || c != '\n'){

			newUnit[i] = c;
			++i;
		}
		newUnit[i] = '\0';
		i = 0;
		printf("\nBy how many: ");
		while((c = getchar()) != EOF || c != '\n'){

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
			if(c != 'y' || c != 'n')
				printf("Invalid response. Please try again.");

		}while(c != 'y' | c != 'n');
	}
	return 0;
}
