#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Time Complexity : O(n)
// Space complexity: O(1)
//
int findSmallestCommonNumber(vector<int>& v1, vector<int>& v2, vector<int>& v3)
{
	if(v1.size() == 0 || v2.size() == 0 || v3.size() == 0)
		return INT_MIN;
	
	//
	// Since all arrays are sorted any first matching value will be the smallest common value
	//
	int i = 0, j = 0, k = 0;
	
	while(i < v1.size() && j < v2.size() && k < v3.size())
	{
		if(v1[i] == v2[j] && v2[j] == v3[k])
				return v1[i];
		
		if(v1[i] < v2[j] && v1[i] < v3[k])
			i++;
		else if(v2[j] < v3[k])
			j++;
		else
			k++;
	}
	
	return INT_MIN;
}

int main()
{
	//
	// All arrays are sorted
	//
	vector<int> v1 = {6, 7, 10, 25, 30, 63, 64};
	vector<int> v2 = {-1, 4, 5, 7, 10, 8, 50};
	vector<int> v3 = {1, 6, 10, 14};
	
	cout << "Elements of first array:" << endl;
	for(int x : v1)
		cout << x << " ";
	cout << endl;
	
	cout << "Elements of second array:" << endl;
	for(int x : v2)
		cout << x << " ";
	cout << endl;
	
	cout << "Elements of third array:" << endl;
	for(int x : v3)
		cout << x << " ";
	cout << endl;
	
	cout << "Common Smallest Number in three Arrays is " << findSmallestCommonNumber(v1, v2, v3);
	return 0;
}