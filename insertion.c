#include <stdio.h>
// 7, 8, 12, 27, 88
// 7, 8, 12, 86, 27, 88

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

void indexInsertion(int arr[], int usedElement, int arrSize, int elementForInsert, int insertionPosition)
{
    if (insertionPosition < 0)
    {
        showMessage("Can't insert in negative.\n");
        return;
    }

    if (insertionPosition >= arrSize)
    {
        showMessage("Insertion failed.\n");
        showMessage("Insertion position is bigger than size of an array.\n");
        return;
    }

    if (insertionPosition > usedElement)
    {
        // This will return {7, 8, 12, 27, 88, 0, 0, 0, 0, 0, 86} For insertionPosition = 9;
        int count;
        for (int i = usedElement; i < insertionPosition + 1; i++)
        {
            count++;
            if (i == insertionPosition)
            {
                arr[insertionPosition] = elementForInsert;
            }
        }
        showMessage("Insertion success.\n");
        usedElement += count;
        display(arr, usedElement);
        return;

        // This will return {7, 8, 12, 27, 88, 86}      For insertionPosition=9
        // arr[usedElement] = elementForInsert;
        // showMessage("Insertion success.\n");
        // usedElement++;
        // display(arr, usedElement);
        // return;
    }

    for (int i = usedElement - 1; i >= insertionPosition; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[insertionPosition] = elementForInsert;
    showMessage("Insertion success.\n");
    usedElement++;
    display(arr, usedElement);
}

int arr[100] = {7, 8, 12, 27, 88, 86};
int arrSize = 100, usedElement = 5, elementForInsert = 86, insertionPosition = 10;

int main()
{
    display(arr, usedElement);
    indexInsertion(arr, usedElement, arrSize, elementForInsert, insertionPosition);
}