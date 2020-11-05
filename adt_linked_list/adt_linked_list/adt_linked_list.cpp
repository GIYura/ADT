// adt_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

static node_t* list1 = NULL;
static node_t* list2 = NULL;

int main()
{
    //head = create_node(12);

    //delete_node(head);

    list1 = create_list(5, false);

    print_list(list1);

    list1 = clear_list(list1);

    print_list(list1);
}
