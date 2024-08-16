#ifndef tools_type
#define tools_type

// 全局头文件

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum
{
    ERROR = 0,
    SUCCESS = 1
} ret_code_t;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#endif
