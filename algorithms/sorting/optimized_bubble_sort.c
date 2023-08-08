#include <stdio.h>

// optimized bubble sort
void bubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int flag = 0; // for tracking swap
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                flag = 1;
            }

        if (flag == 0) // if no swap terminate
            break;
    }
}
// printing
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int n = 5;
    int a[5] = {5, 8, 3, 6, 4};

    // original array
    printf("Unsorted array: ");
    print(a, n);
    printf("\n");

    bubble_sort(a, n);

    // array after sorting
    printf("sorted array: ");
    print(a, n);
    printf("\n");

    return 0;
}

/* Time complexity:
        best case: O(n)
        worst case: O(n^2)
*/