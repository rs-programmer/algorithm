#include "simple.h"
#include "simple_1.h"

bool comp(int *a, int *b)
{
    return *a > *b;
}

int main()
{
    int arr[] = {5, 2, 3};
    qsort(arr, 3, sizeof(int), comp);

    return 0;
}

