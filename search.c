#include <stdio.h>

int linearSearch(int arr[], int size, int ele)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int ele)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2 ;
        if (arr[mid] == ele) return mid;
        if (arr[mid] < ele)
            low = mid + 1;
        else
        {
            high = mid - 1;
        }
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {0, 1, 21, 33, 45, 45, 61, 71, 72, 73};
    int size = sizeof(arr) / sizeof(int);
    int ele=33;
    //scanf("%d", &ele);
    int seaInd = binarySearch(arr, size, ele);
    if (seaInd > -1)
        printf(" the search index of %d is %d \n", ele, seaInd);
    else
        printf("not found \n");
}
