#ifndef Graph_H
#define Graph_H


#include <list>
#include <queue>
#include <stack>

using namespace std;


class Graph
{
	private: 
		int nrNodes;
		list<int> *adj;
		void recursiveDFS(int node, bool visited[]);
	public:
		Graph(int nrNodes)
		{
			this->nrNodes = nrNodes;
			adj = new list<int>[nrNodes];
		}
		~Graph()
		{
			delete [] adj;
		}

		void addEdge(int firstNode, int secondNode);
		void DFS(int node);
		void BFS(int node);
		
};

void Graph::addEdge(int firstNode, int secondNode)
{
	adj[firstNode].push_back(secondNode);
}

void Graph::BFS(int node)
{
	int i;
	list<int>::iterator it;
	bool *visited = new bool[nrNodes];
	queue<int> q;
	for ( i=0 ; i < nrNodes ; i++)
	{
		visited[i]=false;
	}
	visited[node] = true;
	q.push(node);
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		cout<<node<<" ";
		for(it = adj[node].begin(); it!=adj[node].end(); it++)
		{
			if(!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	cout<<endl;
}

void Graph::recursiveDFS(int node, bool visited[])
{
	visited[node]=true;
	cout<<node<<" ";
	list<int>::iterator it;
	for(it = adj[node].begin(); it!=adj[node].end(); it++)
	{
		if (!visited[*it])
		{
			recursiveDFS(*it, visited);
		}
	}
 }
 
void Graph::DFS(int node)
{
	int i;
	list<int>::iterator it;
	bool *visited = new bool[nrNodes];
	for( i = 0; i < nrNodes; i++ )
	{
		visited[i]=false;
	}
	recursiveDFS(node, visited);
	cout<<endl;
}

#endif //Graph_H