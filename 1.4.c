#include <stdio.h>

main()
{
  float celsius, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = 0;
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%3.2f %3.2f\n", celsius, fahr);
    celsius = celsius + step; 
  }
}
