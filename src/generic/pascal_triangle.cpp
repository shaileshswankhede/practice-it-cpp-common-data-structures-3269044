#include <vector>
#include <stdio.h>

using namespace std;

#define NUM_ELEM(row_num) ((row_num) * ((row_num) + 1) / 2)

vector<int> getPascalRow(int row)
{
  vector<int> currRow;
  currRow.push_back(1);
  if (row == 0)
    return currRow;

  vector<int> prevRow = getPascalRow(row - 1);
  for (int i = 1; i < prevRow.size(); i++)
  {
    int curr = prevRow[i - 1] + prevRow[i];
    currRow.push_back(curr);
  }
  currRow.push_back(1);

  return currRow;
}

int *getPascalTriangle(int rows)
{
  int *elements = new int[NUM_ELEM(rows)];
  elements[0] = 1;
  int i, j = 0;
  for (i = 1; i < rows; i++)
  {
    int baseIdx = NUM_ELEM(i);
    int prevBaseIdx = NUM_ELEM(i - 1);
    elements[baseIdx + 0] = 1;
    for (j = 1; j < i; j++)
    {
      elements[baseIdx + j] = elements[prevBaseIdx + j - 1] + elements[prevBaseIdx + j];
    }
    elements[baseIdx + j] = 1;
  }
  return elements;
}

int main()
{
  int n = 5;
  vector<int> row = getPascalRow(n);
  printf("printing %th row of pascal triangle\n");
  for (int i = 0; i < row.size(); i++)
  {
    printf("%d ", row[i]);
  }
  printf("\n");

  int *pascalTriangle = getPascalTriangle(n + 1);
  int rowNumber = 1;
  printf("printing complete pascal triangle\n");
  for (int i = 0; i < NUM_ELEM(n + 1); i++)
  {
    printf("%d ", pascalTriangle[i]);

    // newline for last element of row
    if (i == NUM_ELEM(rowNumber) - 1)
    {
      printf("\n");
      rowNumber++;
    }
  }

  return 0;
}