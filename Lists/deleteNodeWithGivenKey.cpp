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
// Time complexity: O(n)
// Space complexity: O(1)
//
Node* deleteNode(Node* head, int d)
{
	if(head == nullptr)
	{
		cout << "\nEmpty list. Nothing to delete.\n";
		return head;
	}
	
	Node* curr = head;
	Node* prev = nullptr;
	while(curr)
	{
		if(curr->data == d)
		{
			Node* temp = curr;
			if(prev == nullptr)
			{
				head = curr->next;
				curr = head;
			}
			else
			{
				prev->next = curr->next;
				curr = prev->next;
			}
			delete temp;
			continue;
		}
		prev = curr;
		curr = curr->next;
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
	head = insert(head, 4);
	head = insert(head, 0);
	
	display(head);
	
	cout << "\nDeleting node with key 4... \n";
	head = deleteNode(head, 4);
	display(head);
	
	cout << "\nDeleting node with key 7... \n";
	head = deleteNode(head, 7);
	display(head);
	
	cout << "\nDeleting node with key 0... \n";
	head = deleteNode(head, 0);
	display(head);
	
	cout << "\nDeleting node with key 10... \n";
	head = deleteNode(head, 10);
	display(head);
	
	return 0;	
}