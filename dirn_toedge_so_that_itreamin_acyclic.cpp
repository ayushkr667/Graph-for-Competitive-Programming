#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<vector<ll> >adj;
vector<bool>visited;
map<ll, ll>index;

void add_edge(ll u, ll v)
{
    adj[u].pb(v);
}

void direction(ll a, ll b)
{
    if(index[a]<b)
    {
        cout<<"edge direction is from "<<a<<" to "<<b<<"\n";
    }
    else
    {
        cout<<"edge direction is from "<<b<<" to "<<a<<"\n";
    }
    
}




void topo(int a, stack<ll> &s)
{
    visited[a]=true;
    vector<ll>:: iterator i;
    for( i=adj[a].begin();i!=adj[a].end();i++)
    {
        if(!visited[*i])
        {
            topo(*i, s);
        }
    }
    //when all edges are traversed of a node
    s.push(a);
}

void topo_sort()
{
    stack<ll>s;//it will contain topological sort
    for(ll i=0;i<6;i++)
    {
        if(!visited[i])
        {
            topo(i,s);
        }
    }
    ////////////////////////////////
    ll num=0;
    while(!s.empty())
    {
        index[s.top()]=num;
        num++;
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}

int main()
{
    adj.assign(6,vector<ll>());
    visited.assign(6,false);
    //directed edge
    add_edge(0,1);
    add_edge(1,2);
    add_edge(2,3);
    add_edge(3,4);
    add_edge(2,4);
    add_edge(1,4);
    add_edge(1,3);
    add_edge(0,5);
    add_edge(5,2);
    add_edge(5,1);
    topo_sort();
    // enter undirected edges
  ll a=0, b=2;
    direction(a,b);
     a=3, b=0;
    direction(a,b);
     a=5, b=4;
    direction(a,b);

    return 0;
}