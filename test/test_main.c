#include <stdio.h>

#include "hash.h"
#include "tools.h"

int main()
{

    char *src = "aabbccdd";
    char *des = "bccc";

    printf("kmp_str: %d\n", kmp_str(src, des));

    return 0;
}