//time comparison of binary and linear search 

#include <stdio.h>
int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2,10,3,45,31,77,56,29};
    int size = 8;
    int target = 31;
    int result = linearSearch(arr, size, target);
    printf("Index = %d", result);
    return 0;
}
