#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Time complexity : O(log (min(n1, n2))
// Space complexity: O(1)
//
double findMedianSortedArrayUtil(vector<int> &X, vector<int> &Y, int nx, int ny)
{
	double res = 0;
	
	int l = 0;
	int r = nx;
	
	while(l <= r){
		int midX = (l+r)/2;
		int midY = (nx+ny+1)/2 - midX;
		
		int maxLeftX = (midY == 0) ? INT_MIN : X[midX-1];
		int minRightX = (midY == nx) ? INT_MAX : X[midX];

		int maxLeftY = (midY == 0) ? INT_MIN : Y[midY-1];
		int minRightY = (midY == ny) ? INT_MAX : Y[midY];
		
		if(maxLeftX <= minRightY && maxLeftY <= minRightX)
		{
			if((nx + ny)%2 == 0)
			{
				return (double(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2);
			}
			else
			{
				return double(max(maxLeftX, maxLeftY));
			}
		}
		else if(maxLeftX > minRightY)
		{
			r = midX-1;
		}
		else
		{
			l = midX+1;
		}		
	}
	
	return 0;
}


double findMedianSortedArray(vector<int> &v1, vector<int> &v2)
{
	int n1 = v1.size();
	int n2 = v2.size();
	if (n1 == 0 && n2 == 0)
		return 0;
	
	int mid = 0;	
	//
	// This to handle if one of the array is empty
	//
	if(n1 == 0)
	{
		mid = n2+1/2;
		if(n2 % 2 == 0)
			return double(v2[mid]+v2[mid+1])/2;
		else
			return v2[mid];
	}
	else if(n2 == 0)
	{
		mid = n1+1/2;
		if(n1 % 2 == 0)
			return double(v1[mid]+v1[mid+1])/2;
		else
			return v1[mid];
	}
	
	//
	// If both are valid then we can perform binary search on array with min length to find the median
	//
	if(n1 < n2)
		return findMedianSortedArrayUtil(v1, v2, n1, n2);
	else
		return findMedianSortedArrayUtil(v2, v1, n2, n1);
	
}

int main()
{
	vector<int> v1 = {1,3,5,7,9,11};
	vector<int> v2 = {4,8,12,16,20,24};
	
	cout << "Elements in first input sorted array: \n";
	for(int i : v1)
		cout << i << " ";
	cout << endl;
	
	cout << "Elements in second input sorted array: \n";
	for(int i : v2)
		cout << i << " ";
	cout << endl;
	
	cout << "Median of two sorted array : " << findMedianSortedArray(v1, v2);
	
	return 0;
}
		

