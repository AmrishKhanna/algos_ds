#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

//
// Time Complexity : O(n)
// Space Complexity : O(d) where d is no of unique char in given string
//
void LUS(string &str)
{
	if(str.size() == 0)
		return;
	
	int m = str.size();
	
	unordered_map<char, int> hm;
	int start = 0, max_start = 0;
	int len = 0, max_len = 0;
	
	hm[str[0]] = 0;
	int  i;
	for(i=1; i < m; i++)
	{
		if(hm.find(str[i]) != hm.end())
		{
			if(hm[str[i]] >= start)
			{
				len = i-start;
				if(max_len < len)
				{
					max_len = len;
					max_start = start;
				}
				start = hm[str[i]]+1;
			}
		}
		hm[str[i]] = i;
	}	
	
	if(max_len < i-start)
	{
		max_len = i-start;
		max_start = start;
	}
	
	cout << "The given input string is " << str << endl;
	cout << "Maximum length of the unique substring is " << max_len << endl;
	cout << "The unique substring is " << str.substr(max_start, max_len) << endl;
	
}

int main()
{
	string s = "abbeacbdedc";
	LUS(s);
	return 0;
}