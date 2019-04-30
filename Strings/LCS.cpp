#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//
// Time complexity : O(mn)
// Space complexity : O(mn)
//
void LCS(string& str1, string& str2)
{
	if(str1.size() <= 0 && str1.size()<= 0)
		return;
	
	cout << "string 1: " << str1 <<  endl;
	cout << "string 2: " << str2 <<  endl;
	int m = str1.size() + 1;
	int n = str2.size() + 1;
	
	vector<vector<int>> grid(m, vector<int>(n));
	
	int max_i = 0, max_j = 0, maxv = INT_MIN;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				grid[i][j] = grid[i-1][j-1] + 1;
				if(grid[i][j] > maxv)
				{
					maxv = grid[i][j];
					max_i = i;
					max_j = j;
				}
			}
			else{		
				grid[i][j] = 0;
			}
		}
	}	
	//
	// We know the max value an dits index
	// Move diagonally to get the commaon string
	//
	cout << "The maximum length of common string is " << maxv << endl;
	
	string result = "";
	while(grid[max_i][max_j])
	{
		result.insert(0, 1, str1[max_i-1]);
		max_i -= 1;
		max_j -= 1;
	}
	cout << "The common substring is " << result << endl;
	
	
}


int main()
{
	string s1 = "abcdaf";
	string s2 = "zbcdf";
	LCS( s1, s2);
	return 0;
}