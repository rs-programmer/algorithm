#ifndef queue_h
#define queue_h

#include "type.h"

/* 循环队列结构体 */
typedef struct
{
    int capacity; /* 容量 */
    int size; /* 当前元素个数 */
    int front; /* 队列尾 */
    int rear; /* 队列头 */
    int *arr; /* 数组 */
} loop_queue_int_t;

/* 模拟队列 */
loop_queue_int_t* create_loop_queue_int(int capacity);
void free_loop_queue_int(loop_queue_int_t *queue);
bool push_loop_queue_int(loop_queue_int_t *queue, int val);
bool pop_loop_queue_int(loop_queue_int_t *queue, int *val);
bool isEmpty_loop_queue_int(loop_queue_int_t *queue);
bool isFull_loop_queue_int(loop_queue_int_t *queue);
int get_rear_loop_queue_int(loop_queue_int_t *queue);
int get_front_loop_queue_int(loop_queue_int_t *queue);

#endif // !queue_h
