#include <stdio.h>

main()
{
  int currentwordlength = 0;
  int wordlengths[12];
  int c = getchar();

  for (int i = 0; i < 12; ++i) {
    wordlengths[i] = 0;
  }

  /* Loop over input, keeping count of word length until whitespace is hit */
  while (c != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      wordlengths[currentwordlength] = wordlengths[currentwordlength] + 1;
      currentwordlength = 0;
    } else {
      ++currentwordlength;
    }
    
    c = getchar();
  }

  /* After evaluating input, loop through array of counts and print each one out */
  for (int i = 0; i < 12; ++i) {
    printf("%d", i);
    putchar(' ');

    int count = wordlengths[i];

    for (c = 0; c < count; ++c) {
      putchar('x');
    }

    putchar('\n');
  }
}
