#include <stdio.h>
#include <stdlib.h>

void printArr(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d ", a[i]);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int partitionInd;
    if (low < high)
    {
        partitionInd = partition(arr, low, high);
        quickSort(arr, low, partitionInd - 1);
        quickSort(arr, partitionInd + 1, high);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {45, 4, 35, 3, 2, 18, 38};
    int size = sizeof(arr) / sizeof(int);

    printArr(arr, size);
    quickSort(arr, 0, size - 1);
    printf("\n");
    printArr(arr, size);
    return 0;
}
