#include <stdio.h>
#define MAXLINE 1000

int getline1(char str[], int max);
void reverse(char str[], char rev[], int len);

main()
{
  int len;
  char line[MAXLINE];
  char rev[MAXLINE];
  
  /* Read each line, copying chars to char array */
  while ((len = getline1(line, MAXLINE)) > 0) {
    printf("line: \n");
    printf("%s\n", line);
    /* For each line, call reverse */
    reverse(line, rev, len);

    /* For each reversed line, print it out */
    printf("reverse: \n");
    printf("%s\n", rev);
  }

  return 0;
}

int getline1(char str[], int max)
{
  int c, i;
  c = getchar();

  for (i = 0; i < max - 1 && c != EOF && c != '\n'; ++i) {
    str[i] = c;
    c = getchar();
  }

  if (c == '\n') {
    str[i] = c;
    ++i;
  }

  str[i] = '\0'; 
  return i;
}

void reverse(char str[], char rev[], int len)
{
  int i; 
  int j;
  j = 0;

  for (i = len; i >= 0; --i) {
    if (str[i] != '\0') {
      rev[j] = str[i];
      ++j;
    }
  }

  rev[j] = '\0';
}
