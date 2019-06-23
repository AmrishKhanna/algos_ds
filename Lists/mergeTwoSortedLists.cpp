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
	
	while(head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;	
}

//
// Time complexity : O(m+n) where m and n are length of lists
// Space complexity: O(1)
//
Node* mergeLists(Node* head1, Node* head2)
{
	if(!head1 && !head2)
		return nullptr;
	else if(!head1 && head2)
		return head2;
	else if(!head2 && head1)
		return head1;
	
	Node* reshead = nullptr;
	Node* result = nullptr;
	Node* curr1 = head1;
	Node* curr2 = head2;
	
	while(curr1 && curr2)
	{
		if(curr1->data > curr2->data){
			if(result == nullptr){
				result = curr2;
				reshead = curr2;
			}
			else{
				result->next = curr2;
				result = result->next;
			}
			curr2 = curr2->next;
		}
		else
		{
			if(result == nullptr){
				result = curr1;
				reshead = curr1;
			}
			else{
				result->next = curr1;
				result = result->next;
			}
			curr1 = curr1->next;
		}
	}

	while(curr1)
	{
		result->next = curr1;
		result = result->next;
		curr1 = curr1->next;
	}
	
	while(curr2)
	{
		result->next = curr2;
		result = result->next;
		curr2 = curr2->next;
	}
	
	return reshead;		
}

int main()
{
	Node* head1 = nullptr;
	head1 = insert(head1, 10);
	head1 = insert(head1, 8);
	head1 = insert(head1, 6);
	head1 = insert(head1, 4);
	head1 = insert(head1, 2);
	
	Node* head2 = nullptr;
	head2 = insert(head2, 9);
	head2 = insert(head2, 7);
	head2 = insert(head2, 5);
	head2 = insert(head2, 3);
	head2 = insert(head2, 1);
	
	cout << "\nElements in first sorted list : \n";
	display(head1);
	
	cout << "\nElements in second sorted list : \n";
	display(head2);

	cout << "\nElements in sorted merged list : \n";
	Node* result = mergeLists(head1, head2);
	display(result);
	
	return 0;
}