#ifndef THAYBURTBINARYTREE
#define THAYBURTBINARYTREE

typedef struct tree_node {
	struct tree_node* left;
	struct tree_node* right;
	void* value;
};

typedef struct tree_node tree_node_t;

void init_tree_node(tree_node_t* node, const void* value);
tree_node_t* create_tree_node(const void* value);
tree_node_t* create_tree(void* array[], size_t array_size);

void display_preorder(tree_node_t* root);
void display_inorder(tree_node_t* root);
void display_postorder(tree_node_t* root);
void display_preorder_iter(const tree_node_t* root);
void display_inorder_iter(const tree_node_t* root);
void display_postorder_iter(const tree_node_t* root);
void display_level_order(const tree_node_t* root);
void display_level_order_iter(const tree_node_t* root);

size_t tree_height_iter(const tree_node_t* root);
size_t tree_height(const tree_node_t* root);
size_t tree_count_iter(const tree_node_t* root);
size_t tree_count(const tree_node_t* root);
size_t count_leaf_nodes(const tree_node_t* root);
size_t count_leaf_nodes_iter(const tree_node_t* root);

#endif