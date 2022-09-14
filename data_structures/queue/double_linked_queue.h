#ifndef THAYBURTDOUBLEQUEUE
#define THAYBURTDOUBLEQUEUE
#include <stddef.h>

struct _double_queue_node_t {
	void* value;
	struct _double_queue_node_t* prev;
	struct _double_queue_node_t* next;
};

typedef struct _double_queue_node_t double_queue_node_t;

typedef struct {
	double_queue_node_t* front;
	double_queue_node_t* end;
} double_queue_t;

double_queue_t* create_double_queue(const void** array, const size_t size);
void init_double_queue(double_queue_t* queue);
void enqueue_double(double_queue_t* queue, const void* value);
void push_double(double_queue_t* queue, const void* value);
void* pop_double(double_queue_t* queue);
void* dequeue_double(double_queue_t* queue);
void* is_empty_double_queue(double_queue_t* queue);
void* peek_first(const double_queue_t* queue);
void* peek_last(const double_queue_t* queue);

#endif