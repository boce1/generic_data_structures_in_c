#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defined_types.h"
#include "hash_set.h"

typedef struct map_node {
    node base;
    void* pair_value;
    int pair_type;
} map_node;

typedef struct hash_map {
    map_node* entries[DEFAULT_CAPACITY];
} hash_map;

hash_map* create_hash_map();
void free_hash_map(hash_map* dict);

void add_pair_to_hash_map(hash_map* dict, void* key, int key_type, void* value, int value_type);


#endif // HASH_MAP_H