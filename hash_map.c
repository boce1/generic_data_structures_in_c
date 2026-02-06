#include "hash_map.h"

hash_map* create_hash_map() {
    hash_map* output = (hash_map*) malloc(sizeof(hash_map));
    if(!output) exit(EXIT_FAILURE);

	for(int i = 0; i < DEFAULT_CAPACITY; i++) {
        output->entries[i] = NULL;
    }
	return output;
}

void free_hash_map(hash_map* dict) {
    for(int i = 0; i < DEFAULT_CAPACITY; i++) {
        map_node* current = dict->entries[i];
        while(current) {
            // Access next via base, but cast it to map_node*
            map_node* next = (map_node*)current->base.next;

            // 1. Free the key (stored in base)
            free(current->base.data);

            // 2. Free the value (stored in map_node)
            if (current->pair_value) {
                free(current->pair_value);
            }

            // 3. Free the node itself
            free(current);

            current = next;
        }
    }
    free(dict);
}


void add_pair_to_hash_map(hash_map* dict, void* key_pair, int key_type, void* value_pair, int value_type) {
	int index;
	switch (key_type)
	{
		case INT_TYPE:
			index = get_int_hash_index(*((int*) key_pair));
			break;
		case FLOAT_TYPE:
			index = get_float_hash_index(*((float*) key_pair));
			break;
		case STRING_TYPE:
			index = get_string_hash_index((char*) key_pair);
			break;
		default: return;
	}

	map_node* current = dict->entries[index];
	while(current) {
		if(current->base.type == key_type && values_equal(current->base.data, key_pair, key_type)) {
			// update the value
			free(current->pair_value);
            current->pair_value = value_pair;
            current->pair_type = value_type;
            
            free(key_pair); 
            return;
		}
		current = (map_node*)current->base.next;
	}

	// Key not found: Insert new map_node
    map_node* new_entry = (map_node*) malloc(sizeof(map_node));
    if(!new_entry) exit(EXIT_FAILURE);

    new_entry->base.data = key_pair;
    new_entry->base.type = key_type;
    new_entry->pair_value = value_pair;
    new_entry->pair_type = value_type;

    // Push to front of the chain
    new_entry->base.next = (node*)dict->entries[index];
    dict->entries[index] = new_entry;
}