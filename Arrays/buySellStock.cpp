#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> buySellStock(vector<int>& v)
{
	pair<int, int> stock;
	stock.first = -1;
	stock.second = -1;
	
	if(v.size() == 0)
		return stock;
	
	int current_buy = v[0];
	int global_sell = v[1];
	int global_profit = global_sell - current_buy;
	int current_profit = INT_MIN;
	
	for(int i = 1; i < v.size(); i++ )
	{
		current_profit = v[i]-current_buy;
		
		if(current_profit > global_profit)
		{
			global_profit = current_profit;
			global_sell = v[i];
		}
		
		if(current_buy > v[i])
			current_buy = v[i];		
	}
	
	stock.first = global_sell - global_profit;
	stock.second = global_sell;
	
	return stock;
}

int main()
{
	vector<int> v1 = { 1, 2, 3, 4, 3, 2, 1, 2, 5 };
	
	cout << "Input array :" << endl;
	for (int x : v1)
		cout << x << " ";
	cout << endl << endl;
	
	pair<int, int> result = buySellStock(v1);
	cout << "Buy at " << result.first << " and sell at " << result.second << endl << endl;
	
	vector<int> v2 = { 8, 6, 5, 4, 3, 2, 1};
	
	cout << "Input array :" << endl;
	for (int x : v2)
		cout << x << " ";
	cout << endl << endl;
	
	result = buySellStock(v2);
	cout << "Buy at " << result.first << " and sell at " << result.second << endl;
	return 0;
}