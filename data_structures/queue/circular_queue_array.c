#ifndef THAYBURTQUEUEIMPL
#define THAYBURTQUEUEIMPL
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* base;
	int* delete;
	int* write;
	size_t capacity;
} Queue;

int* next_wrapped_index(const Queue* queue, const int* ptr) {
	if (ptr < (queue->base + queue->capacity - 1))
		return ptr + 1;
	return queue->base;
}

int is_empty(const Queue* queue) {
	return queue->write == (queue->base - 1) || queue->delete == queue->write;
}

int is_full(const Queue* queue) {
	return (queue->delete == (queue->base - 1) ? queue->write == (queue->base + queue->capacity - 1) : queue->delete == next_wrapped_index(queue, queue->write));
}


void enqueue(Queue* queue, const int value) {
	if (is_full(queue))
		return;

	queue->write = next_wrapped_index(queue, queue->write);
	*queue->write = value;
}

Queue* create_queue(size_t size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	if (queue != NULL) {
		queue->base = (int*)malloc(size * sizeof(int));
		if (queue->base == NULL) {
			free(queue);
			return NULL;
		}
		queue->capacity = size;
		queue->delete = queue->base - 1;
		queue->write = queue->base - 1;
	}

	return queue;
}

int dequeue(Queue* queue) {
	if (is_empty(queue))
		return -1;

	queue->delete = next_wrapped_index(queue, queue->delete);
	return *queue->delete;
}

int peek_last(const Queue* queue) {
	return *queue->write;
}

int peek_first(const Queue* queue) {
	return *queue->delete;
}

#endif