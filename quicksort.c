#include <stdio.h>
void swap(int *val1, int *val2) {
  int temp = *val1;
  *val1 = *val2;
  *val2 = temp; 
}

void quicksort(int arr[], int low, int high)
{
  if (high - low <= 1)
  {
    return;
  }
  int pointer = low;
  int pivot = arr[high];
  
  for(int i = low; i < high; i++) {
    if(arr[i] < pivot) {
      swap(&arr[i], &arr[pointer++]);
    }
  }

  swap(&arr[pointer], &arr[high]);

  quicksort(arr, low, pointer);
  quicksort(arr, pointer + 1, high);
}

int main()
{
  int len = 5;
  int arr[len];
  arr[0] = 4;
  arr[1] = 3;
  arr[2] = 0;
  arr[3] = 2;
  arr[4] = 1;

  quicksort(arr, 0, len - 1);

  for (int i = 0; i < 5; i++)
  {
    printf("%d", arr[i]);
  }

  return 0;
}
