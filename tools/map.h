#ifndef map_h
#define map_h

#include "type.h"

/* ============================================== */
typedef struct map_char
{
    char *key;
    int val;
    struct map_char *left;
    struct map_char *right;
} map_char_t;

void free_map_char(map_char_t *map_char);
map_char_t* add_map_char(map_char_t *map_char, const char *str, int val);
RET_CODE_T find_map_char(const map_char_t *map_char, const char *str, int *val);
map_char_t* del_map_char(map_char_t *map_char, const char *str);


/* ============================================== */
typedef struct map_int
{
    int key;
    int val;
    struct map_int *left;
    struct map_int *right;
} map_int_t;

void free_map_int(map_int_t *map_int);
map_int_t* add_map_int(map_int_t *map_int, const int key, int val);
bool find_map_int(const map_int_t *map_int, const int key, int *val);
map_int_t* del_map_int(map_int_t *map_int, const int key);


#endif
