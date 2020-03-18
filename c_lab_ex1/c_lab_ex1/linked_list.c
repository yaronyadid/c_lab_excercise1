#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int list_size = 0;




void insert_node_at_start(Node** head,int x) 
{

	Node * temp;
	temp = (Node*)malloc(sizeof(Node));
	if (!temp)
	{
		printf("Node allocation failed");
	}
	temp->value = x;
	
	if (*head == NULL)
	{
		*head = temp;
		(*head)->next = NULL;
	}
	else
	{
		temp->next = *head;
		*head = temp;
	}
	list_size++;
}

void insert_node_at_the_end(Node* head,int x)
{
	Node *temp,*node;
	temp = (Node*)malloc(sizeof(Node));
	temp->value = x;

	if (head == NULL) {
		head = temp;
		head->next = NULL;
	}
	else
	{/*traverse to the end of the list to enter the new node*/
		node = head;

		while (node->next != NULL)
		{
			node = node->next;
		}

		node->next = temp;
		temp->next = NULL;
	}
	list_size++;
}

void print_list(Node ** head)
{
	Node* temp;
	if (list_size == 0)
	{
		printf("[]\n");
	}
	else
	{
		temp = *head;
		printf("[");
		while (temp->next != NULL)
		{
			printf("%d, ", temp->value);
			temp = temp->next;
		}
		printf("%d]\n", temp->value);
	}
}
