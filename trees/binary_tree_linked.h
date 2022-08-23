#ifndef THAYBURTBINARYTREE
#define THAYBURTBINARYTREE

typedef struct _TreeNode {
	struct _TreeNode* left;
	struct _TreeNode* right;
	int value;
};

typedef struct _TreeNode TreeNode;

void init_tree_node(TreeNode* node, const int value);
TreeNode* create_tree_node(const int value);
TreeNode* create_tree(int array[], size_t array_size);

void display_preorder(TreeNode* root);
void display_inorder(TreeNode* root);
void display_postorder(TreeNode* root);
void display_preorder_iter(const TreeNode* root);
void display_inorder_iter(const TreeNode* root);
void display_postorder_iter(const TreeNode* root);
void display_level_order(const TreeNode* root);
void display_level_order_iter(const TreeNode* root);

size_t tree_height_iter(const TreeNode* root);
size_t tree_height(const TreeNode* root);
size_t tree_count_iter(const TreeNode* root);
size_t tree_count(const TreeNode* root);
size_t count_leaf_nodes(const TreeNode* root);
size_t count_leaf_nodes_iter(const TreeNode* root);

#endif