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

int gcd(int m, int n)
{
    if (n == 0) {
        return m;
    }

    return gcd(n, m % n);
}

bool isChar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isRyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

bool isPrime(int num)
{
    if (num < 2) {
        return false;
    } else if (num == 2) {
        return true;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool search_binary_left(int *arr, int arrSize, int target, int *id)
{
    int left = 0, right = arrSize - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            /* 查找最左边值 */
            if (mid == 0 || arr[mid - 1] != arr[mid]) {
                *id = mid;
                return true;
            } else {
                right = mid - 1;
            }
        }
    }

    return false;
}

bool search_binary_right(int *arr, int arrSize, int target, int *id)
{
    int left = 0, right = arrSize - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            /* 查找最左边值 */
            if (mid == arrSize - 1 || arr[mid + 1] != arr[mid]) {
                *id = mid;
                return true;
            } else {
                left = mid + 1;
            }
        }
    }

    return false;
}

void arr_hash(int *arr, int arrSize, int *newSize)
{
    /* 数组元素去重 */
    int j = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    *newSize = j + 1;
}
