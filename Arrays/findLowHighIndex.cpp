#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Problem: Find low and high index of given key in sorted array with duplicates and million elements
//

int findLowIndex(const vector<int>& v, int k)
{
	if (v.size() == 0)
		return -1;
	
	int l = 0,
		r = v.size()-1;
		
	while(l<=r)
	{
		int m = l + (r-l)/2;
		
		if(v[m] >= k)
		{
			r = m-1;
		}
		else
		{
			l = m+1;
		}
	}
	
	if(l < v.size()-1 && v[l]==k)
		return l;
	
	return -1;
}

int findHighIndex(const vector<int>& v, int k)
{
	if (v.size() == 0)
		return -1;
	
	int l = 0,
		r = v.size()-1;
		
	while(l<=r)
	{
		int m = l + (r-l)/2;
		
		if(v[m] <= k)
		{
			l = m+1;
		}
		else
		{
			r = m-1;
		}
	}
	
	if(r >= 0 && v[r]==k)
		return r;
	
	return -1;
}

int main()
{
	vector<int> v = {1,1,1,2,2,2,2,2,3,3,3,4,4,4,4,5,5,5,6,6,6,6,6,6}; 
	
	cout << "Input Array : " << endl;
	for(int x: v)
		cout << x << " ";
	cout << endl << endl;
	
	cout << "For key 1, low index is at " << findLowIndex(v, 1) << " and high index is at " << findHighIndex(v, 1) << endl;
	cout << "For key 4, low index is at " << findLowIndex(v, 4) << " and high index is at " << findHighIndex(v, 4) << endl;
	cout << "For key 6, low index is at " << findLowIndex(v, 6) << " and high index is at " << findHighIndex(v, 6) << endl;
	
	return 0;
}