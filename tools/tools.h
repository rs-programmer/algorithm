#ifndef tools_h
#define tools_h

#include "type.h"

void toLower(char *p_str, int p_str_len);

/* kmp 算法 回溯法 */
void getNext(char *p_str, int *next, int nextSize);
bool kmp_str(char *src, char *des);

/* 大小比较 */
#define min_int(x, y) (x < y ? x : y)
#define max_int(x, y) (x > y ? x : y)

/* 辗转相除法 */
/**
 * 1. m >= n
 * 2. m % n = q...r
 * 3. m = n, n = r
 * 4. 重复2--3
 */
int gcd(int m, int n);

bool isChar(char c);

bool isLeap(int year);

#endif
