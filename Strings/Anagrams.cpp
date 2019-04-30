#include <iostream>
#include <string>
#define NO_OF_CHAR 256

using namespace std;

//
// Time Complexity : O(n)
// Space Complexity : Constant space of 256
//
bool isAnagram(const string &s1, const string &s2)
{
	if(s1.length() != s2.length())
		return false;
	
	int arr1[NO_OF_CHAR] = {0};
	int arr2[NO_OF_CHAR] = {0};
	
	int i;
	for(i = 0; s1[i] && s2[i]; i++)
	{
		arr1[s1[i]]++;
		arr2[s2[i]]++;
	}
	
	//
	// Checking Anagram
	//
	for(i=0; i< NO_OF_CHAR; i++)
	{
		if(arr1[i] != arr2[i])
			return false;
	}
	
	return true;	
}

int main()
{
	std::string s1, s2;
	cout << "Enter two strings for checking anagrams\n" ;
	cin >> s1;
	cin >> s2;
	if(isAnagram(s1, s2))
	{
		cout << "They are anagrams\n";
	}
	else
	{
		cout << "They are not anagrams\n";
	}
	return 0;
}