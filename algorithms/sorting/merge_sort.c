#include <stdio.h>

void merge(int a[], int l, int mid, int u)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int b[u + 1];
    while (i <= mid && j <= u)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid)
        while (j <= u)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    else
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    for (k = l; k <= u; k++)
    {
        a[k] = b[k];
    }
}
void mergeSort(int a[], int l, int u)
{
    if (l < u)
    {
        int mid = (l + u) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, u);
        merge(a, l, mid, u);
    }
}
int main()
{
    int a[6] = {5, 4, 6, 8, 9, 3};
    int size = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, size - 1);
    printf("sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    }
}