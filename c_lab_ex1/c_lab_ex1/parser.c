#include "parser.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

#define _CRT_SECURE_NO_WARNINGS



#define MAX_LENGTH 100
#define COMMAND_LENGTH 3
#define READ_SUCCEED 1
#define READ_UNSUCCESSFUL 0
#define DELIMITERS " \t\r\n"



void lower_case_string(char* input) {
	int ind = 0;
	while (input[ind] != '\0') 
	{
		input[ind] = tolower(input[ind]);
		ind++;
	}
}


int Get_input_from_user(char* input) {
	if (fgets(input, MAX_LENGTH, stdin) != NULL)
	{
		return READ_SUCCEED;
	}
	return READ_UNSUCCESSFUL;

}

int get_command_number(char* command_name)
{
	lower_case_string(command_name);
	if (!strcmp(command_name, "add_end"))
	{
		return ADD_END;
	}
	else if (!strcmp(command_name, "add_start"))
	{
		return ADD_START;
	}
	else if (!strcmp(command_name, "add_after"))
	{
		return ADD_AFTER;
	}
	else if (!strcmp(command_name, "index"))
	{
		return FIND_INDEX;
	}
	else if (!strcmp(command_name, "del"))
	{
		return DELETE_INDEX;
	}
	else if (!strcmp(command_name, "print"))
	{
		return PRINT;
	}
	else if (!strcmp(command_name, "exit"))
	{
		return EXIT;
	}
	
}

int* return_3_first_words_from_line(char* input)
{
	static int current_command[COMMAND_LENGTH];
	char* ptr = strtok(input, DELIMITERS);
	current_command[0] = get_command_number(ptr);
	ptr = strtok(NULL, DELIMITERS);
	if (ptr != NULL)
	{
		current_command[1] = atoi(ptr);
	}
	ptr = strtok(NULL, DELIMITERS);
	if (ptr != NULL)
	{
		current_command[2] = atoi(ptr);
	}
	
	return current_command;

}

int execute_command(Node* head,int* command)
{
	if (*command == ADD_START)//add at start
	{
		insert_node_at_start(head, command[1]);
	}
	if (*command == PRINT)//add at start
	{
		print_list(head);
	}
	return 1;
}

int main(){
	char line[MAX_LENGTH];
	int exit = 0;
	int* command;
	Node* head = NULL;

	command = (int*)malloc(3 * sizeof(int));
	while (exit != 1) {

		if (Get_input_from_user(line))
		{
			command = (int*)return_3_first_words_from_line(line);
			execute_command(&head,command);
			printf("%d %d %d\n", command[0], command[1], command[2]);
		}
		else
		{

		}

	}








}


