#include <stdio.h>

#include "hash.h"
#include "tools.h"

int main()
{
    hash_char_t *hash_char = NULL;
    hash_char = add_hash_char(hash_char, "aa");
    hash_char = add_hash_char(hash_char, "bb");
    hash_char = add_hash_char(hash_char, "cc");

    hash_char = del_hash_char(hash_char, "bb");

    free_hash_char(hash_char);

    return 0;
}