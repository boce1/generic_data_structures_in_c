#include "stack.h"

stack* create_stack() {
    stack* output = (stack*) malloc(sizeof(stack));
	if(!output) exit(EXIT_FAILURE);
	
	output->head = NULL;
	output->size = 0;
	return output;
}

void free_stack(stack* stk) {
	node* current = stk->head;
	while(current != NULL) {
		node* next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	free(stk);
}

void print_stack(stack* stk) {
    node* current = stk->head;
    printf("----------\n");
	while(current) {
		switch (current->type) {
            case INT_TYPE:
                printf("%d\n", *(int*)current->data);
                break;
            case FLOAT_TYPE:
                printf("%.2f\n", *(float*)current->data);
                break;
            case STRING_TYPE:
                printf("\"%s\"\n", (char*)current->data);
                break;
        }
        current = current->next;
	}
	printf("----------\n");
}

unsigned int get_size_stack(stack* stk) {
    return stk->size;
}

void add_node_to_stack(stack* stk, void* data, int type) {
    node* node_to_add = (node*) malloc(sizeof(node));
	
    node_to_add->next = stk->head;
	node_to_add->data = data;
	node_to_add->type = type;
	stk->head = node_to_add;
	stk->size++;
}

void add_int_node_to_stack(stack* stk, int data) {
    int* int_to_add = (int*) malloc(sizeof(int));
	*int_to_add = data;

	add_node_to_stack(stk, int_to_add, INT_TYPE);
}

void add_float_node_to_stack(stack* stk, float data) {
	float* float_to_add = (float*) malloc(sizeof(float));
	*float_to_add = data;

	add_node_to_stack(stk, float_to_add, FLOAT_TYPE);
}

void add_string_node_to_stack(stack* stk, char* data) {
	char* string_to_add = strdup(data);
	add_node_to_stack(stk, string_to_add, STRING_TYPE);
}

void pop_element_from_stack(stack* stk) {
    if(stk->head != NULL) {
        node* new_head = stk->head->next;
        free(stk->head->data);
        free(stk->head);
        stk->head = new_head;
    }
}