#include <stdio.h>

/* 
 Write a program to remove all comments from a C program.
 Don't forget to handle quoted strings and character constants properly.
 C comments do not nest.
*/

/*
 Possible cases:
 - comment at beginning of file
 - inline comment
 - multiline comment 
 - comment characters within quotes
*/

#define IN 1  /* State = inside a comment */
#define OUT 0 /* State = not inside a comment */
#define MAXLEN 10000  /* Maximum length of input */

int c;
int lastc = '\0';
char output[MAXLEN];
int sourcePos = 0;
int destPos = 0;
int state = OUT;

int getCommentState(char lastc, char currc)
{
  if (lastc == '/' && currc == '*') {
    state = IN;
  } else if (lastc == '*' && currc == '/') {
    state = OUT;
  }

  return state;
}

int main() {
  /* Loop over the input */
  while ((c = getchar()) != EOF && destPos < MAXLEN) {
    printf("%d %c %c \n", state, lastc, c);
    
    state = getCommentState(lastc, c);

    if (state == IN) {
      ++sourcePos;
    } else if (state == OUT) {
      if (c != '/' && c != '*') {
        output[destPos++] = c;
        ++sourcePos;
      } else {
        ++sourcePos;
      }
    }

    lastc = c;
  }

  printf("---\n\n");
  printf("%s", output);
  return 0;
}

