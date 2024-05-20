#include <iostream>
using namespace std;

int calculateSum(const int arr[], size_t size)
{
    //...TODO: implement
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    const int ints[]{1, -7, 17};
    cout << "The sum of all elements in the array is " << calculateSum(ints, 3) << endl;
}