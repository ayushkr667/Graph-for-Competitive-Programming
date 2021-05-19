#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define ll long long
#define pb push_back
int V;
vector<vector<int> > g;
vector<bool> visited;

void add_edge(int a,int b)
{
	g[a].pb(b);
	g[b].pb(a);
}
int bfs(int root,int level)
{
	//queue for bfs
	queue<int>q;
	//array to store level of each node
	int node_level[V];
	visited[root]=true;
	q.push(root);
	node_level[root]=0;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		//enqueue all adjacent element and mark their levels
		vector<int>::iterator i;
		for(i=g[s].begin(); i!=g[s].end(); i++)
		{
			if(!visited[*i])
			{
				node_level[*i]=node_level[s]+1;
				visited[*i]=true;
				q.push(*i);
			}
		}

	}
	int count=0;
	for (int i = 0; i < V; ++i)
	{
		/* code */
		if(node_level[i]==level)
		{
			count++;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int e;//no of edges
	cin>>V>>e;//V: no of nodes
	visited.assign(V, false);
    g.assign(V, vector<int>());
    
	int a,b;
	while(e--)
	{
		cin>>a>>b;
		add_edge(a,b);
	}
	int level;
	//input level to find no.
	cin>>level;
	//assuming 0 as root node BFS
	cout<<bfs(0,level)<<"\n";
	return 0;
}
