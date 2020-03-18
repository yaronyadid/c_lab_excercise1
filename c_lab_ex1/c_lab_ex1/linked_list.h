#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

/*STRUCT*/
typedef struct node
{
	int value;
	struct node *next;
}Node;

/*FUNCTIONS*/

void insert_node_at_start(Node* head, int x);
void insert_node_at_the_end(Node* head, int x);
void print_list(Node * head);






#endif // !LINKED_LIST_HEADER
