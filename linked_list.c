#include "linked_list.h"

linked_list* create_linked_list() {
	linked_list* output = (linked_list*) malloc(sizeof(linked_list));
	if(!output) exit(EXIT_FAILURE);
	
	output->head = NULL;
	output->tail = NULL;
	output->size = 0;
	return output;
}

void free_linked_list(linked_list* list) {
	node* current = list->head;
	while(current != NULL) {
		node* next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	free(list);
}

void add_node_to_list(linked_list* list ,void* data, int type) {
	node* node_to_add = (node*) malloc(sizeof(node));
	if(list->head != NULL) {
		node_to_add->next = NULL;
		node_to_add->data = data;
		node_to_add->type = type;
	
		list->tail->next = node_to_add;
		list->tail = node_to_add;
	} else {
		node_to_add->next = NULL;
		node_to_add->data = data;
		node_to_add->type = type;
	
		list->head = node_to_add;
		list->tail = node_to_add;
		
	}
	list->size++;
	
}

void add_int_node_to_list(linked_list* list, int data) {
	int* int_to_add = (int*) malloc(sizeof(int));
	*int_to_add = data;

	add_node_to_list(list, int_to_add, INT_TYPE);
}

void add_float_node_to_list(linked_list* list, float data) {
	float* float_to_add = (float*) malloc(sizeof(float));
	*float_to_add = data;

	add_node_to_list(list, float_to_add, FLOAT_TYPE);
}

void add_string_node_to_list(linked_list* list, char* data) {
	char* string_to_add = strdup(data);
	add_node_to_list(list, string_to_add, STRING_TYPE);
}

unsigned int get_size_linked_list(linked_list* list) {
	return list->size;
}

void remove_element(linked_list* list, unsigned int index) {
	if(index < 0 || index >= list->size) {
		exit(EXIT_FAILURE);
	}

	node* prev_node = NULL;
	node* current = list->head;
	for(int i = 0; i < index; i++) {
		prev_node = current;
		current = current->next;
	}
	
	if(prev_node == NULL) {
		list->head = current->next;
	} else {
		node* next_node = current->next;
		prev_node->next = next_node;
	}

	free(current->data);
	free(current);

	list->size--;
}

void pop_element_from_linked_list(linked_list* list) {
	remove_element(list, get_size_linked_list(list) - 1);
}

void print_linked_list(linked_list* list) {
	node* current = list->head;
	printf("[ ");
	while(current) {
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
        if (current) printf(" , ");
	}
	printf(" ]\n");
}
