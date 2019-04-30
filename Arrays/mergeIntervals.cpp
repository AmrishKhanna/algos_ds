#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<pair<int, int>> Intervals;

//
// Time COmplexity : O(n)
// Space Complexity: O(n), worst case if there are no overllapping intervals
//
Intervals mergeIntervals(Intervals& v)
{
	Intervals result;
	if(v.size() == 0)
		return result;
	
	int start = v[0].first;
	int end = v[0].second;
	
	for (pair<int, int> x : v)
	{
		if(x.first >= start && x.first <= end)
		{
			//
			// This interval must be starting within previous interval
			//
			if(x.second > end)
				end = x.second;
		}
		else
		{
			//
			// Not in previous range. So start new range
			//
			result.push_back(make_pair(start, end));
			start = x.first;
			end = x.second;
		}
	}
	
	//
	// Push final merged intervals
	//
	result.push_back(make_pair(start, end));
	return result;
}

int main()
{
	Intervals v = {
                          make_pair<int,int>(1,5),
                          make_pair<int,int>(3,7),
                          make_pair<int,int>(4,6),
                          make_pair<int,int>(6,8),
						  make_pair<int,int>(10,12),
						  make_pair<int,int>(11,15)
                        };
	
	cout << "Input Intervals :" << endl;
	for (pair<int, int> x : v)
		cout << x.first << " - " << x.second << endl;
	cout << endl << endl;
	
	Intervals res = mergeIntervals(v);
	cout << "Merged Intervals :" << endl;
	for (pair<int, int> x : res)
		cout << x.first << " - " << x.second << endl;
	cout << endl << endl;
	
	return 0;
}