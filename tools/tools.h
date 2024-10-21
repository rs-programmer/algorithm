#ifndef tools_h
#define tools_h

#include "type.h"


void toLower(char *p_str, int p_str_len);

/* kmp 算法 回溯法 */
void getNext(char *p_str, int *next, int nextSize);
bool kmp_str(char *src, char *des);

/* 大小比较 */
#define min_int(x, y) ((x) < (y)? (x) : (y))
#define max_int(x, y) ((x) > (y)? (x) : (y))

/* 辗转相除法 */
/**
 * 1. m >= n
 * 2. m % n = q...r
 * 3. m = n, n = r
 * 4. 重复2--3
 */
int gcd(int m, int n);

bool isChar(char c);

/**
 * @brief 判别是否是闰年
 * 
 * @param year 年份
 * @return true 是
 * @return false 否
 */
bool isRyear(int year);

/**
 * @brief 判断是否为质数
 * 
 * @param num 
 * @return true 
 * @return false 
 */
bool isPrime(int num);

bool search_binary_left(int *arr, int arrSize, int target, int *id);
bool search_binary_right(int *arr, int arrSize, int target, int *id);
void arr_hash(int *arr, int arrSize, int *newSize);
#endif
