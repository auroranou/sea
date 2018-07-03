#include <stdio.h>

main()
{
  int blanks, tabs, newlines;
  blanks = tabs = newlines = 0;

  int c = getchar();
  while (c != EOF) {
    if (c == ' ')
      ++blanks;
    else if (c == '\t')
      ++tabs;
    else if (c == '\n')
      ++newlines;

    c = getchar();
  }

  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("New lines: %d\n", newlines);
}
