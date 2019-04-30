#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int binarySearchRecursive(vector<int>& v, int x, int l, int r)
{
	if(l>r) return -1;
	
	int m = l+(r-l)/2;
	
	if(v[m] > x) 
		return binarySearchRecursive(v, x, l, m-1);
	else if(v[m] < x) 
		return binarySearchRecursive(v, x, m+1, r);
	else 
		return 1;
}

void binarySearch(vector<int>& v, int x)
{
	if(binarySearchRecursive(v, x, 0, v.size()-1))
	{
		cout << "Element " << x << " Found" << endl;
	}
	else
	{
		cout << "Element " << x << " Not found" << endl;
	}
}

int binarySearchIterative(vector<int>& v,int x)
{
	int l = 0, 
		r = v.size();	
	
	while(l<=r){
		int m = l+(r-l)/2;
		if(v[m] > x) 
			r = m-1;
		else if(v[m] < x) 
			l = m+1;
		else 
			return 1;
	}
	return -1;
}

void binarySearchITR(vector<int>& v, int x)
{
	if(binarySearchIterative(v, x))
	{
		cout << "Element " << x << " Found" << endl;
	}
	else
	{
		cout << "Element " << x << " Not found" << endl;
	}
}

int main()
{
	vector<int> v = {5, 7, 9, 11, 6, 3, 1, 2};
	sort(v.begin(), v.end());
	
	//
	// Time Complexity: O(log n)
	// Space Complexity: O(log n)
	//
	cout << "Recursive Method:" << endl;
	binarySearch(v, 9);
	binarySearch(v, 3);
	binarySearch(v, 10);
	binarySearch(v, 1);
	
	//
	// Time Complexity: O(log n)
	// Space Complexity: O(1)
	//
	cout << endl << "Iterative Method:" << endl;
	binarySearchITR(v, 9);
	binarySearchITR(v, 3);
	binarySearchITR(v, 10);
	binarySearchITR(v, 1);
	
	return 0;
}