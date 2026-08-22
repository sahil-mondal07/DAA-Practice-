//time comparison of binary search
#include <stdio.h>
#include <time.h>

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
    int arr[] = {2, 10, 23, 45, 56};
    int size = 5;
    int target = 23;

    clock_t start, end;
    double time_taken;

    start = clock();

    int result = binarySearch(arr, size, target);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Index = %d\n", result);
    printf("Time taken = %f seconds\n", time_taken);

    return 0;
}
