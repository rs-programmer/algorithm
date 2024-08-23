#include "map.h"
/* =================================================== */
void free_map_char(map_char_t *map) {
    // 后序遍历，删除所有节点
    if (map == NULL) {
        return;
    }

    free_map_char(map->left);
    free_map_char(map->right);

    free(map->key);
    free(map);    
}

map_char_t* add_map_char(map_char_t *map, const char *str, int val) {
    if (map == NULL) {
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

    int k = strcmp(map->key, str);
    if (k == 0) {
        // 存在相同节点，则val相加
        map->val += val;
        return map;
    } else if (k > 0) {
        // 左边
        map->left = add_map_char(map->left, str, val);
        return map;
    } else {
        // 右边
        map->right = add_map_char(map->right, str, val);
        return map;
    }
}

RET_CODE_T find_map_char(const map_char_t *map, const char *str, int *val) {
    // 先序查找
    if (map == NULL) {
        return ERROR;
    }

    int k = strcmp(map->key, str);
    if (k == 0)
    {
        *val = map->val;
        return SUCCESS;
    } else if (k > 0) {
        // 左边
        return find_map_char(map->left, str, val);
    } else {
        // 右边
        return find_map_char(map->right, str, val);
    }
}

map_char_t* del_map_char(map_char_t *map, const char* str) {
    if (map == NULL) {
        return NULL;
    }

    int k = strcmp(map->key, str);
    if (k == 0) {
        // 查找到相同字符，需要删掉
        if (map->left == NULL && map->right == NULL) {
            // 叶子节点
            free(map->key);
            free(map);
            return NULL;
        } else if (map->left == NULL) {
            // 仅有右节点
            map_char_t *tmp = map->right;
            free(map->key);
            free(map);
            return tmp;
        } else if (map->right == NULL) {
            // 仅有左节点
            map_char_t *tmp = map->left;
            free(map->key);
            free(map);
            return tmp;
        } else {
            // 左右节点均存在
            map_char_t *right = map->right;
            map_char_t *p = right;
            while (p->left != NULL) {
                p = p->left;
            }
            // 节点转移
            p->left = map->left;
            free(map->key);
            free(map);
            return right;
        }
    } else if (k > 0) {
        // 左边
        map->left = del_map_char(map->left, str);
        return map;
    } else {
        // 右边
        map->right = del_map_char(map->right, str);
        return map;
    }
}


/* =================================================== */
void free_map_int(map_int_t *map)
{
    // 后序遍历，删除所有节点
    if (map == NULL) {
        return;
    }

    free_map_int(map->left);
    free_map_int(map->right);

    free(map);
}
map_int_t* add_map_int(map_int_t *map, const int key, int val)
{
    if (map == NULL) {
        // 没有这个节点，则添加
        map_int_t *node = (map_int_t*)malloc(sizeof(map_int_t));
        node->key = key;
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int k = map->key - key;
    if (k == 0) {
        // 存在相同节点，则val相加
        map->val += val;
        return map;
    } else if (k > 0) {
        // 左边
        map->left = add_map_int(map->left, key, val);
        return map;
    } else {
        // 右边
        map->right = add_map_int(map->right, key, val);
        return map;
    }
}
bool find_map_int(const map_int_t *map, const int key, int *val)
{
    // 先序查找
    if (map == NULL) {
        return false;
    }

    int k = map->key - key;
    if (k == 0)
    {
        if (val != NULL) {
            *val = map->val;
        }
        return true;
    } else if (k > 0) {
        // 左边
        return find_map_int(map->left, key, val);
    } else {
        // 右边
        return find_map_int(map->right, key, val);
    }
}
map_int_t* del_map_int(map_int_t *map, const int key)
{
    if (map == NULL) {
        return NULL;
    }

    int k = map->key - key;
    if (k == 0) {
        // 查找到相同字符，需要删掉
        if (map->left == NULL && map->right == NULL) {
            // 叶子节点
            free(map);
            return NULL;
        } else if (map->left == NULL) {
            // 仅有右节点
            map_int_t *tmp = map->right;
            free(map);
            return tmp;
        } else if (map->right == NULL) {
            // 仅有左节点
            map_int_t *tmp = map->left;
            free(map);
            return tmp;
        } else {
            // 左右节点均存在
            map_int_t *right = map->right;
            map_int_t *p = right;
            while (p->left != NULL) {
                p = p->left;
            }
            // 节点转移
            p->left = map->left;
            free(map);
            return right;
        }
    } else if (k > 0) {
        // 左边
        map->left = del_map_int(map->left, key);
        return map;
    } else {
        // 右边
        map->right = del_map_int(map->right, key);
        return map;
    }
}

