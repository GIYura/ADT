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

    if (ring_init(&ring, RING_BUFFER_SZ, true) == SUCCESS) {
        printf("Ring buffer created\r\n");
    }
    else {
        printf("Ring buffer NOT created\r\n");
    }
        
    for (int i = 0; (i < RING_BUFFER_SZ + 10); i++) {
        ring_push(&ring, i * 10);
    }

    printf("-----------------------\r\n");

    int ret_val;
    for (int i = 0; i < (RING_BUFFER_SZ + 1); i++)
    {
        if (ring_pop(&ring, &ret_val)) {
            printf("Pop value\t:\t[%d]\r\n", ret_val);
        }
    }
}