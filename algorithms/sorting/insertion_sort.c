#include <stdio.h>

// sorting algorithm
void insertionSort(int a[], int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        int temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[] = {4, 1, 5, 3, 7, 6};
    int size = sizeof(a) / sizeof(a[0]);

    // array before sorting
    printf("Unsorted array: ");
    print(a, size);
    printf("\n");

    insertionSort(a, size);

    // array after sorting
    printf("sorted array: ");
    print(a, size);
    return 0;
}