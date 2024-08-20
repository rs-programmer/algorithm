#ifndef tools_h
#define tools_h

#include "type.h"


void toLower(char *p_str, int p_str_len);

/* kmp 算法 回溯法 */
void getNext(char *p_str, int *next, int nextSize);
bool kmp_str(char *src, char *des);

/* 大小比较 */
#define min_int(x, y) (x < y? x : y)
#define max_int(x, y) (x > y? x : y)

#endif
