#include "ring.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

static bool is_full(ring_t* r) {
	if ( ((r->head + 1) % r->buffer_sz) == r->tail) {
		return true;
	}
	return false;
}

static bool is_empty(ring_t* r) {
	if (r->head == r->tail) {
		return true;
	}
	return false;
}

static int next_index(ring_t* r, int idx) {
	return (idx + 1) % r->buffer_sz;
}
static void push(ring_t*, int);
static bool pop(ring_t*, int*);

status_t ring_init(ring_t* r, int s, bool o) {
	assert(r);
	assert(s);

	r->buffer = malloc(sizeof(int) * s);
	if (!r->buffer) {
		printf("Can'r allocate memory\r\n");
		return ERROR;
	}

	r->buffer_sz = s;
	r->head = 0;
	r->tail = 0;
	r->over = o;

	r->push = &push;
	r->pop = &pop;

	return SUCCESS;
}

void ring_deinit(ring_t* r) {
	assert(r);

	r->buffer_sz = 0;
	r->head = 0;
	r->tail = 0;
	r->over = false;
	free(r->buffer);
	printf("Ring buffer deinit\r\n");
}

void push(ring_t* r, int v) {
	assert(r);

	if (is_full(r)) {
		if (!r->over) {
			return;
		}
		r->tail = next_index(r, r->tail);
	}
	r->buffer[r->head] = v;
	r->head = next_index(r, r->head);
	printf("Push value\t:\t[%d]\r\n", v);
}

bool pop(ring_t* r, int* ret_val) {
	assert(r);

	if (is_empty(r)) {
		return false;
	}
	*ret_val = r->buffer[r->tail];
	r->tail = next_index(r, r->tail);
	return true;
}