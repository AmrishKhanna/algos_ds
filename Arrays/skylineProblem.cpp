#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Point {
public:
	int x;
	int y;
	bool isStart;
	
	Point(int px, int py, bool pIsStart)
	{
		x = px;
		y = py;
		isStart = pIsStart;
	}
	
	Point(int px, int py)
	{
		x = px;
		y = py;
		isStart = true;
	}
};

bool point_compare(Point &a, Point &b)
{
	if(a.x == b.x)
	{
		if(!a.isStart && !b.isStart)
			//
			// This is for buildings with end at same x
			//
			return a.y < b.y;
		else{
			//
			// This is for buildings with start and end at same x
			// or two buildinsgs starting at same x
			//
			return a.y > b.y; 
		}
	}

	return a.x < b.x;
}

//
// Time complexity: O(2nlogn) => O(nlogn)
// Space complexity: O(n)
//
vector<Point> getSkyLine(vector<Point> &v)
{
	vector<Point> result;
	
	if(v.size() == 0)
		return result;
	
	int max = 0;
	
	//
	// Using set instead of priority queue because the time complexity are
	// Insert: O(logn)
	// Find Max : O(1)
	// Deletion: O(logn), incase of priority queue we can only pop max at O(1), others require heapify
	//
	set<int> pq;
	pq.insert(0);
	
	for(Point p : v)
	{
		max = *pq.rbegin();
		
		if(p.isStart)
		{
			pq.insert(p.y);
		}
		else
		{
			pq.erase(p.y);
		}
		
		if(*pq.rbegin() != max)
		{
			result.push_back(Point(p.x, *pq.rbegin()));
		}
	}
	
	return result;
}
	
int main()
{
	vector<vector<int>> buildings = {{1, 11, 3}, {3, 6, 7}, {3, 13, 9}, 
                      {12, 7, 16}, {14, 3, 16}};
	
	cout << "The given building points are : \n";
	vector<Point> sortedBuildingPoints;
	for (vector<int> building : buildings)
	{
		sortedBuildingPoints.push_back(Point(building[0], building[1], true));
		sortedBuildingPoints.push_back(Point(building[2], building[1], false));
		cout << "(" << building[0] << ", " << building[2] << ", " << building[1] << " )\n";
	}
	sort(sortedBuildingPoints.begin(), sortedBuildingPoints.end(), point_compare);
	
	cout << "The sorted building points are : \n";
	for(Point p : sortedBuildingPoints)
	{
		cout << "(" << p.x << ", " << p.y << ", " << p.isStart << " )\n";
	}
	
	vector<Point> result = getSkyLine(sortedBuildingPoints);
	cout << "The skyline points are: \n";
	for(Point p : result)
	{
		cout << "(" << p.x << ", " << p.y << " )\n";
	}
	
	return 0;
}