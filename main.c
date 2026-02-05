#include "linked_list.h"
#include "stack.h"
#include "hash_set.h"

int main() {
	linked_list* list = create_linked_list();
	stack* stk = create_stack();
	hash_set* set = create_hash_set();

	/*
	append_to_list(list, 45);
	append_to_list(list, 3.14);
	append_to_list(list, "Hello");
	append_to_list(list, 10);
	append_to_list(list, "World");
	append_to_list(list, 7.8);

	// print_linked_list(list);
	// printf("%u\n", get_size_linked_list(list));
	// remove_element(list, 0);
	pop_element_from_linked_list(list);
	pop_element_from_linked_list(list);
	pop_element_from_linked_list(list);
	
	// print_linked_list(list);

	add_to_stack(stk, 45);
	add_to_stack(stk, 3.14);
	add_to_stack(stk, "Hello");
	add_to_stack(stk, 10);
	add_to_stack(stk, "World");
	add_to_stack(stk, 7.8);
	print_stack(stk);

	pop_element_from_stack(stk);
	pop_element_from_stack(stk);
	pop_element_from_stack(stk);

	print_stack(stk);
	*/
	// printf("%d\n", get_int_hash_index(11)); // 12
	// printf("%d\n", get_int_hash_index(79)); // 12

	// printf("%d\n", get_float_hash_index(100.1454));
	//printf("%d\n", get_string_hash_index("hello world!"));
	
	add_to_hash_set(set, 11);
	add_to_hash_set(set, 1.34);
	add_to_hash_set(set, "Hello");
	add_to_hash_set(set, 79);
	add_to_hash_set(set, "World");
	add_to_hash_set(set, 79);
	add_to_hash_set(set, 79);
	add_to_hash_set(set, 1.34);

	print_hash_set(set);

	printf("%d\n", is_in_hash_set(set, 11));
	printf("%d\n", is_in_hash_set(set, "Hello"));
	printf("%d\n", is_in_hash_set(set, "hello"));
	printf("%d\n", is_in_hash_set(set, 1));
	printf("%d\n", is_in_hash_set(set, 79));

	remove_entry_from_hash(set, 79);
	remove_entry_from_hash(set, "Hello");
	remove_entry_from_hash(set, 1.34);
	remove_entry_from_hash(set, 2); // doesnt exist

	print_hash_set(set);
	
	free_stack(stk);
	free_linked_list(list);
	free_hash_set(set);
	return 0;
}