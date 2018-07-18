/* From K&R chapter 5 */

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n)
  {
    /* If there's enough space, add n & return the address of its initial elem */
    allocp += n;
    return allocp - n;
  }
  else
  {
    /* C guarantees that zero is never a valid address for data */
    return 0;
  }
}

void afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
  {
    allocp = p;
  }
}

int main()
{
  return 0;
}