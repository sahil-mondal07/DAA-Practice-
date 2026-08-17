//insertion sort 
#include <stdio.h>
void insertionSort(int data[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = data[i];
        j = i;
        while (j >= 1 && data[j - 1] > key)
        {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = key;
    }
}

int main()
{
    int data[] = {5, 2, 4, 1, 3};
    int size = 5;
    insertionSort(data, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}