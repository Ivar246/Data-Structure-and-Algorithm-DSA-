#include <stdio.h>

// sorting algorithm
void selectionSort(int a[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
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

    selectionSort(a, size);

    // array after sorting
    printf("sorted array: ");
    print(a, size);
    return 0;
}

// time complexity: O(n^2)