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
// Time complexity : O(nlogn)
// Space complexity: O(logn)
//

pair<Node*, Node*> divide_lists(Node* head)
{
	if(head == nullptr)
		return make_pair(nullptr, nullptr);
	
	Node *first, *second;
	if(head->next == nullptr)
	{
		first = head;
		second = nullptr;
		return make_pair(first, second);
	}
	
	Node* curr = head;
	Node* runner = head;
	while(runner)
	{
		runner = runner->next;
		if(runner)
		{
			curr = curr->next;
			runner = runner->next;
		}
	}
	
	second = curr->next;
	curr->next = nullptr;
	first = head; 
	
	return make_pair(first, second);
}

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

Node* mergeSort(Node *head)
{
	if(head == nullptr || head->next== nullptr)
		return head;
	
	pair<Node*, Node*> p = divide_lists(head);
	
	p.first = mergeSort(p.first);
	p.second = mergeSort(p.second);

	return mergeLists(p.first, p.second);
}

int main()
{
	Node* head = nullptr;
	head = insert(head, 10);
	head = insert(head, 8);
	head = insert(head, 6);
	head = insert(head, 4);
	head = insert(head, 2);
	head = insert(head, 9);
	head = insert(head, 7);
	head = insert(head, 5);
	head = insert(head, 3);
	head = insert(head, 1);
	
	cout << "\nElements in the unsorted list : \n";
	display(head);
	
	cout << "\nElements in sorted list : \n";
	Node* res = mergeSort(head);
	display(res);
	
	return 0;
}