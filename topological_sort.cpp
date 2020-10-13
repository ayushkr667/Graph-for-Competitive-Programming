#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;
#define ll long long
#define pb push_back
int V;
vector<vector<int> > g;
vector<bool> visited;
void add_edge(int a,int b)
{
	g[a].pb(b);
}

void topo(int a, stack<int> &s)
{
    //mark current node as visited
    visited[a]=true;

    vector<int>::iterator i;
    for ( i = g[a].begin(); i != g[a].end(); i++)
    {
       if(!visited[*i])
            topo(*i, s); 
    }
    //when all the edges of a node is traversed
    //put it into stck
    s.push(a);
}

void topologicalsort()
{
    stack<int>s;
    for (int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
        topo(i,s);
        }
    }
    
    //print stack in pop order
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int e;//no of edges
	cin>>V>>e;//V: no of nodes
    //mark all vertices not visited
	visited.assign(V, false);
    g.assign(V, vector<int>());
    
	int a,b;
	while(e--)
	{
		cin>>a>>b;
		add_edge(a,b);
	}
	//assuming 0 as root node BFS
	topologicalsort();
	return 0;
}
