#ifndef stack_h
#define stack_h

#include "type.h"

typedef int ElemType;

typedef struct stack {
    ElemType *arr;
    int top;
    int capacity;
    int size;
} stack_t;

stack_t* create_stack(int capacity);
void free_stack(stack_t *stack);
bool is_empty_stack(stack_t *stack);
bool push_stack(stack_t *stack, ElemType elem);
bool pop_stack(stack_t *stack);
ElemType top_stack(stack_t *stack);

#endif
