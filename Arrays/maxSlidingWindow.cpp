#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

//
// Time Complexity : O(n)
// Space Complexity: O(w_size)
// We can also use priority queue to solve it. But the time complexity will rise to O(nlog(w_size))
//
vector<int> findMaximumSlidingWindow(vector<int>& v, int w_size)
{
	vector<int> result;
	if(w_size > v.size() || w_size == 0 || v.size() == 0) 
		return result;		
	
	deque<int> window;
	
	//
	// Pushing maximum value in first window into deque
	//
	for(int i = 0; i< w_size; ++i)
	{
		while(!window.empty() && v[i] >= v[window.back()])
			window.pop_back();
		window.push_back(i);
	}
	result.push_back(v[window.front()]);
	
	//
	// Find maximum values for other windows by sliding one position
	//
	for(int i=w_size; i< v.size(); ++i)
	{
		while(!window.empty() && v[i] >= v[window.back()])
			window.pop_back();
		
		if(!window.empty() && window.front() <= i-w_size)
			window.pop_front();
		
		window.push_back(i);
		result.push_back(v[window.front()]);		
	}
	
	return result;
}

int main()
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v2 = {10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67};
	
	cout << "The elements in the input array :" << endl;
	for (int x : v1)
		cout << x << " ";
	cout << endl;
	
	vector<int> result1 = findMaximumSlidingWindow(v1, 3);
	cout << endl << "The maximum in each sliding window of size 3 : " << endl; 
	for (int x : result1)
		cout << x << " ";
	cout << endl << endl;
	
	cout << "The elements in the input array :" << endl;
	for (int x : v2)
		cout << x << " ";
	cout << endl;
	
	vector<int> result2 = findMaximumSlidingWindow(v2, 4);
	cout << endl << "The maximum in each sliding window of size 4 : " << endl; 
	for (int x : result2)
		cout << x << " ";
	cout << endl;
	return 0;
}