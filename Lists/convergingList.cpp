#include <iostream>
#include <algorithm>

using namespace std;

class Node{
public:
	int data;
	Node *next;
	
	Node(int d)
	{
		data=d;
		next = nullptr;
	}
};

Node* convergePoint(Node* headA, Node* headB)
{
	if(headA == nullptr || headB == nullptr)
		return nullptr;
	
	Node* hA = headA, *hB = headB;
	int l1 = 0, l2 = 0;
	
	while(hA)
	{
		l1++;
		hA = hA->next;
	}

	while(hB)
	{
		l2++;
		hB = hB->next;
	}

	hA = headA;
	hB = headB;
	int d = abs(l1-l2);

	while(d>0){
		if(l1 > l2)
		{
			hA = hA->next;
		}
		else
		{
			hB = hB->next;
		}
		d--;
	}

	while(hA && hB){
		if(hA->data == hB->data)
			return hA;
		hA = hA->next;
		hB = hB->next;
	}

	return nullptr;
}

int main()
{
	Node* headA = new Node(4);
	Node* headB = new Node(5);
	
	headA->next = new Node(3);
	headA->next->next = new Node(2);
	headA->next->next->next = new Node(1);
	headA->next->next->next->next = new Node(0);
	
	headB->next = new Node(6);
	headB->next->next = new Node(7);
	headB->next->next->next = new Node(7);
	headB->next->next->next->next = headA->next->next->next; //converged
	headB->next->next->next->next->next = headA->next->next->next->next;
	
	Node *converge = convergePoint(headA, headB);
	if(converge)
		cout << "Converging at " << converge->data;
	else
		cout << "Does not converge";
	
	return 0;
}