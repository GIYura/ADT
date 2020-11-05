#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

//
void print_list(node_t* head) {
	node_t* current;

	if (head == NULL) {
		printf("List is empty\r\n");
	}
	else
	{
		current = head;
		while (current != NULL)
		{
			printf("%d\r\n", current->data);
			current = current->next;
		}
	}
}

//
node_t* create_node(int value) {
	node_t* ret = malloc(sizeof(node_t));
	if (ret != NULL) {
		printf("Node created\r\n");
		ret->data = value;
		ret->next = NULL;
	}
	
	return ret;
}

//
void delete_node(node_t* node) {
	if (node != NULL) {
		node->data = 0;
		node->next = NULL;
		free(node);
	}
	printf("Node deleted\r\n");
}

//
node_t* create_list(int size, bool order) {
	node_t* ret = NULL;

	if (size > 0) {
		node_t* head = malloc(sizeof(node_t));
		if (head == NULL) {
			printf("Can't allocate memory\r\n");
		}
		else {
			head->data = 0;
			head->next = NULL;
			node_t* temp = head;

			for (int i = 1; i < size; i++) {
				node_t* new_node = malloc(sizeof(node_t));
				if (new_node == NULL) {
					printf("Can't allocate memory\r\n");
				}
				else {
					new_node->data = i;
					if (!order) {
						new_node->next = head;
						head = new_node;
					}
					else {
						new_node->next = NULL;
						temp->next = new_node;
						temp = temp->next;
					}
				}
			}
			ret = head;
		}
		printf("List created\r\n");
	}
	else {
		printf("The size of linked list should be > 0\r\n");
	}
	return ret;
}

//
node_t* clear_list(node_t* head) {
	node_t* temp;

	if (head == NULL) {
		printf("List is empty\r\n");
	}
	else {
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		head = NULL;
	}
	printf("List deleted\r\n");
	return head;
}