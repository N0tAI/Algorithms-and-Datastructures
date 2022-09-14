#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "double_linked_list.h"

DoubleLinkedNode* double_node_create(const int value) {
	DoubleLinkedNode* node = (DoubleLinkedNode*)malloc(sizeof(DoubleLinkedNode));
	if (node != NULL) {
		node->value = value;
		node->next = NULL;
		node->prev = NULL;
	}
	return node;
}
DoubleLinkedList* double_list_create(const int arr[], const size_t size) {
	DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedNode));

	if (list == NULL)
		return NULL;

	list->length = 0;
	if (size < 1) {
		list->first = NULL;
		list->last = NULL;
		return list;
	}

	DoubleLinkedNode* current = double_node_create(arr[0]);
	if (current == NULL)
		return list;
	list->first = current;
	list->length++;

	for (size_t i = 1; i < size - 1; i++) {
		DoubleLinkedNode* next = double_node_create(arr[i]);
		
		if (next == NULL)
			break;

		current->next = next;
		next->prev = current;
		current = next;
		list->length++;
	}
	list->last = current;
}

void double_list_display(const DoubleLinkedList* list) {
	if (list == NULL || list->length < 1)
		return;

	DoubleLinkedNode* current = list->first;
	do {
		printf("%d ", current->value);
		current = current->next;
	} while (current != NULL);
}

void double_list_insert(DoubleLinkedList* list, const size_t index, const int value) {
	if (list == NULL || index > list->length)
		return;

	DoubleLinkedNode* new_node = double_node_create(value);
	if (new_node == NULL)
		return;

	if (index == 0) {
		new_node->next = list->first;
		list->first = new_node;
	}
	else if (index == list->length) {
		new_node->prev = list->last;
		list->last->next = new_node;
		list->last = new_node;
	}
	else {
		DoubleLinkedNode* insert_point;
		if (index > (list->length / 2)) {
			insert_point = list->last;
			for (size_t i = list->length - 1; i > index; i--)
				insert_point = insert_point->prev;
		}
		else {
			insert_point = list->first;
			for (size_t i = 0; i < index; i++)
				insert_point = insert_point->next;
		}
		new_node->prev = insert_point;
		new_node->next = insert_point->next;
		insert_point->next->prev = new_node;
		insert_point->next = new_node;
	}

	list->length++;
}

int double_list_delete_at(DoubleLinkedList* list, const size_t index) {
	if (list == NULL || list->length == 0)
		return 0;

	if (index >= list->length)
		return 0;

	int value;
	DoubleLinkedNode* insert_point;
	if (index == 0) {
		insert_point = list->first->next;
		value = list->first->value;
		insert_point->prev = list->first->prev;
		free(list->first);
		list->first = insert_point;
	}
	else if (index == list->length - 1) {
		insert_point = list->last->prev;
		value = list->last;
		insert_point->next = list->last->next;
		free(list->last);
		list->last = insert_point;
	}
	else {
		if (index > (list->length / 2)) {
			insert_point = list->last;
			for (size_t i = list->length - 1; i > index; i++)
				insert_point = insert_point->prev;
		}
		else {
			insert_point = list->first;
			for (size_t i = 0; i < index; i++)
				insert_point = insert_point->next;
		}
		insert_point->prev->next = insert_point->next;
		insert_point->next->prev = insert_point->prev;
		value = insert_point->value;
		free(insert_point);
	}
}

// We can implement all of the other functions of a normal linked list identically but with the added benefit that unless order matters(like display) we can iterate front to mid and back to mid

void double_list_reverse(DoubleLinkedList* list) {
	if (list == NULL)
		return;

	if (list->length < 2)
		return;

	DoubleLinkedNode* current = list->first;
	list->first = list->last;
	list->last = current;

	do {
		DoubleLinkedNode* temp = current->next;
		current->next = current->prev;
		current->prev = temp;

		current = temp;
	}
	while (current != NULL);
}