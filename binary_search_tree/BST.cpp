#include "BST.h"
#include<iostream>
#include<limits>
//constructor
BST::BST() 
{
	root = nullptr;
}

//make new Leaf
BST::node* BST::makeLeaf(double key)
{
	node* n = new node;
	n->key = key;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

//interface insert
void BST::insert(double key)
{
	insertPrivate(key,root);
}

//private insert
void BST::insertPrivate(double key,node* pnode)
{
	if (pnode == nullptr)
	{
		root = makeLeaf(key);
	}
	else if (key < pnode->key)
	{
		if (pnode->left != nullptr)
		{
			insertPrivate(key, pnode->left);
		}
		else
		{
			pnode->left = makeLeaf(key);
		}
	}
	else if (key > pnode->key)
	{
		if (pnode->right != nullptr)
		{
			insertPrivate(key, pnode->right);
		}
		else
		{
			pnode->right = makeLeaf(key);
		}
	}
	else
	{
		std::cout << "The key " << key << " has already been added to the tree!"<<std::endl;
	}
}

//interface print 
void BST::print() 
{
	printPrivate(root);
}

//private print
void BST::printPrivate(node*& pnode)
{
	if (root != nullptr)
	{
		if (pnode->left != nullptr)
		{
			printPrivate(pnode->left);
		}
		std::cout << pnode->key << "   ";
		if (pnode->right != nullptr)
		{
			printPrivate(pnode->right);
		}
	}
	else
	{
		std::cout << "The tree is empty!" << std::endl;
	}
}

//interface clear
void BST::clear_all()
{
	this->clear_all_private(root);
}

//private clear
void BST::clear_all_private(node*& pnode)
{
	if (pnode != nullptr)
	{
		clear_all_private(pnode->left);
		clear_all_private(pnode->right);
		delete pnode;
		pnode = nullptr;
	}
}

//interface display 
void BST::display_tree()
{
	this->display_tree_private(root, 1);
}

// display
void BST::display_tree_private(node* pnode, int level)
{
	int i;
	if (pnode != nullptr)
	{
		display_tree_private(pnode->right, level + 1);
		std::cout << std::endl;
		if (pnode == root)
			std::cout << "       Root-> ";
		else
		{
			for (i = 0; i < level; i++)
				std::cout << "             ";
		}
		std::cout << pnode->key << "(" << level << ")";
		display_tree_private(pnode->left, level + 1);
	}
}

//interface height
int BST::height()
{
	return this->FindHeight(this->root);
}

//find height private
int BST::FindHeight(node* root)
{
	if (root == nullptr)
		return 0;
	else
	{
		int lb = FindHeight(root->left);
		int rb = FindHeight(root->right);
		return (lb>rb?lb:rb) + 1;
	}
}