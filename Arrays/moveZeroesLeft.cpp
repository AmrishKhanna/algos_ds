#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

//
// Two pointers approach
// Time complexity: O(n)
// Space complexity: O(1)
//
void moveZeroesLeft(vector<int>& v)
{
	if(v.size() == 0)
		return;
	
	int l = v.size()-1;
	int r = v.size()-1;
	
	while(l>=0 && r>=0)
	{
		if(v[l] == 0)
		{
			--l;
		}
		else
		{
			int tmp = v[l];
			v[l] = v[r];
			v[r] = tmp;
			
			--l;
			--r;
		}
		
	}
}

//
// Another approach is to use queue of size equal to number of zeroes in array
// Time complexity: O(n)
// Space complexity: O(k) if k is no of zeroes in array
//
void moveZeroesLeftQueue(vector<int>& v)
{
	if(v.size() == 0)
		return;
	
	int k = 0;
	for(int x: v)
	{
		if(x == 0)
			k++;
	}
	
	deque<int> q;
	
	//
	// Get first k element and put in q
	//
	for( int i = 0; i< k; i++)
	{
		q.push_back(v[i]);
	}
	
	//
	// Update first k element with 0
	//
	for(int i = 0; i< k; i++)
	{
		v[i] = 0;
	}
	
	for(int i = k; i < v.size() ; i++)
	{
		if(v[i] == 0)
		{
			v[i] = q.front();
			q.pop_front();
		}
		else
		{
			q.push_back(v[i]);
			v[i] = q.front();
			q.pop_front();
		}
	}
	
}

int main()
{
	vector<int> v1 = { 16, 2, 0, 2, 0, 10, 0, 0, 77, 40, 12071 };
	
	cout << "Input array :" << endl;
	for (int x : v1)
		cout << x << " ";
	cout << endl << endl;
	
	moveZeroesLeft(v1);
	
	cout << "Input array after moving zeroes to left:" << endl;
	for (int x : v1)
		cout << x << " ";
	cout << endl << endl;
	
	vector<int> v2 = { 1, 10, 20, 0, 59, 63, 0, 88, 0 };
	
	cout << "Input array :" << endl;
	for (int x : v2)
		cout << x << " ";
	cout << endl << endl;
	
	moveZeroesLeftQueue(v2);
	
	cout << "Input array after moving zeroes to left:" << endl;
	for (int x : v2)
		cout << x << " ";
	cout << endl << endl;
	
	return 0;
}