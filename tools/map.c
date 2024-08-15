#include "map.h"

void free_map_char(map_char_t *map_char) {
    // 后序遍历，删除所有节点
    if (map_char == NULL) {
        return;
    }

    free_map_char(map_char->left);
    free_map_char(map_char->right);

    free(map_char->key);
    free(map_char);    
}

map_char_t* add_map_char(map_char_t *map_char, const char *str, int val) {
    if (map_char == NULL) {
        // 没有这个节点，则添加
        char *p_str = (char*)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(p_str, str);

        map_char_t *node = (map_char_t*)malloc(sizeof(map_char_t));
        node->key = p_str;
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int k = strcmp(map_char->key, str);
    if (k == 0) {
        // 存在相同节点，则val相加
        map_char->val += val;
        return map_char;
    } else if (k > 0) {
        // 左边
        map_char->left = add_map_char(map_char->left, str, val);
        return map_char;
    } else {
        // 右边
        map_char->right = add_map_char(map_char->right, str, val);
        return map_char;
    }
}

ret_code_t find_map_char(const map_char_t *map_char, const char *str, int *val) {
    // 先序查找
    if (map_char == NULL) {
        return ERROR;
    }

    int k = strcmp(map_char->key, str);
    if (k == 0)
    {
        *val = map_char->val;
        return SUCCESS;
    } else if (k > 0) {
        // 左边
        return find_map_char(map_char->left, str, val);
    } else {
        // 右边
        return find_map_char(map_char->right, str, val);
    }
}

map_char_t* del_map_char(map_char_t *map_char, const char* str) {
    if (map_char == NULL) {
        return NULL;
    }

    int k = strcmp(map_char->key, str);
    if (k == 0) {
        // 查找到相同字符，需要删掉
        if (map_char->left == NULL && map_char->right == NULL) {
            // 叶子节点
            free(map_char->key);
            free(map_char);
            return NULL;
        } else if (map_char->left == NULL) {
            // 仅有右节点
            map_char_t *tmp = map_char->right;
            free(map_char->key);
            free(map_char);
            return tmp;
        } else if (map_char->right == NULL) {
            // 仅有左节点
            map_char_t *tmp = map_char->left;
            free(map_char->key);
            free(map_char);
            return tmp;
        } else {
            // 左右节点均存在
            map_char_t *right = map_char->right;
            map_char_t *p = right;
            while (p->left != NULL) {
                p = p->left;
            }
            // 节点转移
            p->left = map_char->left;
            free(map_char->key);
            free(map_char);
            return right;
        }
    } else if (k > 0) {
        // 左边
        map_char->left = del_map_char(map_char->left, str);
        return map_char;
    } else {
        // 右边
        map_char->right = del_map_char(map_char->right, str);
        return map_char;
    }
}
