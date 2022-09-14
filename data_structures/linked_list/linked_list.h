#ifndef THAYBURTLINKEDLIST
#define THAYBURTLINKEDLIST
#include <stddef.h>

struct _LinkedNode {
	int value;
	struct _LinkedNode* next;
};
typedef struct _LinkedNode LinkedNode;

typedef struct {
	LinkedNode* first;
	LinkedNode* last;
	size_t length;
} LinkedList;

LinkedList* create_list(int numbers[], size_t size);
LinkedNode* create_node(const int value);

void display_list(const LinkedList* root);
void display_node(const LinkedNode* node);

size_t count_list(LinkedList* list);
size_t count_nodes(LinkedNode* start);

long int sum_list(const LinkedList* list);
long int sum_nodes(LinkedNode* start);


int max_node(const LinkedNode* start);
int max_list(const LinkedList* list);

LinkedNode* search_from(LinkedNode* start, const int key);
LinkedNode* search(const LinkedList* list, const int key);

void insert(LinkedList* list, const size_t index, const int value);
void insert_sorted(LinkedList* list, const int value);
void append(LinkedList* list, const int value);
void prepend(LinkedList* list, const int value);

void delete_at(LinkedList* list, const size_t index);
void delete_first(LinkedList* list, const int value);
void delete_all(LinkedList* list, const int value);

int is_chain_sorted(LinkedNode* root);
int is_sorted(const LinkedList* list);
int is_looped(LinkedList* list);

void remove_sorted_duplicates(LinkedList* list);
void reverse(LinkedList* list);

void concate(LinkedList* list, LinkedList* other);
void merge(LinkedList* list, LinkedList* other);
#endif