#include <stdio.h>

int main()
{
    int a = 5;
    int *p = &a;
    int **q = &p;
    printf("%d\n", p);
    printf("%d\n", &a);
    printf("%d\n", &p);
    printf("%d\n", q);
    printf("%d", *q);
}
