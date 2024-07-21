#include <stdio.h>
#include <string.h>

int *retArray(void)
{
  static int arr[100];
  memset(arr, 0x1234, 100);
  return &arr[0];
}

int main()
{
  int *ptr = retArray();
  for (int i = 0; i < 100; i++)
  {
    printf("0x%x ", ptr[i]);
  }
  return 0;
}