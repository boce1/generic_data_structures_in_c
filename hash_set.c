#include "hash_set.h"

hash_set* create_hash_set() {
	hash_set* output = (hash_set*) malloc(sizeof(hash_set));
	if(!output) exit(EXIT_FAILURE);
	
	for(int i = 0; i < DEFAULT_CAPACITY; i++) {
        output->entries[i] = NULL;
    }
	return output;
}

void free_hash_set(hash_set* set) {
    for(int i = 0; i < DEFAULT_CAPACITY; i++) {
        node* current = set->entries[i];
        while(current) {
            node* next = current->next;
            free(current->data);
            free(current);
            current = next;
        }
    }
    free(set);
}

int get_int_hash_index(int value) {
    unsigned int magic_number = (value * 0x9E3779B1) >> 0; // >> 0 to ensure 32 bit integer is beign produced
    int index = magic_number % DEFAULT_CAPACITY;
    return index;
}

int get_float_hash_index(float value) {
    unsigned int bits;
    memcpy(&bits, &value, sizeof(bits));

    int index = get_int_hash_index(bits);
    return index;
}

// DJB2
int get_string_hash_index(char* value) {
    unsigned long hash = 5381; // starting seed
    int c;
    while ((c = *value++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % DEFAULT_CAPACITY;
}

int values_equal(void* d1, void* d2, int type) {
    if (type == INT_TYPE) return *(int*)d1 == *(int*)d2;
    if (type == FLOAT_TYPE) return *(float*)d1 == *(float*)d2;
    if (type == STRING_TYPE) return strcmp((char*)d1, (char*)d2) == 0;
    return 0;
}

void add_hash_entry(hash_set* set, void* data, int type, int index) {
    // Check if the value is already in the list at this index
    node* current = set->entries[index];
    while (current != NULL) {
        if (current->type == type && values_equal(current->data, data, type)) {
            // Already exists! 
            // IMPORTANT: Since the wrappers (add_int_hash_entry, etc.)
            // just malloc'd 'data', we must free it here before returning.
            free(data); 
            return; 
        }
        current = current->next;
    }

    // If we reach here, it's a new unique value. Add it!
    node* node_to_add = (node*) malloc(sizeof(node));
    node_to_add->type = type;
    node_to_add->data = data;
    
    // Using the "Push to Front" method
    node_to_add->next = set->entries[index];
    set->entries[index] = node_to_add;
}

void add_int_hash_entry(hash_set* set, int value) {
    int* int_to_add = (int*) malloc(sizeof(int));
	*int_to_add = value;
    int index = get_int_hash_index(value);
	add_hash_entry(set, int_to_add, INT_TYPE, index);
}

void add_float_hash_entry(hash_set* set, float value) {
    float* float_to_add = (float*) malloc(sizeof(float));
	*float_to_add = value;
    int index = get_float_hash_index(value);
	add_hash_entry(set, float_to_add, FLOAT_TYPE, index);
}

void add_string_hash_entry(hash_set* set, char* value) {
    char* string_to_add = strdup(value);
    int index = get_string_hash_index(value);
	add_hash_entry(set, string_to_add, STRING_TYPE, index);
}

void print_hash_set(hash_set* set) {
    int first_element = 1;
    printf("{ ");
    for(int i = 0; i < DEFAULT_CAPACITY; i++) {
        if(set->entries[i] != NULL) {
            node* current = set->entries[i];

            while(current) {
                if (!first_element) {
                    printf(", ");
                }

                switch (current->type) {
                    case INT_TYPE:
                        printf("%d", *(int*)current->data);
                        break;
                    case FLOAT_TYPE:
                        printf("%.2f", *(float*)current->data);
                        break;
                    case STRING_TYPE:
                        printf("\"%s\"", (char*)current->data);
                        break;
                }
                current = current->next;
                first_element = 0;
            }
            
        }
    }
    printf(" }\n");
}

int is_data_in_hash_set(hash_set* set, void* data, int type, int index) {
    node* current = set->entries[index];
    while (current != NULL) {
        if (current->type == type && values_equal(current->data, data, type)) {
            return 1; 
        }
        current = current->next;
    }

    return 0;
}

int is_int_in_hash_set(hash_set* set, int value) {
    int index = get_int_hash_index(value);
    return is_data_in_hash_set(set, &value, INT_TYPE, index);
}

int is_float_in_hash_set(hash_set* set, float value) {
    int index = get_float_hash_index(value);
    return is_data_in_hash_set(set, &value, FLOAT_TYPE, index);
}

int is_string_in_hash_set(hash_set* set, char* value) {
    int index = get_string_hash_index(value);
    return is_data_in_hash_set(set, value, STRING_TYPE, index);
}


void remove_hash_entry(hash_set* set, void* data, int type, int index) {
    node* current = set->entries[index];
    node* prev = NULL;

    while (current != NULL) {
        if (current->type == type && values_equal(current->data, data, type)) {
            // Found it! Now unlink it
            if (prev == NULL) {
                // Scenario A: It's the head of the list
                set->entries[index] = current->next;
            } else {
                // Scenario B: It's in the middle or end
                prev->next = current->next;
            }

            // Cleanup memory
            free(current->data);
            free(current);
            return; // Exit after deleting one instance
        }
        prev = current;
        current = current->next;
    }
}

void remove_int_from_set(hash_set* set, int value) {
    int index = get_int_hash_index(value);
    remove_hash_entry(set, &value, INT_TYPE, index);
}

void remove_float_from_set(hash_set* set, float value) {
    int index = get_float_hash_index(value);
    remove_hash_entry(set, &value, FLOAT_TYPE, index);
}

void remove_string_from_set(hash_set* set, char* value) {
    int index = get_string_hash_index(value);
    remove_hash_entry(set, value, STRING_TYPE, index);
}