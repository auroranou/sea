#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define BASE 10

// int pow(int base, int exp)
// {
//   int result = 1;
//   for (int i = 0; i < exp; i++)
//   {
//     result *= base;
//   }

//   return result;
// }

int getLength(int x)
{
  return floor(log10(abs(x))) + 1;
}

int max(int x, int y)
{
  if (x >= y)
  {
    return y;
  }
  else
  {
    return x;
  }
}

int karatsuba(int x, int y)
{
  if (x < 10 || y < 10)
  {
    return x * y;
  }

  int m = max(getLength(x), getLength(y));
  int m2 = floor(m / 2);
  int b = pow(BASE, m2);

  int xHigh = floor(x / b);
  int xLow = x % b;

  int yHigh = floor(y / b);
  int yLow = y % b;

  int z0 = karatsuba(xLow, yLow);
  int z1 = karatsuba((xLow + xHigh), (yLow + yHigh));
  int z2 = karatsuba(xHigh, yHigh);

  return (z2 * pow(BASE, 2 * m2)) + ((z1 - z2 - z0) * b) + z0;
}

int main(void)
{
  int x = 12345;
  int y = 54321;

  printf("%d * %d = %d", x, y, karatsuba(x, y));

  return 0;
}