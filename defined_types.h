#ifndef DEFINED_TYPES_H
#define DEFINED_TYPES_H

typedef enum {INT_TYPE, FLOAT_TYPE, STRING_TYPE} data_type;

typedef struct node {
    void* data;
    struct node* next;
    data_type type;
} node;



#endif // DEFINED_TYPES_H