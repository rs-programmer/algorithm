#ifndef hash_h
#define hash_h

#include "type.h"

// 二叉搜索树构建哈希表
typedef struct hash_char
{
    char *key;
    struct hash_char *left;
    struct hash_char *right;
} hash_char_t;


// hash_char_t* malloc_hash_char();
void free_hash_char(hash_char_t *hash_char);
hash_char_t* add_hash_char(hash_char_t *hash_char, const char *str);
ret_code_t find_hash_char(const hash_char_t *hash_char, const char *str);
hash_char_t* del_hash_char(hash_char_t *hash_char, const char *str);

#endif
