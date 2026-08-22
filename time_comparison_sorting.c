#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------------- BUBBLE SORT ---------------- */

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* ---------------- SELECTION SORT ---------------- */

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

/* ---------------- INSERTION SORT ---------------- */

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

/* ---------------- MERGE SORT ---------------- */

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/* ---------------- QUICK SORT ---------------- */

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ---------------- COPY ARRAY ---------------- */

void copyArray(int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

/* ---------------- MAIN ---------------- */

int main()
{
    /*
       Different input sizes.
       These are deliberately kept reasonable because
       Bubble, Selection and Insertion become slow as n grows.
    */

    int sizes[] = {1000, 2000, 5000, 7000, 10000};

    int numberOfSizes = 5;

    FILE *file = fopen("sorting_times.csv", "w");

    if (file == NULL)
    {
        printf("Could not create CSV file.\n");
        return 1;
    }

    fprintf(file, "Size,Bubble,Selection,Insertion,Merge,Quick\n");

    srand(time(NULL));

    for (int s = 0; s < numberOfSizes; s++)
    {
        int size = sizes[s];

        printf("\nTesting size = %d\n", size);

        int *original = malloc(size * sizeof(int));
        int *arr1 = malloc(size * sizeof(int));
        int *arr2 = malloc(size * sizeof(int));
        int *arr3 = malloc(size * sizeof(int));
        int *arr4 = malloc(size * sizeof(int));
        int *arr5 = malloc(size * sizeof(int));

        if (original == NULL || arr1 == NULL || arr2 == NULL ||
            arr3 == NULL || arr4 == NULL || arr5 == NULL)
        {
            printf("Memory allocation failed.\n");

            free(original);
            free(arr1);
            free(arr2);
            free(arr3);
            free(arr4);
            free(arr5);

            fclose(file);
            return 1;
        }

        /* Generate same random input for all algorithms */

        for (int i = 0; i < size; i++)
        {
            original[i] = rand() % 1000000;
        }

        /* ---------------- BUBBLE ---------------- */

        copyArray(original, arr1, size);

        clock_t start = clock();

        bubbleSort(arr1, size);

        clock_t end = clock();

        double bubbleTime =
            (double)(end - start) / CLOCKS_PER_SEC;

        /* ---------------- SELECTION ---------------- */

        copyArray(original, arr2, size);

        start = clock();

        selectionSort(arr2, size);

        end = clock();

        double selectionTime =
            (double)(end - start) / CLOCKS_PER_SEC;

        /* ---------------- INSERTION ---------------- */

        copyArray(original, arr3, size);

        start = clock();

        insertionSort(arr3, size);

        end = clock();

        double insertionTime =
            (double)(end - start) / CLOCKS_PER_SEC;

        /* ---------------- MERGE ---------------- */

        copyArray(original, arr4, size);

        start = clock();

        mergeSort(arr4, 0, size - 1);

        end = clock();

        double mergeTime =
            (double)(end - start) / CLOCKS_PER_SEC;

        /* ---------------- QUICK ---------------- */

        copyArray(original, arr5, size);

        start = clock();

        quickSort(arr5, 0, size - 1);

        end = clock();

        double quickTime =
            (double)(end - start) / CLOCKS_PER_SEC;

        /* Print results */

        printf("Bubble    : %f seconds\n", bubbleTime);
        printf("Selection : %f seconds\n", selectionTime);
        printf("Insertion : %f seconds\n", insertionTime);
        printf("Merge     : %f seconds\n", mergeTime);
        printf("Quick     : %f seconds\n", quickTime);

        /* Save to CSV */

        fprintf(file, "%d,%f,%f,%f,%f,%f\n",
                size,
                bubbleTime,
                selectionTime,
                insertionTime,
                mergeTime,
                quickTime);

        free(original);
        free(arr1);
        free(arr2);
        free(arr3);
        free(arr4);
        free(arr5);
    }

    fclose(file);

    printf("\nResults saved to sorting_times.csv\n");

    return 0;
}