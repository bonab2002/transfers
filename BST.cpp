#include "BST.h"
//Robert Bona U85102194, Collaborator was Xinyu Lei (tllrllsa@bu.edu)
BSTNode* BST::CreateNode(int data)
{
	BSTNode* created = new BSTNode;
	created->data = data;
	created->left = nullptr;
	created->right = nullptr;
	return created;
}
BSTNode* BST::Insert(BSTNode* node, int data)
{
	BSTNode* parent = NULL;
	BSTNode* current = root;
	BSTNode* newEntry = CreateNode(data);
	if (root == nullptr)
	{
		root = newEntry;
	}
	else
	{
		while (current)
		{
			parent = current;
			if (newEntry->data < current->data)
			{
				current = current->left;
			}
			else if (newEntry->data > current->data)
			{
				current = current->right;
			}
		}
		if (newEntry->data > parent->data)
		{
			parent->right = newEntry;
		}
		else if(newEntry->data < parent->data)
		{
			parent->left = newEntry;
		}
	}
	return newEntry;
}
bool BST::Search(BSTNode* node, int data)
{
	if (node == nullptr)
	{
		return NULL;
	}
	else if (node->data == data)
	{
		return true;
	}
	else if (node->data > data)
	{
		return Search(node->left, data);
	}
	else if (node->data < data)
	{
		return Search(node->right, data);
	}
	return false;
}
int BST::CountNodes(BSTNode* root)
{
	int total = 1;
	if (root == NULL)
	{
		return 0;
	}                                                                                                                                                        
	total += CountNodes(root->right);
	total += CountNodes(root->left);
	return total;
}
void BST::CreateTree(string file)
{
	ifstream in(file);
	int data;
	if (in.is_open())
	{
		while (in >> data)
		{
			Insert(root, data);
		}
	}
	in.close();
}
int BST::treeHeight(BSTNode* root)
{
	int leftHeight, rightHeight, currentMax;
	if (root == nullptr)
	{
		return 0;
	}
	rightHeight = treeHeight(root->right);
	leftHeight = treeHeight(root->left);
	if (leftHeight > rightHeight)
	{
		currentMax = leftHeight+1;
	}
	else if (rightHeight > leftHeight)
	{
		currentMax = rightHeight+1;
	}
	return currentMax;
}
bool BST::isBalanced(BSTNode* node)
{
	int leftHeight, rightHeight;
	if (node == NULL)
	{
		return true;
	}
	rightHeight = treeHeight(node->right);
	leftHeight = treeHeight(node->left);
	if (abs(leftHeight - rightHeight) > 1)
	{
		return false;
	}
	return isBalanced(node->left) && isBalanced(node->right);
}