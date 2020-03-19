#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

Node *new_node(int value) {
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

void insert_at_start(List *list, int value) {
	Node* node = new_node(value);
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	}
	else {
		node->next = list->head;
		list->head = node;
	}
}

void insert_at_end(List *list, int value) {
	Node* node = new_node(value);
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	}
	else {
		list->tail->next = node;
		list->tail = node;
	}
}

/* the element is inserted after the first occurrence of the specified element in the list. 
   if no such element exists, -1 is returned */
int  insert_after_element(List *list, int value_to_insert, int value_to_insert_after) {
	Node* current = list->head;
	Node* node_to_insert = new_node(value_to_insert);
	while (current != NULL) {
		if (current->value == value_to_insert_after) {
			node_to_insert->next = current->next;
			current->next = node_to_insert;
			if (current == list->tail) {
				list->tail = node_to_insert;
			}
			return 0;
		}
		current = current->next;
	}

	printf("Element %d is not in list\n", value_to_insert_after);
	free(node_to_insert);
	return -1;
}

/* if the element isn't found, -1 is returned */
int get_first_index_by_value(List *list, int value) {
	int index = 0;
	Node* current = list->head;
	while (current != NULL) {
		if (current->value == value) {
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;
}


void print_list(List *list) {
	printf("[");
	Node* current = list->head;
	while (current != NULL) {
		printf("%d", current->value);
		if (current->next != NULL) {
			printf(", ");
			current = current->next;
		}
	}
	printf("]\n");
}

void free_list(List *list) {
	Node* current;
	while (list->head != NULL) {
		current = list->head;
		list->head = list->head->next;
		free(current);
	}
}

int remove_element_at_index(List *list, int index) {
	Node* current = list->head;
	Node* node_to_remove;
	int current_index = 0;
	if (list->head == NULL) {
		printf("Specified index is too large\n");
		return -1;
	}
	if (index == 0) {
		node_to_remove = list->head;
		list->head = list->head->next;
		free(node_to_remove);
		return 0;
	}
	while (current != NULL) {
		if (current_index == (index-1)) {
			if (current->next == NULL) {
				printf("Specified index is too large\n");
				return -1;
			}
			node_to_remove = current->next;
			current->next = current->next->next;
			free(node_to_remove);
			return 0;
		}
		current = current->next;
		current_index++;
	}
	printf("Specified index is too large\n");
	return -1;
}
