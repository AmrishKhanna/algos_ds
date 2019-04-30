#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void findNumIslands_dfs(vector<vector<int>> &grid, int i, int j, int m, int n)
{
	if(i<0 || j>=n || i>=m || j <0 || grid[i][j] == 0 || grid[i][j] == 999)
		return;
	
	grid[i][j] = 999;
	findNumIslands_dfs(grid, i+1, j, m, n);
	findNumIslands_dfs(grid, i-1, j, m, n);
	findNumIslands_dfs(grid, i, j+1, m, n);
	findNumIslands_dfs(grid, i, j-1, m, n);
}

int findNumIslands(vector<vector<int>> &grid)
{
	int m = grid.size();
	int n = grid[0].size();
	
	if(m <= 0) return 0;
	int result = 0;
	
	for(int i=0; i < m; ++i)
	{
		for(int j=0; j < n; ++j)
		{
			if(grid[i][j] == 1)
			{
				findNumIslands_dfs(grid, i, j, m , n);
				result++;
			}
		}
	}
	
	return result;
}

int main()
{
	vector<vector<int>> grid = {   
								   {1, 1, 0, 0, 0}, 
								   {0, 1, 0, 0, 1}, 
								   {1, 0, 0, 1, 1}, 
								   {0, 0, 0, 0, 0}, 
								   {1, 0, 1, 0, 1} 
							   }; 
	
	cout << "No of islands : " << findNumIslands(grid) << endl;
	
	return 0;
}