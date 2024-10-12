#include <stdio.h>
#include <string.h>
#include <iostream>

typedef struct
{
  char a;  // 1 byte
  char *c; // pointer (size depends on the machine: 4 bytes on 32-bit, 8 bytes on 64-bit)
  int b;   // 4 byte
} myStruct;

struct Example2
{
  char a;   // 1 byte
  int b;    // 4 bytes
  double c; // 8 bytes
};

int *retArray(void)
{
  static int arr[100];
  memset(arr, 0x1234, 100);
  return &arr[0];
}

int main()
{
  /*
  int *ptr = retArray();
  for (int i = 0; i < 100; i++)
  {
    printf("0x%x ", ptr[i]);
  }
  */
  printf("sizeof myStruct %d\n", sizeof(myStruct));
  printf("sizeof Example2 %d\n", sizeof(Example2));

  return 0;
}