#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node
{
	int value;
	struct node *next;
}Node;

typedef struct list {
	Node *head;
	Node *tail;
}List;

Node *new_node(int value);
void insert_at_start(List *list, int value);
void insert_at_end(List *list, int value);
void print_list(List *list);
void free_list(List *list);
int insert_after_element(List *list, int value_to_insert, int value_to_insert_after);
int get_first_index_by_value(List *list, int value);
int remove_element_at_index(List *list, int index);

#endif 
