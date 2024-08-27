#ifndef link_h
#define link_h

#include "type.h"

/* 统一链表格式 */
typedef int ElemType;

typedef struct node
{
    ElemType val;
    struct node *next;
} node_t;

typedef struct link
{
    int size;
    node_t *head;
} link_t;

#endif
