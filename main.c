#include "linked_list.h"
#include "stack.h"

int main() {
	linked_list* list = create_linked_list();
	stack* stk = create_stack();

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

	free_stack(stk);
	free_linked_list(list);
	return 0;
}