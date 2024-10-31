#include "link.h"

link_t *create_link()
{
    link_t *link = (link_t *)malloc(sizeof(link_t));
    link->head = NULL;
    link->size = 0;
    return link;
}

void free_link(link_t *link)
{
    if (link == NULL) {
        return;
    }

    /* 先删除节点 */
    link_node_t *node = link->head;
    link_node_t *p = NULL;
    while (node != NULL) {
        p = node->next;
        free(node);
        node = p;
    }

    free(link);
}

bool is_empty_link(link_t *link)
{
    return link->size == 0;
}

void append_link(link_t *link, ElemType val)
{
    /* 尾部添加节点 */
    link_node_t *node = link->head;
    if (node == NULL) {
        link_node_t *tmp = (link_node_t *)malloc(sizeof(link_node_t));
        tmp->next = NULL;
        tmp->val = val;
        link->head = tmp;
        link->size += 1;
        return;
    }

    /* 找到尾节点 */
    while (node->next != NULL) {
        node = node->next;
    }

    /* 添加节点 */
    link_node_t *tmp = (link_node_t *)malloc(sizeof(link_node_t));
    tmp->next = NULL;
    tmp->val = val;
    node->next = tmp;
    link->size += 1;
}

void head_link(link_t *link, ElemType val)
{
    /* 头插法 */
    link_node_t *tmp = (link_node_t *)malloc(sizeof(link_node_t));
    tmp->val = val;
    tmp->next = link->head;
    link->head = tmp;
    link->size += 1;
}

void insert_link(link_t *link, ElemType after, ElemType val)
{
    /* after 节点之后，插入 val 节点 */
    link_node_t *node = link->head;
    while (node != NULL && node->val != after) {
        node = node->next;
    }

    if (node == NULL) {
        /* 没有找到指定节点 */
        return;
    }

    link_node_t *tmp = (link_node_t *)malloc(sizeof(link_node_t));
    tmp->val = val;
    tmp->next = node->next;
    node->next = tmp;
    link->size += 1;
}

void del_item_link(link_t *link, ElemType val)
{
    /* 查找到 val */
    link_node_t *node = link->head;
    link_node_t *p = NULL;

    while (node != NULL && node->val != val) {
        p = node;
        node = node->next;
    }

    if (node == NULL) {
        /* 没有这个节点 */
        return;
    }

    if (p == NULL) {
        /* 删除头节点 */
        link->head = node->next;
        free(node);
        link->size -= 1;
        return;
    }

    /* 中间节点 */
    p->next = node->next;
    free(node);
    link->size -= 1;
}
