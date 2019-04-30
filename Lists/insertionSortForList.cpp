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
// Time complexity: O(n^2)
// Space complexity: O(1)
//
Node* insertionSort(Node* head)
{
	if(head == nullptr || head->next == nullptr)
		return head;
	
	Node* sorted = nullptr;
	
	while(head)
	{
		Node* newNode = new Node(head->data);
		if(sorted == nullptr)
		{
			sorted = newNode;
		}
		else
		{
			Node* curr = sorted;
			Node* prev = nullptr;
			while(curr)
			{
				if(curr->data >= newNode->data)
				{
					newNode->next = curr;
					if(prev)
					{
						prev->next = newNode;
					}
					else
					{
						sorted = newNode;
					}
					break;
				}
				prev = curr;
				curr = curr->next;
			}
				
		}
	
		head = head->next;
	}
	return sorted;
}

int main()
{
	Node* head = nullptr;
	head = insert(head, 0);
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 6);
	head = insert(head, 7);
	head = insert(head, 8);
	head = insert(head, 9);
	head = insert(head, 10);
	
	display(head);
	
	cout << "\nAfter Insertion Sort... \n";
	Node *sorted = insertionSort(head);
	display(sorted);
}