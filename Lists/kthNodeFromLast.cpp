#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	
	Node(int d)
	{
		data = d;
		next =  nullptr;
	}
};

Node* insert(Node* head, int d)
{
	Node* newNode = new Node(d);
	if(head==nullptr)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	
	return head;
}

void display(Node* head)
{
	if(head == nullptr)
		return;
	
	cout << "\nElement in Lists : \n";
	while(head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;	
}

//
// Time complexity : O(n)
// Space complexity: O(1)
//
Node* getKthNode(Node* head, int k)
{
	if(head == nullptr)
		return head;
	
	//
	// We can traverse with two pointers
	//
	Node *curr = head;
	Node *runner = head;
	
	while(k>0)
	{
		if(runner->next) 
			runner = runner->next;
		else 
			return nullptr;
		--k;
	}
	
	while(runner)
	{
		runner = runner->next;
		curr = curr->next;
	}
	
	return curr;
}

int main()
{
	Node* head = nullptr;
	head = insert(head, 10);
	head = insert(head, 9);
	head = insert(head, 8);
	head = insert(head, 7);
	head = insert(head, 6);
	head = insert(head, 5);
	head = insert(head, 4);
	head = insert(head, 3);
	head = insert(head, 2);
	head = insert(head, 1);
	head = insert(head, 0);
	
	display(head);
	cout << "\Getting kth element from above list... \n";
	cout << "Element at 3rd position from last is " << (getKthNode(head, 3))->data << endl;
	cout << "Element at 8th position from last is " << (getKthNode(head, 8))->data << endl;
	if(!(getKthNode(head, 11)))
		cout << "Element at 11th position from last is null" << endl;
	
	return 0;
}