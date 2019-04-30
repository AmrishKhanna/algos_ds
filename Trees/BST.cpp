#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

public:
	Node(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

//
// Time Complexity: O(logn)
//
int Min(Node *root)
{
	if(root == nullptr)
		return -1;
	
	while(root->left != nullptr)
	{
		root = root->left;
	}
	
	return root->data;
}

//
// Time Complexity: O(logn)
//
int Max(Node *root)
{
	if(root == nullptr)
		return -1;
	
	while(root->right != nullptr)
	{
		root = root->right;
	}
	
	return root->data;
}

//
// For all below traversals
// Time Complexity: O(n)
// Space Complexity: O(n) as it uses internal stack due to recursion
//
void inorder_traversal(Node *root)
{
	if(root == nullptr)
		return;
	
	inorder_traversal(root->left);
	cout << root->data << " ";
	inorder_traversal(root->right);
}

void preorder_traversal(Node *root)
{
	if(root == nullptr)
		return;
	
	cout << root->data << " ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void postorder_traversal(Node *root)
{
	if(root == nullptr)
		return;
	
	postorder_traversal(root->left);
	postorder_traversal(root->right);	
	cout << root->data << " ";
}

void postorder_clear(Node *root)
{
	if(root == nullptr)
		return;
	
	postorder_clear(root->left);
	postorder_clear(root->right);	
	delete root;
}

//
// Time Complexity: O(logn)
//
Node* insert(Node* root, int data)
{
	if(root == nullptr)
	{
		root = new Node(data);
	}
	else
	{
		if(data < root->data) 
			root->left = insert(root->left, data);
		else if(data > root->data) 
			root->right = insert(root->right, data);
	}
	
	return root;
}

Node* remove(Node* root, int x)
{
	if(root == nullptr)
		return root;
	else if(x < root->data) 
		root->left = remove(root->left, x);
	else if(x > root->data) 
		root->right = remove(root->right, x);
	else
	{
		//
		// If data is equal to x there are three cases
		// 1. Leaf Node
		// 2. Node with one child
		// 3. Node with two child
		//
		if(root->left == nullptr && root->right == nullptr) //Leaf Node
		{
			delete root;
			root = nullptr;
		}
		else if(root->left == nullptr) // One Child
		{
			root->data = root->right->data;
			Node *temp = root->right;
			root->right = nullptr;
			delete temp;
		}
		else if(root->right == nullptr) // One child
		{
			root->data = root->left->data;
			Node *temp = root->left;
			root->left = nullptr;
			delete temp;
		}
		else // Two child
		{
			int min = Min(root->right);
			root->data = min;
			root->right = remove(root->right, min);
		}
	}
	
	return root;
}

//
// Time Complexity: O(logn)
//
bool search(Node *root, int x)
{
	if(root == nullptr)
		return false;
	else if(root->data == x)
		return true;
	else if(x < root->data)
		return search(root->left, x);
	else if(x > root->data)	
		return search(root->right, x);		
}

//
// Time Complexity: O(n)
// Space Complexity: O(n)
//
void dfs_traversal_iterative(Node *root)
{
	if(root == nullptr)
		return;
	
	Node *curr = root;
	stack<Node *> s;
	
	while(!s.empty() || curr != nullptr)
	{
		if(curr == nullptr)
		{
			curr = s.top();
			s.pop();
			cout << curr->data << " ";
			curr = curr->right;
		}
		else
		{
			s.push(curr);
			curr = curr->left;
		}
	}
}

//
// Time Complexity: O(n)
// Space Complexity: O(n)
//
void bfs_traversal_iterative(Node *root)
{
	if(root == nullptr)
		return;
	
	Node *curr = root;
	queue<Node *> q;
	q.push(curr);
	
	while(!q.empty())
	{
		Node *top = q.front();
		cout << top->data << " ";
		q.pop();
		
		if(top->left) 
			q.push(top->left);
		if(top->right)
			q.push(top->right);
	}
}

//
// Time Complexity: O(n)
// Space complexity: O(n) because of recursion
//
bool isBST_util(Node* root, int min, int max)
{
	if(root == nullptr)
		return true;
	else if( root->data > min 
			&& root->data < max 
			&& isBST_util(root->left, min, root->data)
			&& isBST_util(root->right, root->data, max))
				return true;
	else
		return false;
}

bool isBST(Node *root)
{
	if(root == nullptr)
		return true;
	else
		return isBST_util(root, INT_MIN, INT_MAX);
}

bool isBST_alternate_util(Node* root, Node* l, Node* r)
{
	if(root == nullptr)
		return true;
	else if(l && l->data > root->data)
		return false;
	else if(r && r->data < root->data)
		return false;
	else return isBST_alternate_util(root->left, l, root)
			&& isBSisBST_alternate_utilT_util(root->right, root, r)
}

bool isBST_alternate(Node *root)
{
	if(root == nullptr)
		return true;
	else
		return isBST_alternate_util(root, nullptr, nullptr);
}

//
// Time Complexity: O(n)
// Space Complexity: O(n) as it uses internal stack due to recursion
//
int Height(Node *root)
{
	if(root == nullptr)
		return 0;
	else
		return max(Height(root->left), Height(root->right))+1;
}

//
// Balance a BST
// 1. Do inorder traversal
// 2. Do binary search and build the Balances BST with pre-order approch
//

void getInorderBSTArray(Node *root, vector<Node *> &nodes)
{
	if(root == nullptr)
		return;
	
	getInorderBSTArray(root->left, nodes);
	nodes.push_back(root);
	getInorderBSTArray(root->right, nodes);
}

Node* buildBalancedBSTUtil(vector<Node *> &nodes, int start, int end)
{
	if(start > end)
		return nullptr;
	
	int mid = (start+end)/2;
	Node *root = nodes[mid];
	
	root->left = buildBalancedBSTUtil(nodes, start, mid-1);
	root->right = buildBalancedBSTUtil(nodes, mid+1, end);
	
	return root;	
}	

Node* buildBalancedBST(Node *root){
	//
	// Balancing BST
	//
	cout << "\nPreorder Before Balancing\n";
	preorder_traversal(root);
	
	vector<Node *> nodes;
	getInorderBSTArray(root, nodes);
	
	root = buildBalancedBSTUtil(nodes, 0, nodes.size()-1);
	
	cout << "\nPreorder After Balancing\n";
	preorder_traversal(root);
	
	cout << "\nBST Validation\n";
	if(isBST(root))
		cout << "It is BST\n";
	else
		cout << "It is not BST\n";
	
	return root;
}

//
// isBalancedBST
//
int isBalancedBST(Node* root)
{
	if(root == nullptr)
		return 0;
	
	int left_height = isBalancedBST(root->left);
	if(left_height == -1)
		return -1;
	
	int right_height = isBalancedBST(root->right);
	if(right_height == -1)
		return -1;
	
	if(abs(left_height-right_height) > 1)
		return -1;
	
	return 1+(max(left_height, right_height));
}

int main()
{
	Node *root = nullptr;
	//
	// Insertion
	//
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 6);
	root = insert(root, 5);
	root = insert(root, 7);
	
	//
	// Traversals
	//
	cout << "\nInorder Traversal\n";
	inorder_traversal(root);
	cout << "\nPreorder Traversal\n";
	preorder_traversal(root);
	cout << "\nPostorder Traversal\n";	
	postorder_traversal(root);	
	cout << "\nDFS Iterative Traversal\n";
	dfs_traversal_iterative(root);
	cout << "\nBFS Iterative Traversal\n";
	bfs_traversal_iterative(root);
	
	cout << "\nMinimum in BST\n";
	cout << Min(root);
	
	cout << "\nMaximum in BST\n";
	cout << Max(root);
	
	root = insert(root, 10);
	cout << "\nMaximum height of BST\n";
	cout << Height(root);
	
	cout << "\nSearch in BST\n";
	if(search(root, 7))
		cout << "Found 7 in BST\n";
	else
		cout << "Not Found 7 in BST\n";
	
	if(search(root, 9))
		cout << "Found 9 in BST\n";
	else
		cout << "Not Found 9 in BST\n";
	
	cout << "\nBST Validation\n";
	if(isBST(root))
		cout << "It is BST\n";
	else
		cout << "It is not BST\n";
	
	if(isBalancedBST(root) < 0)
		cout << "Not balanced BST\n";
	else
		cout << "Is Balanced BST\n";
	
	//
	// Deleting nodes
	//
	cout << "\nBefore removal\n";
	inorder_traversal(root);
	root = remove(root, 7); // one child removal
	cout << "\nAfter removing 7\n";
	inorder_traversal(root);
	root = remove(root, 4); // two child removal
	cout << "\nAfter removing 4\n";
	inorder_traversal(root);
	root = remove(root, 1); // leaf node removal
	cout << "\nAfter removing 1\n";
	inorder_traversal(root);
	
	cout << "\nBST Validation\n";
	if(isBST(root))
		cout << "It is valid BST\n";
	else
		cout << "It is not valid BST\n";
	
	//
	// Balance BST
	//
	Node* root1 = new Node(10);
	root1->left = new Node(8);
	root1->left->left = new Node(7);
	root1->left->left->left = new Node(6);
	root1->left->left->left->left = new Node(5);

	//
	// Check if it is balanced
	//
	if(isBalancedBST(root1) < 0){
		cout << "Not Balanced tree. Balancing now.....\n";
		root1 = buildBalancedBST(root1);
	}
	else
		cout << "Already balanced Tree\n";
	
	//
	// Memory Management to clear memory allocated for BST
	//
	postorder_clear(root);
	
	
	return 0;
}