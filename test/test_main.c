#include "simple.h"
#include "hash.h"

#include "sort.h"

#define Transf(T, n) ((T*)((char*)n - (char*)&(((T*)0)->n)))

int main()
{
    char *str = "IDID";
    int size = 0;
    diStringMatch(str, &size);
    return 0;
}

