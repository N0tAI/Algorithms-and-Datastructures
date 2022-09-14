#ifndef THAYBURTQUEUEIMPL
#define THAYBURTQUEUEIMPL
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct _QueueNode {
	int value;
	struct _QueueNode* next;
};

typedef struct _QueueNode QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* end;
} Queue;

QueueNode* create_queue_node(const int value) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));

	if (node != NULL) {
		node->value = value;
		node->next = NULL;
	}

	return node;
}
Queue* create_queue(const int* array, const size_t size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	if (queue != NULL) {
		if (size > 0) {
			for (size_t i = 0; i < size; i++)
				enqueue(queue, array[i]);
		}
		else {
			queue->front = NULL;
			queue->end = NULL;
		}
	}

	return queue;
}

void enqueue(Queue* queue, const int value) {
	QueueNode* node = create_queue_node(value);

	if (node == NULL)
		return;

	if (queue->front == NULL) {
		queue->front = node;
		if (queue->end == NULL) {
			queue->end = node;
		}
	}
	else {
		queue->end->next = node;
		queue->end = queue->end->next;
	}
}

int dequeue(Queue* queue) {
	if (queue->front == NULL)
		return -1;

	int value = queue->front->value;
	QueueNode* node = queue->front;
	
	queue->front = queue->front->next;
	free(node);
	
	return value;

}

int is_empty(Queue* queue) {
	return queue->front == NULL;
}

int peek_first(const Queue* queue) {
	return queue->front;
}

int peek_last(const Queue* queue) {
	return queue->end;
}

#endif