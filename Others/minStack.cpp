#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class MinStack
{
public:
	void push(int d)
	{
		values.push_back(d);
		
		if(minValues.empty())
			minValues.push_back(d);
		else{
			if(minValues.back() > d)
				minValues.push_back(d);
		}
	}
	
	void pop()
	{
		int min = values.back();
		values.pop_back();
		
		if(minValues.back() == min)
			minValues.pop_back();
	}
	
	int top()
	{
		return values.back();
	}
	
	int min()
	{
		return minValues.back();
	}

private:
	vector<int> values;
	vector<int> minValues;
};

int main()
{
	MinStack ms;
	ms.push(4);
	ms.push(2);
	ms.push(1);
	ms.push(3);
	
	cout << ms.min() << endl;
	ms.pop();
	
	cout << ms.min() << endl;
	ms.pop();
	
	cout << ms.min() << endl;
	ms.pop();
	
	cout << ms.min() << endl;
		
	return 0;
}