#ifndef HASH_SET_H
#define HASH_SET_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "defined_types.h"

// 131 because it is a prime number
#define DEFAULT_CAPACITY 131

/*
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
*/

typedef struct hash_set {
    node* entries[DEFAULT_CAPACITY];
} hash_set;

hash_set* create_hash_set();
void free_hash_set(hash_set* set);

int get_int_hash_index(int value);
int get_float_hash_index(float value);
int get_string_hash_index(char* value);


void add_hash_entry(hash_set* set, void* data, int type, int index);
void add_int_hash_entry(hash_set* set, int value);
void add_float_hash_entry(hash_set* set, float value);
void add_string_hash_entry(hash_set* set, char* value);

void print_hash_set(hash_set* set);

int values_equal(void* d1, void* d2, int type);

int is_data_in_hash_set(hash_set* set, void* data, int type, int index);
int is_int_in_hash_set(hash_set* set, int value);
int is_float_in_hash_set(hash_set* set, float value);
int is_string_in_hash_set(hash_set* set, char* value);

void remove_hash_entry(hash_set* set, void* data, int type, int index);
void remove_int_from_set(hash_set* set, int value);
void remove_float_from_set(hash_set* set, float value);
void remove_string_from_set(hash_set* set, char* value);

#define add_to_hash_set(set, data) _Generic((data), \
    int: add_int_hash_entry,                   \
    float: add_float_hash_entry,               \
    double: add_float_hash_entry,              \
    char*: add_string_hash_entry,              \
    const char*: add_string_hash_entry         \
)(set, data)

#define is_in_hash_set(set, data) _Generic((data), \
    int: is_int_in_hash_set,                   \
    float: is_float_in_hash_set,               \
    double: is_float_in_hash_set,              \
    char*: is_string_in_hash_set,              \
    const char*: is_string_in_hash_set         \
)(set, data)

#define remove_entry_from_hash(set, data) _Generic((data), \
    int: remove_int_from_set,                   \
    float: remove_float_from_set,               \
    double: remove_float_from_set,              \
    char*: remove_string_from_set,              \
    const char*: remove_string_from_set         \
)(set, data)

#endif // HASH_SET_H
