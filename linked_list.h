#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defined_types.h"

typedef struct linked_list {
    node* head;
    node* tail;
    unsigned int size;
} linked_list;

linked_list* create_linked_list();
void free_linked_list(linked_list* list);
void print_linked_list(linked_list* list);

void add_node_to_list(linked_list* list, void* data, int type);
void add_int_node_to_list(linked_list* list, int data);
void add_float_node_to_list(linked_list* list, float data);
void add_string_node_to_list(linked_list* list, char* data);

void remove_element(linked_list* list, unsigned int index);
void pop_element_from_linked_list(linked_list* list);

unsigned int get_size_linked_list(linked_list* list);

#define append_to_list(list, data) _Generic((data), \
    int: add_int_node_to_list,                   \
    float: add_float_node_to_list,               \
    double: add_float_node_to_list,              \
    char*: add_string_node_to_list,              \
    const char*: add_string_node_to_list         \
)(list, data)

#endif // LINKED_LIST_H
