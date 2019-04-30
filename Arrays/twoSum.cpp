#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

//
// Array is not sorted so we need hash table to store complement.
// Time complexity : O(n)
// Space complexity: O(n)
//
void twoSum(vector<int>& v, int k)
{
	if(v.size() == 0)
		return;
	
	unordered_set<int> comp;
	
	for(int x : v)
	{
		if(comp.find(x) == comp.end())
		{
			comp.insert(k-x);
		}
		else
		{
			cout << "Element " << x << " and " << k-x << " sums upto " << k << endl;
			return;
		}
	}
	
	cout << "No two element sums up to " << k << endl;
}

//
// Array is sorted so we ncan go with two pointer approach
// Time complexity : O(n)
// Space complexity: O(1)
//
void twoSumSorted(vector<int>& v, int k)
{
	if(v.size() == 0)
		return;
	
	int i = 0;
	int j = v.size()-1;
	
	while(i<j)
	{
		if(v[i] + v[j] < k)
			++i;
		else if(v[i] + v[j] > k)
			--j;
		else
		{
			cout << "Element " << v[i] << " and " << v[j] << " sums upto " << k << endl;
			return;
		}
	}
	
	cout << "No two element sums up to " << k << endl;
}

int main()
{
	vector<int> v = { 16, 2, 9, 2, 5, 10, 1, 0, 77, 40 };
	
	cout << "Input array :" << endl;
	for (int x : v)
		cout << x << " ";
	cout << endl << endl;
	
	twoSum(v, 50);
	twoSum(v, 51);
	
	sort(v.begin(), v.end());
	
	cout << endl <<  "Sorted Input array :" << endl;
	for (int x : v)
		cout << x << " ";
	cout << endl << endl;
	
	twoSumSorted(v, 50);
	twoSumSorted(v, 51);
	
	return 0;
}