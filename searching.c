#include <stdio.h>

void display(int arr[], int size)
{
    // Traversal
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void showMessage(char message[100])
{
    printf("%s", message);
}

void showResult(int position)
{
    if (position != -1)
        printf("Element found at %d\n", position);
    else
        printf("Element not found.\n");
}

int linearSearch(int arr[], int size, int elementForSearch)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count++;
        printf("Executed %d times.\n", count);
        if (arr[i] == elementForSearch)
            return i;
    }

    return -1;
}

int binarySearch(int arr[], int size, int elementForSearch)
{
    int low = 0, mid, high = size - 1;
    int count = 0;
    while (low <= high)
    {
        count++;
        printf("Executed %d times.\n", count);
        mid = low + high / 2;
        if (arr[low] == elementForSearch)
        {
            return low;
        }
        if (arr[high] == elementForSearch)
        {
            return high;
        }
        if (arr[mid] == elementForSearch)
        {
            return mid;
        }

        if (elementForSearch < arr[mid])
        {
            high = mid - 1;
            low += 1;
        }
        else
        {
            low = mid + 1;
            high -= 1;
        }
    }
    return -1;
}

int arr[10] = {10, 25, 40, 60, 75, 85, 100, 185, 200, 300};
int elementForSearch = 200, arrSize = 10;

int main()
{
    display(arr, arrSize);
    showMessage("Linear Search\n");
    int linearSearchResult = linearSearch(arr, arrSize, elementForSearch);
    showResult(linearSearchResult);
    showMessage("Binary Search\n");
    int binarySearchResult = binarySearch(arr, arrSize, elementForSearch);
    showResult(binarySearchResult);
    return 0;
}