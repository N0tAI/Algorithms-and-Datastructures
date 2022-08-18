#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct _QueueNode {
	int value;
	struct _QueueNode* prev;
	struct _QueueNode* next;
};

typedef struct _QueueNode QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* end;
} Queue;

// This is a single 'easy' way to implement
// however we could create a priority queue as a sorted list which sorts based off of the rule for an added priority element
typedef struct {
	size_t priority_count;
	Queue** queues;
} PriorityQueue;

QueueNode* create_queue_node(const int value) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));

	if (node != NULL) {
		node->value = value;
		node->next = NULL;
		node->prev = NULL;
	}

	return node;
}
Queue* create_queue(const int* array, const size_t size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	if (queue != NULL) {
		if (size > 0 && array != NULL) {
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

PriorityQueue* create_priority(const size_t priorities) {
	if (priorities < 1)
		return NULL;

	PriorityQueue* pqueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));

	if (pqueue != NULL) {
		Queue** priority_queues = (Queue**)malloc(sizeof(Queue) * priorities);
		if (priority_queues == NULL) {
			free(pqueue);
			return NULL;
		}

		for (size_t i = 0; i < priority_queues; i++)
			priority_queues[i] = create_queue(NULL, 0);
		
		pqueue->priority_count = priorities;
		pqueue->queues = priority_queues;
	}

	return pqueue;
}


void enqueue(Queue* queue, const int value) {
	QueueNode* node = create_queue_node(value);

	if (node == NULL)
		return;

	if (queue->front == NULL) {
		queue->front = node;
		if (queue->end == NULL)
			queue->end = node;
	}
	else {
		queue->end->next = node;
		node->prev = queue->end;
		queue->end = queue->end->next;
	}
}

void enqueue_priority(PriorityQueue* queue, const size_t priority, const int value) {
	if (priority > queue->priority_count)
		return;

	enqueue(queue->queues[priority - 1], value);
}

void push(Queue* queue, const int value) {
	QueueNode* node = create_queue_node(value);

	if (node == NULL)
		return;

	if (queue->front == NULL) {
		queue->front = node;
		if (queue->end == NULL)
			queue->end = node;
	}
	else {
		node->next = queue->front;
		queue->front->prev = node;
		queue->front = node;
	}
}

void push_priority(PriorityQueue* queue, const size_t priority, const int value) {
	if (priority > queue->priority_count)
		return;

	push(queue->queues[priority - 1], value);
}

// remove from front
int pop(Queue* queue) {
	if (queue->front == NULL)
		return -1;

	QueueNode* node = queue->front;
	int value = node->value;

	queue->front = node->next;
	queue->front->prev = NULL;
	free(node);

	return value;
}

int next(PriorityQueue* queue) {
	for (size_t i = 0; i < queue->priority_count; i++)
		if (queue->queues[i]->front != NULL)
			return pop(queue->queues[i]);
}

// remove from back
int dequeue(Queue* queue) {
	if (queue->end == NULL)
		return -1;

	QueueNode* node = queue->end;
	int value = node->value;

	queue->end = node->next;
	queue->end->next = NULL;
	free(node);

	return value;
}

int is_empty(Queue* queue) {
	return queue->front == NULL;
}

int peek_first(const Queue* queue) {
	if (queue->front == NULL)
		return -1;
	return queue->front->value;
}

int peek_last(const Queue* queue) {
	if (queue->end == NULL)
		return -1;
	return queue->end->value;
}