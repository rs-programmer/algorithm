#ifndef tools_type
#define tools_type

// 全局头文件

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum {
    ERROR = 0,
    SUCCESS = 1
} RET_CODE_T;

// 枚举
typedef enum {
    PARAM_CHAR = 0,
    PARAM_INT,
} TYPE_T;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

#endif
