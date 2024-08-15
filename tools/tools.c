#include "tools.h"

void toLower(char *p_str, int p_str_len)
{
    if (p_str == NULL) return;
    for (int i = 0; i < p_str_len; i++) {
        p_str[i] = tolower(p_str[i]);
    }
}

void getNext(char *p_str, int *next, int nextSize)
{
    int i = 1, j = 0;
    next[0] = 0;

    for (i = 1; i < nextSize; i++) {
        while (j > 0 && p_str[i] != p_str[j]) {
            // 出现了不相等的情况
            j = next[j - 1];
        }

        if (p_str[i] == p_str[j]) {
            j++;
        }

        next[i] = j; // 下标 j 的前缀内容（不包括j）与后缀内容（包括i）相同
    }
}

bool kmp_str(char *src, char *des)
{
    int src_len = strlen(src);
    int des_len = strlen(des);

    // 先计算 des 的 next
    int *next = (int*)malloc(sizeof(int) * des_len);
    getNext(des, next, des_len);

    int src_id = 0, des_id = 0;
    while (src_id < src_len) {
        if (src[src_id] == des[des_id]) {
            src_id++;
            des_id++;
        } else {
            // des_id 回退一下
            if (des_id > 0) {
                des_id = next[des_id - 1];
            } else {
                src_id++; // 首个字符就不匹配
            }
        }

        // 判断是否存在
        if (des_id >= des_len) {
            return true;
        }
    }

    return false;
}
