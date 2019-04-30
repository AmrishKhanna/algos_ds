#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int>& v, int l, int r)
{
	int pValue = v[l];
	int i = l;
	int j = r;
	
	while(i<j)
	{
		while(i <= r && v[i] <= pValue) i++;
		while(v[j] > pValue) j--;
		
		if(i < j)
		{
			swap(v[i], v[j]);
		}
	}
	
	v[l] = v[j];
	v[j] = pValue;
	
	return j;
}

void quick_sort_recursive(vector<int>& v, int l, int r)
{
	if(r > l) {
		int pivot = partition(v, l, r);
		quick_sort_recursive(v, l, pivot-1);
		quick_sort_recursive(v, pivot+1, r);
	}
}

void quick_sort(vector<int>& v)
{
	if(v.size() == 0)
		return;
	
	quick_sort_recursive(v, 0, v.size()-1);
}

int main()
{
	vector<int> v = { 55, 23, 26, 2, 18, 78, 23, 8, 2, 3 };
	
	cout << "Input array :" << endl;
	for (int x : v)
		cout << x << " ";
	cout << endl << endl;
	
	quick_sort(v);
	
	cout << "Sorted Input array :" << endl;
	for (int x : v)
		cout << x << " ";
	cout << endl << endl;
	
	return 0;
}