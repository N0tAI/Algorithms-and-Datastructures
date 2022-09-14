#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void display_node(const LinkedNode* node) {
	if (node != NULL) {
		printf("%d ", node->value);
		display_node(node->next);
	}
}
void display_list(const LinkedList* list) {
	display_node(list->first);
}

LinkedNode* create_node(const int value) {
	LinkedNode* node = (LinkedNode*)malloc(sizeof(LinkedNode));
	if (node != NULL) {
		node->value = value;
		node->next = NULL;
	}
	return node;
}
LinkedList* create_list(int numbers[], const size_t size) {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

	if (size > 0 && list != NULL) {
		LinkedNode* current = create_node(numbers[0]);
		current->value = numbers[0];
		list->first = current;
		list->length++;
		{
			size_t i = 1;
			for (; i < size; i++) {
				LinkedNode* temp = create_node(numbers[i]);
				if (temp == NULL) {
					return list;
				}
				current->next = temp;
				current = temp;
			}
			list->length = i;
		}
		list->last = current;
		if (list->first != list->last)
			list->length++;

	}
	return list;
}

size_t count_nodes(LinkedNode* start) {
	size_t count = 0;
	LinkedNode* current = start;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}
size_t count_list(LinkedList* list) {
	return list->length;
}

long int sum_nodes(LinkedNode* start) {
	long int sum = 0;
	LinkedNode* current = start;
	while (current != NULL) {
		sum += current->value;
		current = current->next;
	}
	return sum;
}
long int sum_list(const LinkedList* list) {
	return sum_nodes(list->first);
}

int max_node(const LinkedNode* start) {
	int max = start->value;
	LinkedNode* current = start->next;
	while (current != NULL) {
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return max;
}
int max_list(const LinkedList* list) {
	return max_node(list->first);
}

LinkedNode* search_from(LinkedNode* start, const int key) {
	LinkedNode* current = start;
	while (current != NULL) {
		if (current->value == key)
			break;
		current = current->next;
	}
	return current;
}
LinkedNode* search(const LinkedList* list, const int key) {
	return search_node(list->first, key);
}

void insert(LinkedList* list, const size_t index, const int value) {
	if (index > list->length)
		return;

	LinkedNode* new_node = create_node(value);
	if (new_node == NULL)
		return;

	if (index == 0) {
		new_node->next = list->first;
		list->first = new_node;
		if (list->last == NULL)
			list->last = new_node->next;
	}
	// in this case last will always be instantiated because length > 0 to get here (assuming no outside tampering with the structure)
	else if (index == list->length) {
		list->last->next = new_node;
		list->last = new_node;
	}
	else {
		LinkedNode* current = list->first;
		for (size_t i = 0; i < (index - 1); i++)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
	list->length++;
}
void append(LinkedList* list, const int value) {
	insert(list, list->length, value);
}
void prepend(LinkedList* list, const int value) {
	insert(list, 0, value);
}
void insert_sorted(LinkedList* list, const int value) {
	LinkedNode* new_node = create_node(value);

	if (new_node == NULL)
		return;

	if (list->first == NULL || list->first->value > value)
		prepend(list, value);
	else if (list->last->value < value)
		append(list, value);
	else {
		LinkedNode* current = list->first;
		LinkedNode* prev = NULL;
		while (current != NULL && current->value < value) {
			prev = current;
			current = prev->next;
		}
		prev->next = new_node;
		new_node->next = current;
		list->length++;
	}
}

void delete_at(LinkedList* list, const size_t index) {
	if (list->length == 0 || index >= list->length)
		return;

	if (index == 0) {
		LinkedNode* temp = list->first->next;
		if (list->last == list->first)
			list->last = temp;
		free(list->first);
		list->first = temp;
	}
	else {
		LinkedNode* current = list->first;
		LinkedNode* prev = NULL;
		for (size_t i = 1; i < (list->length - 1); i++) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		free(current);
	}
	list->length--;
}
// TODO Implement these knowing how to delete_at (shouldn't be that different)
void delete_first(LinkedList* list, const int value) {

}
void delete_all(LinkedList* list, const int value) {

}

int is_chain_sorted(LinkedNode* root) {
	LinkedNode* current = root;
	while (current->next != NULL) {
		if (current->next->value < current->value)
			return 1;
	}
	return 0;
}
int is_sorted(const LinkedList* list) {
	return is_chain_sorted(list->first);
}

void remove_sorted_duplicates(LinkedList* list) {
	if (list->first == NULL)
		return;
	LinkedNode* current = list->first;
	while (current->next != NULL) {
		if (current->value == current->next->value) {
			LinkedNode* delete_node = current->next;
			current->next = delete_node->next;
			free(delete_node);
			list->length--;
		}
		current = current->next;
	}
}

void reverse(LinkedList* list) {
	LinkedNode* next = list->first;
	LinkedNode* current = NULL;
	LinkedNode* prev = NULL;

	while (next != NULL) {
		prev = current;
		current = next;
		next = next->next;

		current->next = prev;
	}
}

void concate(LinkedList* list, LinkedList* other) {
	list->last->next = other->first;
	list->last = other->last;
	list->length += other->length;
}
void merge(LinkedList* list, LinkedList* other) {
	LinkedNode* list_node = list->first;
	LinkedNode* other_node = other->first;
	LinkedNode* last = NULL;

	if (list_node->value < other_node->value) {
		last = list_node;
		list_node = list_node->next;
		last->next = NULL;
	}
	else {
		last = other_node;
		other_node = other_node->next;
		last->next = NULL;
	}
	while (list_node != NULL && other_node != NULL) {
		if (list_node->value < other_node->value) {
			last->next = list_node;
			last = list_node;
			list_node = list_node->next;
			last->next = NULL;
		}
		else {
			last->next = other_node;
			last = other_node;
			other_node = other_node->next;
			last->next = NULL;
		}
	}
	if (list_node != NULL) {
		last->next = list_node;
	}
	else if (other_node != NULL)
		last->next = other_node;
}

int is_looped(LinkedList* list) {
	if (list->first == NULL)
		return 0;
	LinkedNode* slow = list->first;
	LinkedNode* fast = slow->next;
	while (fast != NULL) {
		if (slow == fast)
			return 1;
		slow = slow->next;
		fast = fast->next;
		fast = (fast != NULL ? fast->next : fast);
	}
	return 0;
}