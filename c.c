#include <stdio.h>
#define LOWER  0 //lower limit of the tempersture scale
#define UPPER  300 // Upper limit of the temperature scale
#define STEP 20 /*Increment of the temperature scale*/
/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */
int main() {
  int celsius;
  printf("\nTemperature Conversion Table\n");
  printf(" °C\t  °F\n");
  for (celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP) {
    printf("%3d\t %6.2f\n", celsius, celsius/(5.0/9.0) + 32); 
  }
}
