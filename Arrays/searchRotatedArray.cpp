#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Time complexity: O(logn)
// Space complexity: O(1)
//
int searchRotatedArray(vector<int>& v, int x)
{
	if(v.size() == 0) return -1;
	
	int l = 0,
	    r = v.size() - 1;
	
	while(l <= r)
	{
		int m = l+(r-l)/2;
		if(x == v[m])
			return m;
		
		if(v[l] <= v[m])
		{
			if(x >= v[l] && x <= v[m])
			{
				r = m-1;
			}
			else
			{
				l = m+1;
			}
		}
		else
		{
			if(x >= v[m] && x <= v[r])
			{
				l = m+1;
			}
			else
			{
				r = m-1;
			}				
		}
	}
	return -1;
}

int main()
{
	vector<int> v1 = {6, 7, 1, 2, 3, 4, 5};
  
    cout << "Key 3 found at: " << searchRotatedArray(v1, 3) << endl;
    cout << "Key 6 found at: " << searchRotatedArray(v1, 6) << endl;
    
    vector<int> v2 = {4, 5, 6, 1, 2, 3};
    
    cout << "Key 3 found at: " << searchRotatedArray(v2, 3) << endl;
    cout << "Key 6 found at: " << searchRotatedArray(v2, 6) << endl;
	return 0;
}