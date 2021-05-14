#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> arr[2001];
int vis[2001];
int col[2001];
bool dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c;

    vector<int>:: iterator it;
    for(it= arr[node].begin(); it!=arr[node].end(); it++)
    {
        if(!vis[*it])
        {
            bool res = dfs(*it, (!c));
            if(res == false) 
                return false;
        }

        else if(col[node] == col[*it])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        int n, m, a, b;
        cin>>n>>m;
        for(int j=1; j<=n; j++)
            arr[j].clear(), vis[j] =  0;

        //make the adjacency graph
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            arr[a].pb(b);
            arr[b].pb(a);
        }

        bool flag  = true; //to check if graph is bipartite

        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                bool res = dfs(i, 0); //colour of 1st node is 0

                if(res ==  false)
                    flag = false;
            }
        }
        cout<<"Scenario #"<<tc<<":"<<"\n";

        if(!flag)
            cout<<"Suspicious bugs found!"<<"\n";
        else
        {
            cout<<"No suspicious bugs found!"<<"\n";
        }  
    }
    return 0;
}
