//time comparison of linear search 
#include<stdlib.h>
#include<time.h>
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
int main(){
    int size=10000;
    int arr[10000];
    //yha pe random 10k inputs generate hoga
    srand(time(NULL));
    for(int i=0;i<size;i++){
        arr[i]=rand()%1000000;
    }
    //yhe pe taget search hoga 
    int target=arr[size-1];
     int target = arr[size - 1];

    clock_t start, end;
    double time_taken;

    start = clock();

    int result = linearSearch(arr, size, target);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if (result != -1)
    {
        printf("Element found at index = %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Time taken = %f seconds\n", time_taken);

    return 0;
}