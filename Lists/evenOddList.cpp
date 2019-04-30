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
		next = nullptr;
	}
};

Node* insert(Node* head, int d)
{
	if(head == nullptr)
	{
		head = new Node(d);
	}
	else
	{
		Node *newNode = new Node(d);
		newNode->next = head;
		head = newNode;
	}
	return head;
}

void display(Node* head)
{
	if(head == nullptr)
		return;
	
	cout << "List elements" << endl;
	while(head)
	{
		cout << head->data << " "; 
		head = head->next;
	}
	cout << endl ;
}

pair<Node*, Node*> separateOddEvenList(Node *head)
{
	pair<Node*, Node*> p;
	p = make_pair(nullptr, nullptr);
	
	if(head == nullptr)
		return p;
	
	bool swap = true;
	Node *oddHead = head,
		 *evenHead = head->next,
		 *odd = oddHead,
		 *even = evenHead,
		 *curr = head->next->next;
		 
	while(curr && curr->next)
	{
		odd->next = curr;
		even->next = curr->next;
		
		odd = odd->next;
		even = even->next;
		
		if(curr->next->next)
			curr = curr->next->next;
		else
		{
			odd->next = nullptr;
			even->next = nullptr;
		}
	}
	
	//
	// Last remaining odd element to add
	//
	if(curr!= nullptr && curr->next == nullptr )
	{
		odd->next = curr;
		odd->next->next = nullptr;
		even->next = nullptr;
	}
	
	p.first = oddHead;
	p.second = evenHead;
	return p;
}

int main()
{
	Node *head = nullptr;
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
	
	pair<Node*, Node*> pHead = separateOddEvenList(head);
	display(pHead.first);
	display(pHead.second);

	return 0;
}