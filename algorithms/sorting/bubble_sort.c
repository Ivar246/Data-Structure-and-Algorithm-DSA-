#include <stdio.h>

// printing
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void bubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
}

int main()
{
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};

    // original array
    printf("Unsorted array:");
    print(a, n);

    bubbleSort(a, n);

    // array after sorting
    printf("sorted array:");
    print(a, n);

    return 0;
}

/* Time complexity:O(n^2)
 */