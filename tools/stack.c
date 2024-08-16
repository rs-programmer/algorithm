#include "stack.h"

stack_t* create_stack(int capacity)
{
    stack_t *stack = (stack_t*)malloc(sizeof(stack_t));
    stack->arr = (ElemType*)malloc(sizeof(ElemType) * capacity);
    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

void free_stack(stack_t *stack)
{
    if (stack == NULL)
    {
        return;
    }
    
    free(stack->arr);
    free(stack);
}

bool is_empty_stack(stack_t *stack)
{
    return stack->top == -1;
}

bool push_stack(stack_t *stack, ElemType elem)
{
    if (stack->top == stack->capacity - 1) {
        return false;
    }

    stack->top += 1;
    stack->arr[stack->top] = elem;
    return true;
}

bool pop_stack(stack_t *stack)
{
    if (stack->top == -1) {
        return false;
    }

    stack->top -= 1;
    return true;
}

ElemType top_stack(stack_t *stack)
{
    return stack->arr[stack->top];
}