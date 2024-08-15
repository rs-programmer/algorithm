#include "simple.h"

static void map_char_prosearch(map_char_t *map_char, char **p_str, int *minVal)
{
    if (map_char == NULL) {
        return;
    }

    if (map_char->val > *minVal) {
        // 找到较大值
        *minVal = map_char->val;
        *p_str = map_char->key;
    }

    map_char_prosearch(map_char->left, p_str, minVal);
    map_char_prosearch(map_char->right, p_str, minVal);
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize)
{
    // 字符串分割
    char *p_str = strtok(paragraph, " ");
    map_char_t *map_char = NULL;

    while (p_str != NULL) {
        int p_str_len = strlen(p_str);

        // 内容拷贝到数组中
        char *p_str_arr = (char*)malloc(sizeof(char) * (p_str_len + 1));
        strcpy(p_str_arr, p_str);
        toLower(p_str_arr, p_str_len);

        // 判断是否在banned数组中
        int i = 0;
        for (i = 0; i < bannedSize; i++) {
            if (strcmp(p_str_arr, banned[i]) == 0) {
                break;
            }
        }

        if (i < bannedSize) {
            // 是禁用字符串
            p_str = strtok(NULL, " ");
            continue;
        }

        // 添加到map中
        map_char = add_map_char(map_char, p_str_arr, 1);
        p_str = strtok(NULL, " ");
    }

    // 查询二叉树中 val最大的值
    char *min_p_str = NULL;
    int minVal = 0;
    map_char_prosearch(map_char, &min_p_str, &minVal);

    return min_p_str;
}

int* shortestToChar(char* s, char c, int* returnSize)
{
    int s_len = strlen(s);
    // 创建内存空间
    int *rets = (int*)malloc(sizeof(int) * s_len);
    int *temp = (int*)malloc(sizeof(int) * s_len);

    // 查询字符串中 c 所在的位置
    int c_id = 0;
    for (int i = 0; i < s_len; i++) {
        if (s[i] == c) {
            temp[c_id++] = i;
        }
    }

    // 计算每个字符的最小距离
    for (int i = 0; i < s_len; i++) {
        int min_dest = s_len;

        for (int j = 0; j < c_id; j++) {
            if (abs(i - temp[j]) < min_dest) {
                min_dest = abs(i - temp[j]);
            }
        }

        rets[i] = min_dest;
    }

    *returnSize = s_len;
    return rets;
}

char* toGoatLatin(char* sentence)
{
    
}



