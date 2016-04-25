#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	int m,first,sec;
	Graph g(10);
	cin>>m;
	for(int i=0; i<m; i++)
	{
		cout<<"First node and second node: "<<endl;
		cin>>first>>sec;
		g.addEdge(first,sec);
		g.addEdge(sec,first);
	}
	cout<<"BFS: \n";
	g.BFS(0);

	cout<<"DFS: \n";
	g.DFS(0);

	return 0;
}
