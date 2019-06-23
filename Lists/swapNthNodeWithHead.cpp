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
Node* swapNthNodeWithHead(Node* head, int k)
{
	if(head == nullptr || k <= 1)
		return head;
	
	Node* curr = head;
	Node* prev = nullptr;
	--k;
	
	while(curr && k > 0)
	{
		prev = curr;
		curr = curr->next;
		--k;
	}
	
	if(curr) {
		Node *temp = head->next;
		head->next = curr->next;
		curr->next = temp;
		prev->next = head;
		
		head = curr;
		temp = nullptr;
	}
	return head;
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

	cout << "\nSwapping element at 3rd position ... \n";
	head = swapNthNodeWithHead(head, 3);
	display(head);
	
	cout << "\nSwapping element at 6th position ... \n";
	head = swapNthNodeWithHead(head, 6);
	display(head);	
	
	cout << "\nSwapping element at 12th position ... \n";
	head = swapNthNodeWithHead(head, 12);
	display(head);	
	
	return 0;
}