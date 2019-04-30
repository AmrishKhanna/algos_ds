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
Node* reverseList(Node* head)
{
	if(head == nullptr)
		return head;
	
	Node* prev = nullptr;
	Node* curr = head;
	Node* nxt = nullptr;;
	
	while(curr)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	
	head = prev;
	return head;
}

//
// Time complexity: O(n)
// Space complexity: O(n)
//
void reverseList_recursive(Node** head)
{
	if (*head == nullptr)
		return;
	
	Node* first = *head;
	Node* rest = first->next;
	
	if (rest == nullptr)
		return;
	
	reverseList_recursive(&rest);
	first->next->next = first;
	first->next = nullptr;
	
	*head = rest;
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
	cout << "\nReversing List... \n";
	head = reverseList(head);
	display(head);
	
	cout << "\nReversing List... \n";
	reverseList_recursive(&head);
	display(head);
	return 0;
}