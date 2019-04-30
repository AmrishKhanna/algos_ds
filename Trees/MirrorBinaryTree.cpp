#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

    Node(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}	
};

bool isMirrorUtil(Node* rootA, Node* rootB)
{
	if(rootA == nullptr && rootB == nullptr)
		return true;
	
	if(rootA && rootB && rootA->data == rootB->data)
		return isMirrorUtil(rootA->left, rootB->right) 
				&& isMirrorUtil(rootA->right, rootB->left);
	
	return false;
}


bool isMirror(Node* rootA, Node* rootB)
{
	return isMirrorUtil(rootA, rootB);
}

bool isSelfMirror(Node* root)
{
	return isMirrorUtil(root, root);
}

int main()
{
	//
	// Creating two Mirror Binary Tree
	//	
	Node *rootA = new Node(1);
	rootA->left = new Node(2);
	rootA->left->left = new Node(3);
	rootA->left->right = new Node(4);
	
	rootA->right = new Node(5);
	rootA->right->left = new Node(6);
	rootA->right->right = new Node(7);
	
	Node *rootB = new Node(1);
	rootB->left = new Node(5);
	rootB->left->left = new Node(7);
	rootB->left->right = new Node(6);
	
	rootB->right = new Node(2);
	rootB->right->left = new Node(4);
	rootB->right->right = new Node(3);
    
	if(isMirror(rootA, rootB))
		cout << "\nIs Mirror";
	else
		cout << "\nIs not Mirror";
	
	Node *root        = new Node(1);
    root->left        = new Node(2);
	root->left->left  = new Node(3);
    root->left->right = new Node(4);
	
    root->right       = new Node(2);
    root->right->left  = new Node(4);
    root->right->right = new Node(3);

    if(isSelfMirror(root))
		cout << "\nIs Mirror";
	else
		cout << "\nIs not Mirror";
	return 0;
}