#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

#define MAX_LINE_LENGTH 100
#define DELIMITERS " \t\r\n"

void to_lower_string(char *input) {
	int index = 0;
	while (input[index] != '\0') 
	{
		input[index] = tolower(input[index]);
		index++;
	}
}

void execute_command(List *list, char *command) {
	int arg1, arg2;
	char* command_name;
	command_name = strtok(command, DELIMITERS);
	string_tolower(command_name);
	if (strcmp(command_name, "add_start") == 0) {
		arg1 = atoi(strtok(NULL, DELIMITERS));
		insert_first(list, arg1);
	}
	if (strcmp(command_name, "add_end") == 0) {
		arg1 = atoi(strtok(NULL, DELIMITERS));
		insert_last(list, arg1);
	}
	if (strcmp(command_name, "add_after") == 0) {
		arg1 = atoi(strtok(NULL, DELIMITERS));
		arg2 = atoi(strtok(NULL, DELIMITERS));
		if (insert_after_element_first_occurrence(list, arg1, arg2) == -1) { // error - exit program
			free_list(list);
			exit(1);
		}
	}
	if (strcmp(command_name, "index") == 0) {
		arg1 = atoi(strtok(NULL, DELIMITERS));
		printf("%d\n", get_element_first_index(list, arg1));
	}
	if (strcmp(command_name, "del") == 0) {
		arg1 = atoi(strtok(NULL, DELIMITERS));
		if (remove_element_at_index(list, arg1) == -1) { // error - exit program
			free_list(list);
			exit(1);
		}
	}
	if (strcmp(command_name, "print") == 0) {
		print_list(list);
	}
	if (strcmp(command_name, "exit") == 0) {
		free_list(list);
		exit(0);
	}
}


int main() {
	List* list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	char command[MAX_LINE_LENGTH];
	while (fgets(command, MAX_LINE_LENGTH, stdin) != NULL) {
		execute_command(list, command);
	}
	return 0;
}