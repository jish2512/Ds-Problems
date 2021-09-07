#include <stdio.h>
void printArr(int arr[])
{
    for (int j = 0; j < 8; j++)
    {
        printf("%d ", arr[j]);
    }
}

void bubbleSort(int arr[])
{
        int exc = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int k = i + 1; k < 8; k++)
        {
            int temp = 0;
            if (arr[i] > arr[k])
            {
                temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
                exc++;
            }
        }
        if (exc == 0)
            break;
    }
    printf("Counter %d \n",exc);
    printArr(arr);
}

void insertionSort(int arr[], int size)
{
    int key = 0;
    for (int i = 1; i <= size - 1; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printArr(arr);
}
void selectionSort(int a[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        int indOfmin = i;
        for (int j = i + 1; j < s; j++)
        {
            if (a[j] > a[indOfmin])
                indOfmin = j;
        }
        int temp = 0;
        temp = a[i];
        a[i] = a[indOfmin];
        a[indOfmin] = temp;

        /* code */
    }
    printArr(a);
}
void ReverseArr(int arr[], int size)
{
    int temp = 0;
    bubbleSort(arr);
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printArr(arr);
}
int main(int argc, char const *argv[])
{
    int arr[8] = {2,2,3,4,5,6,7,8};
    int size = sizeof(arr) / sizeof(int);
    bubbleSort(arr);
    //ReverseArr(arr, size);
    //insertionSort(arr, size);
    //selectionSort(arr, size);
    return 0;
}
