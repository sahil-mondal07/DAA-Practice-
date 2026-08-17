//time comparison of binary and linear search
#include <stdio.h>
int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2,10,23,45,56};
    int size = 5;
    int target = 23;
    int result = binarySearch(arr, size, target);
    printf("Index = %d", result);
    return 0;
}