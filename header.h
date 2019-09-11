#ifndef HEADER_H_   /* Include guard */
#define HEADER_H_

int isValid(char* unit);
int isSameUnit(char* firstUnit, char* secondUnit);
double convertTemp(char* originalUnit, char* desiredUnit, char* quantityOfUnit);
double convertTime(char* originalUnit, char* desiredUnit, char* quantityOfUnit);
#endif  //HEADER_H_
