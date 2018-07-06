#include <stdio.h>
#define MAXLINE 1000

int getline1(char s[], int max);
void copy(char to[], char from[]);

main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];  

  max = 0;

  while ((len = getline1(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  
  if (max > 0) {
    printf("%d", max);
    printf("%s", longest);
  }

  return 0;
}

int getline1(char s[], int max)
{
  int c, i;

  for (i = 0; i < max - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;
  i = 0;

  while((to[i] = from[i]) != '\0') {
    ++i;
  }
}
