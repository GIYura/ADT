// ring_buffer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include "ring.h"

static ring_t ring;

int main()
{
    printf("-----------------------\r\n");
    printf("| Ring buffer example |\r\n");
    printf("-----------------------\r\n");

    if (ring_init(&ring, RING_BUFFER_SZ + 1, true) == SUCCESS) {
        printf("Ring buffer created\r\n");
    }
    else {
        printf("Ring buffer NOT created\r\n");
    }
            
//    ring_push(&ring, 123);
//    ring_push(&ring, 1234);
//    ring_push(&ring, 12345);
    ring.push(&ring, 12);
    ring.push(&ring, 123);
    ring.push(&ring, 1234);  

    printf("-----------------------\r\n");

    int ret_val;
    for (int i = 0; i < (100); i++)
    {
        if (ring.pop(&ring, &ret_val)) {
            printf("Pop value\t:\t[%d]\r\n", ret_val);
        }
    }
}