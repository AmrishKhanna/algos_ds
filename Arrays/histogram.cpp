#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

//
// Time complexity : O(n)
// Space complexity : O(n)
//
int findMaxAreaInHistogram(vector<int> &v)
{
	if(v.size() == 0)
		return 0;
	
	int n = v.size();
	int maxArea = 0;
	int currArea = 0;
	stack<int> indexStk; // To store index
	
	int i = 0;
	while(i < n)
	{
		if(indexStk.empty() || v[indexStk.top()] <= v[i] ){
			indexStk.push(i);
			i++;
		}
		else
		{
			int top = indexStk.top();
			indexStk.pop();
			
			currArea = v[top]*(indexStk.empty() ? i : i-1-indexStk.top());
			
			if(currArea > maxArea)
				maxArea = currArea;
		}
	}
	
	while(!indexStk.empty())
	{
		int top = indexStk.top();
		indexStk.pop();
		
		currArea = v[top]*(indexStk.empty() ? i : i-1-indexStk.top());
		
		if(currArea > maxArea)
			maxArea = currArea;
	}
	
	return maxArea;
}


int main()
{
	vector<int> histogram = {6, 2, 5, 4, 5, 1, 6};
	cout << "Elements in given histogram array: " ;
	for(int i : histogram)
		cout << i << " ";
	cout << endl;
	
	cout << "Maximum Arean for given histogram : " << findMaxAreaInHistogram(histogram) << endl;
	
	
	return 0;
}
