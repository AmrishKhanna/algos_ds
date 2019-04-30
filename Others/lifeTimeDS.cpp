#include <iostream>
#include <chrono>
#include <thread>
#include <future>

using namespace std;
using namespace std::chrono;

class Node {
	public:
		int data;
		milliseconds lifetimeinMS;
			
		Node(int d, milliseconds ms)
		{
			data = d;
			lifetimeinMS = ms;
		}
};

class LTDS
{
private:
	vector<Node> v;
public:
	LTDS()
	{
		std::async([](){
 
						
 
					}, "Data");
	}
	
	void insert(Node n)
	{
		v.push_back(n);
	}
	
	void access()
	{
		cout << "Elements in Life time Data Structure are: \n";
		for(int x: v)
			cout << x << " "
		cout << endl
	}
};

int main()
{
	LTDS ltds;
	ltds.insert(Node(1, 500));
	ltds.insert(Node(2, 500));
	ltds.insert(Node(3, 5000));
	ltds.insert(Node(4, 1000));
	ltds.insert(Node(5, 2000));
	ltds.insert(Node(6, 1000));
	
	ltds.access();
	
	return 0;
}
