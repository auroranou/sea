#include <stdio.h>

main()
{
  int c, lastchar;
  c = getchar();
  
  while (c != EOF) {
    if ((c == ' ' || c == '\n' || c == '\t') && (lastchar == ' ' || lastchar == '\n' || lastchar == '\t')) {
      ;
    } else {
      putchar(c);
    }

    lastchar = c;
    c = getchar();
  }  
}


