#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defined_types.h"

typedef struct stack {
    node* head;
    unsigned int size;
} stack;

stack* create_stack();
void free_stack(stack* stk); 
void print_stack(stack* stk);

void add_node_to_stack(stack* stk, void* data, int type);
void add_int_node_to_stack(stack* stk, int data);
void add_float_node_to_stack(stack* stk, float data);
void add_string_node_to_stack(stack* stk, char* data);

void pop_element_from_stack(stack* stk);

unsigned int get_size_stack(stack* stk);

#define add_to_stack(list, data) _Generic((data), \
    int: add_int_node_to_stack,                   \
    float: add_float_node_to_stack,               \
    double: add_float_node_to_stack,              \
    char*: add_string_node_to_stack,              \
    const char*: add_string_node_to_stack         \
)(list, data)

#endif // STACK_H