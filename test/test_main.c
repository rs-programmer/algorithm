#include "simple.h"
#include "simple_1.h"
#include "tools.h"

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
    int id;

    arr_hash(arr, sizeof(arr)/sizeof(int), &id);
    return 0;
}
