#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
	string key;
	string value;
	Node *next;
	
	Node(string k, string v)
	{
		key = k;
		value = v;
		next = nullptr;
	}
};

class HashTable
{
	
public:
    HashTable(int size) : m_size(size)
	{
		m_hashTable.resize(m_size);
		m_hashTable = {nullptr};
	}
	
	~HashTable()
	{
		m_hashTable.clear();
	}
	
	void put(string key, string value)
	{
		int index = getHash(key);
		if(m_hashTable[index] == nullptr) // No element for that index
		{
			Node* head = new Node(key, value);
			m_hashTable[index] = head;
		}
		else
		{
			Node *head = m_hashTable[index];
			//
			// Check if the key already exists if so update and return
			//
			while(head)
			{
				if(key == head->key)
				{
					head->value = value;
					return;
				}
				head = head->next;
			}
			//
			// If it has reached here, that means no key was found. Add new key value pair
			//
			Node *newPair = new Node(key, value);
			newPair->next = m_hashTable[index];
			m_hashTable[index] = newPair;
		}		
	}
	
	string get(string key)
	{
		int index = getHash(key);
		Node *head = m_hashTable[index];
		while(head)
		{
			if(key == head->key)
			{
				return head->value;
			}
			head = head->next;
		}
		
		return nullptr;
	}
	
	bool remove(string key)
	{
		int index = getHash(key);
		Node* head = m_hashTable[index];
		
		if(head == nullptr)
		{ 
			return false;
		}
		else if(head->key == key)
		{
			Node *temp = head;
			head = head->next;
			m_hashTable[index] = head;
			delete temp;
		}	
		else{
			Node *prev = head;
			Node *runner = head->next;
			while(runner)
			{
				if(runner->key == key)
				{
					prev->next = runner->next;
					delete runner;
					return true;
				}			
				prev = runner;
				runner = runner->next;			
			}
			return false;
		}
		
	}
		
private:
	
	int getHash(string key)
	{
		int index = 0;
		
		for(int i = 0; i < key.size(); i++)
		{
			index = index * key[i] + key[i] + i; 
		}
		index = abs(index);
		
		index = index % m_size;
		return index;
	}
	
	int m_size;
	vector<Node*> m_hashTable;
};

int main()
{
	HashTable ht(20);
	ht.put("hello", "1");
	ht.put("world", "2");
	ht.put("test", "3");
	
	cout << ht.get("hello") << endl;
	cout << ht.get("world") << endl;
	cout << ht.get("test") << endl;
	
	ht.put("hello", "4");
	ht.put("world", "5");
	ht.put("test", "6");
	
	cout << ht.get("hello") << endl;
	cout << ht.get("world") << endl;
	cout << ht.get("test") << endl;
	
	cout << ht.remove("hello") << endl;
	cout << ht.remove("world") << endl;
	cout << ht.remove("test") << endl;
	
	cout << ht.remove("hello") << endl;
	cout << ht.remove("world") << endl;
	cout << ht.remove("test") << endl;

	return 0;
}