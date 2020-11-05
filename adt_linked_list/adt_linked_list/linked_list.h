#pragma once
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node* next;
}node_t;

void print_list(node_t* head);

node_t* create_node(int value);
void delete_node(node_t*);

//
node_t* create_list(int size, bool order);

//
node_t* clear_list(node_t* head);