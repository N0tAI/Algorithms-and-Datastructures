#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* values;
	int* first;
	int* last;
	size_t capacity;
} Queue;

int is_empty(const Queue* queue) {
	return queue->first == queue->last;
}

int is_full(const Queue* queue) {
	return queue->last == &(queue->values + queue->capacity - 1);
}

void enqueue(Queue* queue, int value) {
	if (is_full(queue))
		return;

	queue->last++;
	*queue->last = value;
}

Queue* create_queue(size_t size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	if (queue != NULL) {
		queue->values = (int*)malloc(size * sizeof(int));
		if (queue->values == NULL) {
			free(queue);
			return NULL;
		}
		queue->capacity = size;
		queue->first = queue->values - 1;
		queue->last = queue->values - 1;
	}

	return queue;
}

int dequeue(Queue* queue) {
	if (is_empty(queue))
		return -1;

	queue->first++;
	return *queue->first;
}

int peek_first(const Queue* queue) {

}

int peek_last(const Queue* queue) {

}