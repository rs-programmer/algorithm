#include <stdio.h>

#include "hash.h"
#include "tools.h"

int main()
{

    char *p_str = "aaa";
    char p_arr[] = {'a','a', 'a', '\0'};

    printf("k: %d\n", strcmp(p_str, p_arr));

    return 0;
}