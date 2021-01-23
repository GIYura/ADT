#ifndef _RING_H
#define _RING_H

#define RING_BUFFER_SZ  3

#include <stdbool.h>

typedef enum {
	SUCCESS = 0,
	ERROR
}status_t;

typedef struct RING {
	int buffer[RING_BUFFER_SZ];
	int buffer_sz;
	int head;
	int tail;
	bool over;
}ring_t;

status_t ring_init(ring_t*, int, bool);
void ring_deinit(ring_t*);

void ring_push(ring_t*, int);
bool ring_pop(ring_t*, int*);

#endif // !_RING_H

