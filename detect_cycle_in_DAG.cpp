#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ll long long
#define pb push_back

vector<vector<ll> >adj;
vector<bool>visited;
vector<bool>rec;

void add_edge(ll u, ll v)
{
adj[u].pb(v);
//adj[v].pb(u);//
}

//function to check cycle using modified dfs
bool cyclic(ll v)
{
    if(!visited[v])
    {
        visited[v]=true;
        rec[v]=true;
        vector<ll>::iterator i;
        for(i=adj[v].begin(); i!=adj[v].end(); i++)
        {
            if(!visited[*i] && cyclic(*i))
                return true;

            else if(rec[*i])
                return true;
        }
    }
    // remove the vertex from rec vector
    rec[v] = false;

    return false;
}

// function which return cyclic or not
bool is(ll n)
{
    for(ll i=0; i<n; i++)
    {
        if(cyclic(i))
            return true;
    }
    return false;
}

int main()
{
    adj.assign(3, vector<ll>());
    visited.assign(3, false);
    rec.assign(3, false);
   // add_edge(0,1);
   // add_edge(0,2);
   // add_edge(1,2);
   // add_edge(2,0);
   // add_edge(2,3);
   // add_edge(3,3);
      add_edge(0,1);
      add_edge(1,2);
     // add_edge()
    if(is(3))
            cout<<"graph has cycle"<<"\n";
    
    else
            cout<<"cycle not found in this graph"<<"\n";
    return 0;
}