# License
If this code is useful for you, you can do whatever you want with it.

# Features

These data structures can work only with int types, strings, float. Doubles are threaded as floats.

## Disclamier

This is no profesional nor very useful repo. I dont want to lose this code and I use this repo as backup.

# Fundamental functions

## Nodes
`node` is a structure that contains void pointer to data, pointer to the next node, and type of data that stores (int, float, string).
```c
typedef struct node {
    void* data;
    struct node* next;
    data_type type;
} node;
```

## Linked list
`linked_list` - structure that contains head node, tail node, and number of nodes that contains
```c
create_linked_list(); // returns pointer to a linked list
```
```c
free_linked_list(linked_list); // frees allocated memory fo linked list
```
```c
pop_element_from_linked_list(linked_list); // removes the last element of list
```
```c
remove_element(linked_list, index); // removes the element at the index position
```
```c
print_linked_list(list); // prints the linked list
```
```c
append_to_list(list, data) // appends the data to the end of the list, data can be any type
```
```c
get_size_linked_list(list); // returns unsigned int corresponding to the number of nodes in linked list
```

## Stack
`stack` - structure that contains head node and number of nodes that contains
```c
create_stack(); // returns pointer to a stack
```
```c
free_stack(stack); // frees memory allocated for stack
```
```c
pop_element_from_stack(stack); // pops element
```
```c
print_stack(stack); // prints the stack
```
```c
add_to_stack(stack, data) // adds data to the top of the stack, data can be any type
```
```c
get_size_stack(stack); // returns unsigned int corresponding to the number of nodes in stack
```

## Hash set
`hash_set` - structures with entries with chain method, the arrays inside of hash set is array of `node` data structure above
```c
create_hash_set(); // returns the pointer to hash set
```
```c
free_hash_set(hash_set* set); // frees allocated memory for hash set
```
```c
add_to_hash_set(set, data); // adds entry to hash set
```
```c
is_in_hash_set(set, data); // return 0 or 1 depending if the element is in hash set or not
```
```c
remove_entry_from_hash(set, data); // removes the element from the hash set if it exists

```
### To Do: add trees, and list for pair values in dictionaries