#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void unionArray(vector<int> &v1, vector<int> &v2)
{
    sort(v1.begin(), v1.end()); 
	int i;
	
	cout << "\nUnion of Array: \n";
	for(i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	
    for (i = 0; i < v2.size(); i++)
	{
       if(!binary_search(v1.begin(), v1.end(), v2[i]))
	   {
		   cout << v2[i] << " ";
	   }
	}
	
	//Time Complexity: O(mlogm + nlogm) => O((m+n)logm)
}

void intersectArray(vector<int> &v1, vector<int> &v2)
{
	sort(v1.begin(), v1.end());
    int i;
	
	cout << "\nIntersection of Array: \n"; 
	
    for (i = 0; i < v2.size(); i++)
	{
       if(binary_search(v1.begin(), v1.end(), v2[i]))
	   {
		   cout << v2[i] << " ";
	   }
	}
	
	//Time Complexity: O(mlogm + nlogm) => O((m+n)logm)
}

void unionArraySorted(vector<int> &v1, vector<int> &v2)
{	
	cout << "\nUnion of Sorted Array: \n"; 
	int i = 0, j =0;
	
	while(i < v1.size() && j < v2.size())
	{
		if(v1[i] < v2[j])
		{
			cout << v1[i] << " ";
			i++;
		}
		else if(v1[i] > v2[j])
		{
			cout << v2[j] << " ";
			j++;
		}
		else
		{
			cout << v1[i] << " ";
			i++;
			j++;
		}	
	}
	
	// Print remaining elements of the larger array
	while(i < v1.size())
		cout << v1[i++] << " ";
	while(j < v2.size())
		cout << v2[j++] << " ";
	
	// Time Complexity: O(m + n)
}

void intersectArraySorted(vector<int> &v1, vector<int> &v2)
{
    cout << "\nIntersection of Sorted Array: \n"; 
	int i = 0, j =0;
	
	while(i < v1.size() && j < v2.size())
	{
		if(v1[i] < v2[j])
		{
			i++;
		}
		else if(v1[i] > v2[j])
		{
			j++;
		}
		else
		{
			cout << v1[i] << " ";
			i++;
			j++;
		}	
	}
	
	// Time Complexity: O(m + n)
}

void arrayDriver(vector<int> &v1, vector<int> &v2, int sorted = 0)
{
	if(sorted == 0)
	{
		if(v1.size() <= v2.size())
		{
			unionArray(v1, v2);
			intersectArray(v1, v2);
		}
		else{
			unionArray(v2, v1);
			intersectArray(v2, v1);
		}	
	}
	else
	{
		if(v1.size() <= v2.size())
		{
			unionArraySorted(v1, v2);
			intersectArraySorted(v1, v2);
		}
		else{
			unionArraySorted(v2, v1);
			intersectArraySorted(v2, v1);
		}	
	}
}

int main()
{
	//
	// Unsorted no duplicates
	//
	vector<int> a = {3, 1, 4, 5, 2};
	vector<int> b = {4, 5, 3, 7};
	arrayDriver(a, b);
	a.clear();
	b.clear();
	
	//
	// Sorted no duplicates
	//
	b = {1, 2, 3, 4, 5};
	a = {3, 4, 5, 7};
	arrayDriver(a, b, 1);
	a.clear();
	b.clear();
	
	return 0;	
}
