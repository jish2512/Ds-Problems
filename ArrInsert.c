#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
}
int insertElement(int arr[], int size, int element, int index, int capacity)
{
    if (size >= capacity)
        return 0;
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

void deleteElement(int arr[], int size, int index, int capacity)
{
    if (index >= capacity)
        printf("%s","out of bound");
    for (int i = index; i <= size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100] = {1, 2, 34, 5};
    int size = 4, element = 78, index = 2;
    display(arr, size);
    printf("\n");
    insertElement(arr, size, element, index, 100);
    size++;
    display(arr, size);
    printf("\n");
    deleteElement(arr,size,index,100);
    size--;
    display(arr,size);
    return 0;
}