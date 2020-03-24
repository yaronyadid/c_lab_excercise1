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
	Node* traverse_node = list->head;
	Node* node_to_insert = new_node(value_to_insert);
	while (traverse_node != NULL) {
		if (traverse_node->value == value_to_insert_after) {
			node_to_insert->next = traverse_node->next;
			traverse_node->next = node_to_insert;
			if (traverse_node == list->tail) {
				list->tail = node_to_insert;
			}
			return 0;
		}
		traverse_node = traverse_node->next;
	}

	printf("Element %d is not in list\n", value_to_insert_after);
	free(node_to_insert);
	return -1;
}

/* if the element isn't found, -1 is returned */
int get_first_index_by_value(List *list, int value) {
	int index = 0;
	Node* traverse_node = list->head;
	while (traverse_node != NULL) {
		if (traverse_node->value == value) {
			return index;
		}
		traverse_node = traverse_node->next;
		index++;
	}
	return -1;
}


void print_list(List *list) {
	printf("[");
	Node* traverse_node = list->head;
	while (traverse_node != NULL) {
		printf("%d", traverse_node->value);
		if (traverse_node->next != NULL) {
			printf(", ");
		}
		traverse_node = traverse_node->next;
	}
	printf("]\n");
}

void free_list(List *list) {
	Node* traverse_node;
	while (list->head != NULL) {
		traverse_node = list->head;
		list->head = list->head->next;
		free(traverse_node);
	}
}

int remove_element_at_index(List *list, int index) {
	Node* traverse_node = list->head;
	Node* node_to_remove;
	int traverse_node_index = 0;
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
	while (traverse_node != NULL) {
		if (traverse_node == (index-1)) {
			if (traverse_node->next == NULL) {
				printf("Specified index is too large\n");
				return -1;
			}
			node_to_remove = traverse_node->next;
			traverse_node->next = traverse_node->next->next;
			free(node_to_remove);
			return 0;
		}
		traverse_node = traverse_node->next;
		traverse_node_index++;
	}
	printf("Specified index is too large\n");
	return -1;
}
