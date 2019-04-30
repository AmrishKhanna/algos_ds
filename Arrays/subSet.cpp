#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Time complexity: O(2^n)
//
void getSubSets(vector<int> &s)
{
	if(s.size() == 0)
		return;
	
	int len = s.size();
	
	for(int i=0; i < (1<<len); i++) // 2^n-1
	{
		cout << "{ ";
		for(int j =0; j < len; j++)
		{
			if(i & (1<<j))
				cout << s[j] << " ";
		}
		cout << "}"  << endl;
	}
}

int main()
{
	vector<int> s = {1, 2, 3};
	getSubSets(s);
	return 0;
}