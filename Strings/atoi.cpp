#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int my_atoi(string s)
{
	//
	// If string is null return 0
	//
	if(s == "") 
		return 0;
	
	//
	// Remove spaces between, leading spaces and trailing spaces if any
	//
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	
	//
	// If the first char is letter return 0
	//
	if(s[0]!= '-' && s[0] != '+' && (s[0] < '0' || s[0] > '9'))
		return 0;
	
	//
	// Get sign if any
	//
	int sign = 1;
	if(s[0] == '-')
	{
		s.erase(0,1);
		sign = -1;
	}
	else if(s[0] == '+')
		s.erase(0,1);
    //
	// Remove trailing zeroes if any
	//
	int i = 0;
	while(s[i] == '0') i++;
	s.erase(0, i);
	
	i = 0; 
	long long num = 0;

	while(s[i] >= '0' && s[i] <= '9') // This will avoid other characters
	{
		num = num * 10 + (s[i] - '0'); 
		i++;
		
		cout << num << endl;
		if(num > INT_MAX)
		{
			if(sign == -1) 
				return INT_MIN;
			else 
				return INT_MAX;
		}
	}		
	return (sign*num);
}

int main()
{
	string s1 = "0042";
	string s2 = "   -42";
	string s3 = "400862 with words";
	string s4 = "shouldnotprocess42";
	string s5 = "-91283472332";
	
	//cout << "Integer equivalent to " << s1 << " is " << my_atoi(s1) << endl;
	//cout << "Integer equivalent to " << s2 << " is " << my_atoi(s2) << endl;
	//cout << "Integer equivalent to " << s3 << " is " << my_atoi(s3) << endl;
	//cout << "Integer equivalent to " << s4 << " is " << my_atoi(s4) << endl;
	cout << "Integer equivalent to " << s5 << " is " << my_atoi(s5) << endl;
	
	return 0;
}