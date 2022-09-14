#ifndef THAYBURTLOOPEDLIST
#define THAYBURTLOOPEDLIST
#include "linked_list.h"

LinkedNode* create_looped_node(int value);
LinkedList* create_looped(int arr[], size_t size);

void display_looped_nodes(LinkedNode* node);
void display_looped(LinkedList* list);
#endif