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

static void next_head(ring_t* r) {
	r->head = (r->head + 1) % r->buffer_sz;
}

static void next_tail(ring_t* r) {
	r->tail = (r->tail + 1) % r->buffer_sz;
}

status_t ring_init(ring_t* r, int s, bool o) {
	assert(r);
	assert(s);

	//r->buffer = malloc(sizeof(int) * s + 1);
	//if (!r->buffer) {
	//	printf("Can'r allocate memory\r\n");
	//	return ERROR;
	//}

	r->buffer_sz = s;
	r->head = 0;
	r->tail = 0;
	r->over = o;

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

void ring_push(ring_t* r, int v) {
	assert(r);

	if (is_full(r)) {
		next_tail(r);
//		r->tail = (r->tail + 1) % RING_BUFFER_SZ;
	}
	r->buffer[r->head] = v;
//	r->head = (r->head + 1) % RING_BUFFER_SZ;
	next_head(r);
	printf("Push value\t:\t[%d]\r\n", v);
}

bool ring_pop(ring_t* r, int* ret_val) {
	assert(r);

	if (is_empty(r)) {
		return false;
	}
	*ret_val = r->buffer[r->tail];
//	r->tail = (r->tail + 1) % RING_BUFFER_SZ;
	next_tail(r);
	return true;
}