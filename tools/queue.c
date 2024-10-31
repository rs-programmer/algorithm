#include "queue.h"

loop_queue_int_t *create_loop_queue_int(int capacity)
{
    loop_queue_int_t *queue = (loop_queue_int_t *)malloc(sizeof(loop_queue_int_t));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
    queue->arr = (int *)malloc(sizeof(int) * capacity);

    return queue;
}

void free_loop_queue_int(loop_queue_int_t *queue)
{
    if (queue == NULL) {
        return;
    }

    free(queue->arr);
    free(queue);
}

bool push_loop_queue_int(loop_queue_int_t *queue, int val)
{
    if (is_full_loop_queue_int(queue)) {
        return false;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = val;
    queue->size += 1;
    return true;
}

bool pop_loop_queue_int(loop_queue_int_t *queue, int *val)
{
    if (is_empty_loop_queue_int(queue)) {
        return false;
    }

    queue->front = (queue->front + 1) % queue->capacity;
    if (val != NULL) {
        *val = queue->arr[queue->front];
    }

    queue->size -= 1;
    return true;
}

bool is_empty_loop_queue_int(loop_queue_int_t *queue)
{
    // return queue->front == queue->rear;
    return queue->size == 0;
}

bool is_full_loop_queue_int(loop_queue_int_t *queue)
{
    // return (queue->rear + 1) % queue->capacity == queue->front;
    return queue->size == queue->capacity - 1;
}

int get_rear_loop_queue_int(loop_queue_int_t *queue)
{
    /* 返回头部数据 */
    return queue->arr[queue->rear];
}
int get_front_loop_queue_int(loop_queue_int_t *queue)
{
    /* 返回尾部数据 */
    return queue->arr[(queue->front + 1) % queue->capacity];
}
