
//by using bellman ford algorithm with
//modificaation
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int v,e,inc=0;//vertex,edge
vector<vector<int> >vect;

void add_edge(int u, int v, int wt)
{
vect[inc].pb(u);//0th index is source
vect[inc].pb(v);//1st is destination
vect[inc].pb(wt);//2nd is weight
inc++;
}

bool isNegCycleBellmanFord(int src, int dist[])
{
	//initialize all vertices except src INFINITE
	for(int i=0; i<v; i++)
		dist[i]=INT_MAX;

	dist[src]=0;//source with 0;
	//relax all vertices v-1 times
	for(int i=0; i<v-1; i++)
	{
		for(int j=0; j<e; j++)
		{
			int u=vect[j][0];
			int v=vect[j][1];
			int wt=vect[j][2];
			if(dist[u] != INT_MAX && dist[u]+wt < dist[v])
			{
				dist[v] = dist[u]+wt;
			}
		}
	}
	//as above operation gives minimum from source to 
	//every gurantly is no negative wt cycle
	//evaluate onece more if still there is change
	//in wt means negative wt cycle exists
	for(int j=0; j<e; j++)
	{
		int u=vect[j][0];
		int v=vect[j][1];
		int wt=vect[j][2];
		if(dist[u] != INT_MAX && dist[u]+wt < dist[v])
		{
			return true;
		}
	}
	return false;
}

bool isNegCycleDisconnected()
{
	vector<bool> visited;
	visited.assign(v, false);
	int dist[v];
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			if(isNegCycleBellmanFord(i, dist))
			{
				return true;
			}
			//mark all vertices visited 
			//of above call
			for(int i=0;i<v;i++)
			{
				if(dist[i] != INT_MAX)
					visited[i]=true;
			}
		}
	}
	return false;
}


int main()
{

     v = 5; // Number of vertices in graph 
     e = 8; // Number of edges in graph
    vect.assign(e,vector<int>());
    add_edge(0,1,-1);
    add_edge(0,2,4);
  	add_edge(1,2,3);
  	add_edge(1,3,2);
  	add_edge(1,4,2);
  	add_edge(3,2,5);
  	add_edge(3,1,1);
  	add_edge(4,3,-3);
  	/*
  	add_edge(0, 1, 1);
  	add_edge(1,2,2);
  	add_edge(2,0,-6);
  	*/
    if (isNegCycleDisconnected()) 
        cout << "Yes"; 
    else
        cout << "No"; 
  
    return 0; 


}