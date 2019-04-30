#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
struct Edge
{
public:
	int src;
	int tgt;
	
	Edge(int s, int t)
	{
		src = s;
		tgt = t;
	}
};

class Graph
{
private:
    int m_edge_count;
	vector<unordered_set<int>> m_adjlist;

public:
	Graph(int size) 
	{
		m_edge_count = 0;
		m_adjlist.resize(size);
	}
	
	void addEdge(Edge e)
	{
		if(m_adjlist[e.src].find(e.tgt) == m_adjlist[e.src].end())
		{
			m_adjlist[e.src].insert(e.tgt);
			//
			// Uncomment below line for undirected graph
			//
			// m_adjlist[e.tgt].insert(e.src);
			m_edge_count++;
		}
	}
	
	void bfs_iterative(int src)
	{
		if(m_adjlist.size() < src && src >=0)
			return;
		
		cout << "BFS of graph: " << endl;
		unordered_set<int> visited;
		queue<int> q;
		
		q.push(src);	
		visited.insert(src);		
		
		while(!q.empty())
		{
			int s = q.front();
			cout << s << " ";
			q.pop();
			
			if(m_adjlist[s].size())
			{
				for(auto t: m_adjlist[s])
				{
					if(visited.find(t)==visited.end())
					{
						q.push(t);
						visited.insert(t);
					}							
				}
			}			
		}
		cout << endl;
	}
	
	void dfs_iterative(int src)
	{
		if(m_adjlist.size() < src && src >=0)
			return;
		
		cout << "DFS of graph: " << endl;
		unordered_set<int> visited;
		stack<int> stk;
		
		stk.push(src);	
		visited.insert(src);		
		
		while(!stk.empty())
		{
			int s = stk.top();
			cout << s << " ";
			stk.pop();
			
			if(m_adjlist[s].size())
			{
				for(auto t: m_adjlist[s])
				{
					if(visited.find(t)==visited.end())
					{
						stk.push(t);
						visited.insert(t);
					}							
				}
			}			
		}
		cout << endl;
	}
	
	int nodeCount()
	{
		return m_adjlist.size();
	}
	
	int edgeCount()
	{
		return m_edge_count;
	}
};

int main()
{
	Graph g(6);
	
	g.addEdge(Edge(0,1));
	g.addEdge(Edge(0,2));
	g.addEdge(Edge(1,2));
	g.addEdge(Edge(1,3));
	g.addEdge(Edge(2,4));
	g.addEdge(Edge(3,5));
	g.addEdge(Edge(2,5));
	g.addEdge(Edge(3,4));
	
	cout << "Node Count : " << g.nodeCount() << endl;
	cout << "Edge Count : " << g.edgeCount() << endl;
	g.bfs_iterative(0);
	g.dfs_iterative(0);
	return 0;
}
