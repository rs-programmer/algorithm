#ifndef hash_h
#define hash_h

#include "type.h"

/* 字符串 哈希表 */
typedef struct hash_char
{
    char *key;
    struct hash_char *left;
    struct hash_char *right;
} hash_char_t;

void free_hash_char(hash_char_t *hash);
hash_char_t* add_hash_char(hash_char_t *hash, const char *str);
int find_hash_char(const hash_char_t *hash, const char *str);
hash_char_t* del_hash_char(hash_char_t *hash, const char *str);

/* 整形 哈希表 */
typedef struct hash_int
{
    int key;
    struct hash_int *left;
    struct hash_int *right;
} hash_int_t;

void free_hash_int(hash_int_t *hash);
hash_int_t* add_hash_int(hash_int_t *hash, int num);
int find_hash_int(const hash_int_t *hash, int num);
hash_int_t* del_hash_int(hash_int_t *hash, int num);



#endif
