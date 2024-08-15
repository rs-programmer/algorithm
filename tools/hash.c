#include "hash.h"

void free_hash_char(hash_char_t *hash_char) {
    // 后序遍历，删除所有节点
    if (hash_char == NULL) {
        return;
    }

    free_hash_char(hash_char->left);
    free_hash_char(hash_char->right);

    free(hash_char->key);
    free(hash_char);    
}

hash_char_t* add_hash_char(hash_char_t *hash_char, const char *str) {
    if (hash_char == NULL) {
        // 没有这个节点，则添加
        char *p_str = (char*)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(p_str, str);

        hash_char_t *node = (hash_char_t*)malloc(sizeof(hash_char_t));
        node->key = p_str;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int k = strcmp(hash_char->key, str);
    if (k == 0) {
        // 存在相同节点，直接返回当前节点
        return hash_char;
    } else if (k > 0) {
        // 左边
        hash_char->left = add_hash_char(hash_char->left, str);
        return hash_char;
    } else {
        // 右边
        hash_char->right = add_hash_char(hash_char->right, str);
        return hash_char;
    }
}

ret_code_t find_hash_char(const hash_char_t *hash_char, const char* str) {
    // 先序查找
    if (hash_char == NULL) {
        return ERROR;
    }

    int k = strcmp(hash_char->key, str);
    if (k == 0)
    {
        return SUCCESS;
    } else if (k > 0) {
        // 左边
        return find_hash_char(hash_char->left, str);
    } else {
        // 右边
        return find_hash_char(hash_char->right, str);
    }
}

hash_char_t* del_hash_char(hash_char_t *hash_char, const char* str) {
    if (hash_char == NULL) {
        return NULL;
    }

    int k = strcmp(hash_char->key, str);
    if (k == 0) {
        // 查找到相同字符，需要删掉
        if (hash_char->left == NULL && hash_char->right == NULL) {
            // 叶子节点
            free(hash_char->key);
            free(hash_char);
            return NULL;
        } else if (hash_char->left == NULL) {
            // 仅有右节点
            hash_char_t *tmp = hash_char->right;
            free(hash_char->key);
            free(hash_char);
            return tmp;
        } else if (hash_char->right == NULL) {
            // 仅有左节点
            hash_char_t *tmp = hash_char->left;
            free(hash_char->key);
            free(hash_char);
            return tmp;
        } else {
            // 左右节点均存在
            hash_char_t *right = hash_char->right;
            hash_char_t *p = right;
            while (p->left != NULL) {
                p = p->left;
            }
            // 节点转移
            p->left = hash_char->left;
            free(hash_char->key);
            free(hash_char);
            return right;
        }
    } else if (k > 0) {
        // 左边
        hash_char->left = del_hash_char(hash_char->left, str);
        return hash_char;
    } else {
        // 右边
        hash_char->right = del_hash_char(hash_char->right, str);
        return hash_char;
    }
}
