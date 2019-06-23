#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Time complexity: O(n)
// Space complexity: O(1)
//

int findMaxAreaBetweenTwoPillars(vector<int>& height)
{
	if(height.size() == 0)
		return 0;
	
	int maxArea = 0;
	int startIdx = 0, endIdx = 0;
	
	int l = 0; 
	int r = height.size()-1;
	
	int currArea = 0;
	
	while(l<r)
	{
		currArea = min(height[l], height[r]) * (r-l);
		if(maxArea < currArea)
		{
			maxArea = currArea;
			startIdx = l;
			endIdx = r;
		}
		
		if(height[l] < height[r])
			l = l+1;
		else
			r = r-1;
	}
	
	//Odd case
	if(l == r)
	{
		if( height[l-1] < height[l+1] ){
			currArea = min(height[l], height[l+1]);
			r = l+1;
		}
		else
		{
			currArea = min(height[l], height[l-1]);
			l = l-1;
		}
		if(maxArea < currArea)
		{
			maxArea = currArea;
			startIdx = l;
			endIdx = r;
		}	
	}
	
	cout << "Start container at : " << startIdx << endl;
	cout << "End container at : " << endIdx << endl;
	
	return maxArea;
}

//
// Container with most water
// Basically need to find the max area 
// between two pillars to store water
//
int main()
{
	
	vector<int> height1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	
	cout << "Elements in height array 1: \n";
	for(int i : height1)
		cout << i << " ";
	cout << endl;
	
	cout << "Maximum Area that can contain water : " << findMaxAreaBetweenTwoPillars(height1) << endl;
	
	vector<int> height2 = { 1, 1, 1, 1, 50, 100, 2, 1, 1 };
	
	cout << "\nElements in height array 2: \n";
	for(int i : height2)
		cout << i << " ";
	cout << endl;
	
	cout << "Maximum Area that can contain water : " << findMaxAreaBetweenTwoPillars(height2) << endl;
 	return 0;
}