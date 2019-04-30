#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void reverseArray(vector<int>& v, int l, int r)
{
	while(l<r)
	{
		int temp = v[l];
		v[l] = v[r];
		v[r] = temp;
		++l; --r;	
	}
}

//
// Time Complexity : O(n)
// Space Complexity: O(1)
//
void rotateArray(vector<int>& v, int k)
{
	if(	k == 0 || v.size() == 0){
		cout << "Not Rotated" << endl;
		return;
	}
	
	cout << "Input array :" << endl;
	for (int x : v)
		cout << x << " ";
	cout << endl;
	cout << "Rotated array by " << k << " :" << endl;
	//
	// Idea is to find the right partition based on k
	// If k is negative take its abs and if positive n-k will be the partition
	// Reverse left subarray, Reverse Right subarray and Reverse entire array
	//
	if( k < 0) k = -1 *k;
	else k = v.size()-k;
	
	reverseArray(v, 0, k-1);
	reverseArray(v, k, v.size()-1);
	reverseArray(v, 0, v.size()-1);
	
	for (int x : v)
		cout << x << " ";
	cout << endl;
}

int main()
{
	vector<int> v = { 20, 30, 1, 5, 7, 80, 90};
	rotateArray(v, -2);
	rotateArray(v, 4);
	
	return 0;
}