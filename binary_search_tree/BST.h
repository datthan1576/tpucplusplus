#pragma once
class BST
{
private:
	struct node
	{
		double key;
		node* left;
		node* right;
	};
	node* root;
	void insertPrivate(double key, node*);
	void printPrivate(node*& ptr);
	void clear_all_private(node*& pnode);
	void display_tree_private(node*,int);
	int FindHeight(node* pnode);
public:
	BST();
	node* makeLeaf(double key);
	void insert(double key);
	void print();
	void clear_all();
	void display_tree();
	int height();	
};

