#ifndef THAYBURTDOUBLEQUEUEIMPL
#define THAYBURTDOUBLEQUEUEIMPL
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "double_linked_queue.h"

double_queue_node_t* create_double_queue_node(const void* value) {
	double_queue_node_t* node = (double_queue_node_t*)malloc(sizeof(double_queue_node_t));

	if (node != NULL) {
		node->value = value;
		node->next = NULL;
		node->prev = NULL;
	}

	return node;
}
double_queue_t* create_double_queue(const void** array, const size_t size) {
	double_queue_t* queue = (double_queue_t*)malloc(sizeof(double_queue_t));

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

void init_double_queue(double_queue_t* queue) {
	queue->end = NULL;
	queue->front = NULL;
}

void enqueue_double(double_queue_t* queue, const void* value) {
	double_queue_node_t* node = create_double_queue_node(value);

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

void push_double(double_queue_t* queue, const void* value) {
	double_queue_node_t* node = create_double_queue_node(value);

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

// remove from front
void* pop_double(double_queue_t* queue) {
	if (queue->front == NULL)
		return -1;

	double_queue_node_t* node = queue->front;
	int value = node->value;
	
	queue->front = node->next;
	queue->front->prev = NULL;
	free(node);

	return value;
}

// remove from back
void* dequeue_double(double_queue_t* queue) {
	if (queue->end == NULL)
		return -1;

	double_queue_node_t* node = queue->end;
	int value = node->value;

	queue->end = node->next;
	queue->end->next = NULL;
	free(node);

	return value;
}

void* is_empty_double_queue(double_queue_t* queue) {
	return queue->front == NULL;
}

void* peek_first(const double_queue_t* queue) {
	if (queue->front == NULL)
		return -1;
	return queue->front->value;
}

void* peek_last(const double_queue_t* queue) {
	if (queue->end == NULL)
		return -1;
	return queue->end->value;
}

#endif