all:
	gcc main.c linked_list.c stack.c hash_set.c -o main

clean:
	rm -f main