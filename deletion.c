#include <stdio.h>
// 7, 8, 12, 27, 88
// 8, 12,  27, 88

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

void indexDeletion(int arr[], int usedElement, int deletionPosition)
{
    if (deletionPosition >= usedElement || deletionPosition < 0)
    {
        showMessage("No element found in this position.\n");
        return;
    }

    for (int i = deletionPosition; i < usedElement - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    showMessage("Deletion success.\n");
    usedElement--;
    display(arr, usedElement);
    return;
}

int arr[100] = {7, 8, 12, 27, 88};
int arrSize = 100, usedElement = 5, deletionPosition = 0;
int main()
{
    display(arr, usedElement);
    indexDeletion(arr, usedElement, deletionPosition);
}