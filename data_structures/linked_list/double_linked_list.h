#ifndef THAYBURTDOUBLELINKEDLIST
#define THAYBURTDOUBLELINKEDLIST

#include <stddef.h>

struct _DoubleLinkedNode {
	int value;
	struct _DoubleLinkedNode* next;
	struct _DoubleLinkedNode* prev;
};

typedef struct _DoubleLinkedNode DoubleLinkedNode;

typedef struct {
	DoubleLinkedNode* first;
	DoubleLinkedNode* last;
	size_t length;
} DoubleLinkedList;

DoubleLinkedNode* double_node_create(const int value);
DoubleLinkedList* double_list_create(const int arr[], const size_t size);

void double_list_display(const DoubleLinkedList* list);

void double_list_insert(DoubleLinkedList* list, const size_t index, const int value);

int double_list_delete_at(DoubleLinkedList* list, const size_t index);

void double_list_reverse(DoubleLinkedList* list);

#endif