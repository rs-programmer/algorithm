#include "hash.h"

void free_hash_char(hash_char_t *hash)
{
    // 后序遍历，删除所有节点
    if (hash == NULL) {
        return;
    }

    free_hash_char(hash->left);
    free_hash_char(hash->right);

    free(hash->key);
    free(hash);
}

hash_char_t *add_hash_char(hash_char_t *hash, const char *str)
{
    if (hash == NULL) {
        // 没有这个节点，则添加
        char *p_str = (char *)malloc(sizeof(char) * (strlen(str) + 1));
        hash_char_t *node = (hash_char_t *)malloc(sizeof(hash_char_t));
        node->key = p_str;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int k = strcmp((char *)hash->key, (char *)str);

    if (k == 0) {
        // 存在相同节点，直接返回当前节点
        return hash;
    } else if (k > 0) {
        // 左边
        hash->left = add_hash_char(hash->left, str);
        return hash;
    } else {
        // 右边
        hash->right = add_hash_char(hash->right, str);
        return hash;
    }
}

int find_hash_char(const hash_char_t *hash, const char *str)
{
    // 先序查找
    if (hash == NULL) {
        return -1;
    }

    int k = strcmp(hash->key, str);
    if (k == 0) {
        return 0;
    } else if (k > 0) {
        // 左边
        return find_hash_char(hash->left, str);
    } else {
        // 右边
        return find_hash_char(hash->right, str);
    }
}

hash_char_t *del_hash_char(hash_char_t *hash, const char *str)
{
    if (hash == NULL) {
        return NULL;
    }

    int k = strcmp(hash->key, str);
    if (k == 0) {
        // 查找到相同字符，需要删掉
        if (hash->left == NULL && hash->right == NULL) {
            // 叶子节点
            free(hash->key);
            free(hash);
            return NULL;
        } else if (hash->left == NULL) {
            // 仅有右节点
            hash_char_t *tmp = hash->right;
            free(hash->key);
            free(hash);
            return tmp;
        } else if (hash->right == NULL) {
            // 仅有左节点
            hash_char_t *tmp = hash->left;
            free(hash->key);
            free(hash);
            return tmp;
        } else {
            // 左右节点均存在
            hash_char_t *right = hash->right;
            hash_char_t *p = right;
            while (p->left != NULL) {
                p = p->left;
            }
            // 节点转移
            p->left = hash->left;
            free(hash->key);
            free(hash);
            return right;
        }
    } else if (k > 0) {
        // 左边
        hash->left = del_hash_char(hash->left, str);
        return hash;
    } else {
        // 右边
        hash->right = del_hash_char(hash->right, str);
        return hash;
    }
}

/* 整形数据类型 */
void free_hash_int(hash_int_t *hash)
{
    // 后序遍历，删除所有节点
    if (hash == NULL) {
        return;
    }

    free_hash_int(hash->left);
    free_hash_int(hash->right);

    free(hash);
}

hash_int_t *add_hash_int(hash_int_t *hash, int num)
{
    if (hash == NULL) {
        // 没有这个节点，则添加
        hash_int_t *node = (hash_int_t *)malloc(sizeof(hash_int_t));
        node->key = num;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int k = hash->key - num;

    if (k == 0) {
        // 存在相同节点，直接返回当前节点
        return hash;
    } else if (k > 0) {
        // 左边
        hash->left = add_hash_int(hash->left, num);
        return hash;
    } else {
        // 右边
        hash->right = add_hash_int(hash->right, num);
        return hash;
    }
}

int find_hash_int(const hash_int_t *hash, int num)
{
    // 先序查找
    if (hash == NULL) {
        return -1;
    }

    int k = hash->key - num;
    if (k == 0) {
        return 0;
    } else if (k > 0) {
        // 左边
        return find_hash_int(hash->left, num);
    } else {
        // 右边
        return find_hash_int(hash->right, num);
    }
}

hash_int_t *del_hash_int(hash_int_t *hash, int num)
{
    if (hash == NULL) {
        return NULL;
    }

    int k = hash->key - num;
    if (k == 0) {
        // 查找到相同字符，需要删掉
        if (hash->left == NULL && hash->right == NULL) {
            // 叶子节点
            free(hash);
            return NULL;
        } else if (hash->left == NULL) {
            // 仅有右节点
            hash_int_t *tmp = hash->right;
            free(hash);
            return tmp;
        } else if (hash->right == NULL) {
            // 仅有左节点
            hash_int_t *tmp = hash->left;
            free(hash);
            return tmp;
        } else {
            // 左右节点均存在
            hash_int_t *right = hash->right;
            hash_int_t *p = right;
            while (p->left != NULL) {
                p = p->left;
            }
            // 节点转移
            p->left = hash->left;
            free(hash);
            return right;
        }
    } else if (k > 0) {
        // 左边
        hash->left = del_hash_int(hash->left, num);
        return hash;
    } else {
        // 右边
        hash->right = del_hash_int(hash->right, num);
        return hash;
    }
}
