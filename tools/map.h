#ifndef map_h
#define map_h

#include "type.h"

// 二叉搜索树构map
typedef struct map_char
{
    char *key;
    int val;
    struct map_char *left;
    struct map_char *right;
} map_char_t;


// map_char_t* malloc_map_char();

void free_map_char(map_char_t *map_char);
map_char_t* add_map_char(map_char_t *map_char, const char *str, int val);
ret_code_t find_map_char(const map_char_t *map_char, const char *str, int *val);
map_char_t* del_map_char(map_char_t *map_char, const char *str);


#endif
