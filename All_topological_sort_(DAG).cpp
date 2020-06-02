#include<iostream>
#include<stdio.h>
#include<vector>
#define ll long long
#define pb push_back
using namespace std;

vector<vector<int> >adj;
vector<int> indegree;
int n;

void add_edge(int u, int v)
{
    adj[u].pb(v);
    indegree[v]++;
}

void alltopo_recursive(vector<int>& res, vector<bool>& visited)
{
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        //if indegree is 0 and not visited yet
        if(indegree[i]==0 &&  !visited[i])
        {
            vector<int>:: iterator it,j;
            for(it=adj[i].begin();it!=adj[i].end();it++)
            {
                //reduce indegree of adjacent vertices
                indegree[*it]--;
            }
            res.pb(i);
            visited[i]=true;
            alltopo_recursive(res,visited);
            //reset visited, res and indegree for 
            //back tracking
            visited[i] = false;
            res.erase(res.end()-1);
            for(j=adj[i].begin();j!=adj[i].end();j++)
            {
                indegree[*j]++;
            }
            flag=true;
        }

    }
    // we reach here if all vertices are visited
    //print solution
    if(!flag)
    {
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}

void alltopo()
{
    vector<bool> visited;
    visited.assign(n,false);
    vector<int> res;
    alltopo_recursive(res,visited);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    n=6;
    for (int i = 0; i < n; i++) 
    {
        indegree.push_back(0); 
    } 
    adj.assign(n,vector<int>());
    add_edge(5,2);
    add_edge(5,0);
    add_edge(4,0);
    add_edge(4,1);
    add_edge(2,3);
    add_edge(3,1);
    alltopo();
}


//OUTPUT
/*
4 5 0 2 3 1 
4 5 2 0 3 1 
4 5 2 3 0 1 
4 5 2 3 1 0 
5 2 3 4 0 1 
5 2 3 4 1 0 
5 2 4 0 3 1 
5 2 4 3 0 1 
5 2 4 3 1 0 
5 4 0 2 3 1 
5 4 2 0 3 1 
5 4 2 3 0 1 
5 4 2 3 1 0 */
