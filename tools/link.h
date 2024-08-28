#ifndef link_h
#define link_h

#include "type.h"

/* 统一链表格式 */
typedef int ElemType;

typedef struct link_node
{
    ElemType val;
    struct link_node *next;
} link_node_t;

typedef struct link
{
    int size;
    link_node_t *head;
} link_t;

link_t* create_link();
void free_link(link_t *link);
bool is_empty_link(link_t *link);
void append_link(link_t *link, ElemType val);
void head_link(link_t *link, ElemType val);
void insert_link(link_t *link, ElemType after, ElemType val);
void del_item_link(link_t *link, ElemType val);

#endif
