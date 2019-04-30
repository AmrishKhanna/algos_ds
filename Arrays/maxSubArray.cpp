#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Time complexity : O(n)
//
void maxSubArray(vector<int> &input)
{
	if(input.size() == 0)
		return;
		
	int curr_max = input[0];
	int total_max = input[0];
	int start = 0, end = 0, s = 0;

	//
	// Kadane's algorithm
	//
	for(int i =1; i < input.size(); i++)
	{
		if(input[i] < curr_max + input[i])
		{
			curr_max = curr_max + input[i];
		}
		else
		{
			curr_max = input[i];
			s = i;
			
		}
		
		if(curr_max > total_max)
		{   
			total_max = curr_max;
			start = s;
			end = i;
		}
	}	
	
	cout << "Maximum sub array sum is " << total_max 
	     << " starting from index " << start << " to " << end <<  endl;
}

int main()
{
	vector<int> input = { -2, -3, 4, -1, -2, 1, 5, -3};
	maxSubArray(input);
	return 0;
}