#include <stdio.h>

int partition(int a[], int l, int r)
{
    int pivot = a[l];
    int start = l;
    int end = r;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }

        while (a[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    a[l] = a[end];
    a[end] = pivot;
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("end: %d", end);
    printf("\n");

    return end;
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        // quickSort(a, p + 1, r);

        // quickSort(a, l, p - 1);
    }
}

int main()
{
    int n = 6;
    int a[6] = {8, 6, 4, 9, 1, 3};
    quickSort(a, 0, 5);
    printf("sorted array: \n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}