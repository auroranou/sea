#include <stdio.h>
#define TABLENGTH 4

main()
{
  int c, spacecount;
  c = getchar();
  spacecount = 0;

  /* Loop over input, keeping count of whitespaces */
  while (c != EOF) {
    if (c == ' ') {
      ++spacecount;

      if (spacecount == TABLENGTH) {
        putchar('\t');
        spacecount = 0;
      }
    } else {
      putchar(c);
    }

    c = getchar(); 
  }
}
