#include <stdio.h>
#include "looped_list.h"

LinkedNode* create_looped_node(int value) {
	LinkedNode* node = create_node(value);
	if(node != NULL)
		node->next = node;
	return node;
}
LinkedList* create_looped(int arr[], size_t size) {
	LinkedList* list = create_list(arr, size);
	if (list != NULL)
		if (list->last != NULL)
			list->last->next = list->first;
	return list;
}

void display_looped_nodes(const LinkedNode* node) {
	if (node == NULL)
		return;
	LinkedNode* current = node;
	do {
		printf("%d ", current->value);
		current = current->next;
	} while (current != node);
	putchar('\n');
}
void display_looped(LinkedList* list) {
	display_looped_nodes(list->first);
}

void insert_looped(LinkedList* list, const size_t index, const int value) {
	insert(list, index, value);
	if (list->length < 1)
		return;
	if (index == 0 || index == list->length - 1)
		list->last->next = list->first;
}

void internal_new_insert_looped(LinkedList* list, const size_t index, const int value) {
	if (index > list->length)
		return;

	LinkedNode* node = create_looped_node(value);

	if (node == NULL)
		return;

	if (index == 0) {
		
		if (list->first != NULL)
			node->next = list->first;
		list->first = node;
		if (list->last != NULL)
			list->last->next = node;
		else
			list->last = node;
		return;
	}
	else if (index == list->length) {
		list->last->next = node;
		list->last = node;
		node->next = list->first;
	}
	else {
		LinkedNode* current_node = list->first->next;
		for (size_t i = 0; i < index - 1; i++)
			current_node = current_node->next;
		node->next = current_node->next;
		current_node->next = node;
	}
	list->length++;
}

int looped_delete_at(LinkedList* list, const size_t index) {
	if (list->length == 0)
		return 0;

	if (index >= list->length)
		return -1;

	int value;
	if (index == 0) {
		if (list->last == list->first)
			list->last = NULL;
		if (list->first->next == list->first) {
			value = list->first->value;
			free(list->first);
			list->first = NULL;
		}
	}
	else {
		LinkedNode* prev = list->first;
		for (size_t i = 0; i < index - 1; i++)
			prev = prev->next;
		
		LinkedNode* to_delete = prev->next;
		prev->next = prev->next->next;
		value = to_delete->value;
		free(to_delete);

		if (index == list->length - 1)
			list->last = prev;
	}
	list->length--;
	return value;
}