#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	
	Node(int d)
	{
		data = d;
		next = nullptr;
	}
};

//
// Time complexity : O(n)
// Space complexity : O(n)
//

void deleteDuplicateWithBuffer(Node *head)
{
	if (head == nullptr)
		return;
	
	Node* prev = nullptr;
	unordered_set<int> s; // O(1) operation due to hashing
	
	while(head)
	{
		if(s.find(head->data) == s.end()) // not in set
		{
			s.insert(head->data);
			prev = head;
			head = head->next;
		}
		else // is in set so duplicate. delete it
		{
			Node* temp = head;
			prev->next = head->next;
			head = head->next;
			delete temp;
		}
	}
}

//
// Time complexity : O(n2)
// Space complexity : O(1)
//
void deleteDuplicateWithNoBuffer(Node *head)
{
	if (head == nullptr)
		return;
	
	Node *runner = nullptr;
	Node *prev = nullptr;
	
	while(head)
	{
		runner = head->next;
		prev = head;
		while(runner)
		{
			if(head->data == runner->data)
			{
				Node *temp = runner;
				runner = runner->next;
				prev->next = runner;
				delete temp;
			}
			prev = runner;
			runner = runner->next;
		}
		head = head->next;
	}	
}

void display(Node *head)
{
	if(head == nullptr)
		return;
	
	cout << "List elements:\n";
	while(head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(2);
	head->next->next->next->next = new Node(4);
	head->next->next->next->next->next = new Node(2);
	head->next->next->next->next->next->next = new Node(5);
	
	display(head);
	deleteDuplicateWithBuffer(head);
	display(head);
	
	Node *head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(2);
	head1->next->next->next->next = new Node(4);
	head1->next->next->next->next->next = new Node(2);
	head1->next->next->next->next->next->next = new Node(5);
	
	display(head1);
	deleteDuplicateWithNoBuffer(head1);
	display(head1);
	
	return 0;
}