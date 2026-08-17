//selection sort 

#include <stdio.h>
void selectionSort(int data[], int size)
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (data[j] < data[min])
            {
                min = j;
            }
        }
        temp = data[min];
        data[min] = data[i];
        data[i] = temp;
    }
}
int main()
{
    int data[] = {5, 2, 4, 1, 3};
    int size = 5;
    selectionSort(data, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}