#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

vector<int> arr[100001];
int in[100001];
int low[100001];
int vis[100001];
int timer;

bool hasBridge;
vector<pair<int, int> > edgelist;
void dfs(int node, int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;

    vector<int>:: iterator it;
    for(it = arr[node].begin(); it!=arr[node].end(); it++)
    {

        if(*it == par) continue;
        if(vis[*it])
        {
            //this is back edge
            low[node] = min(low[node], in[*it]);

            //check current node is decendent
            if(in[node]  > in[*it])
            {
                edgelist.pb(make_pair(node, *it));
            }
        }

        else
        {
            dfs(*it, node);
            if(low[*it] > in[node])
            {
               //node to child is bridge
               hasBridge = true;
               return; 
            }

            //if else condition is not
            //then that is forward edge node->child
            edgelist.pb(make_pair(node, *it));
            low[node]  = min(low[node], low[*it]);
        }
        
    }
}





int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a, b;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    dfs(1, -1);

    if(hasBridge)
    {
        cout<<0;
    }
    else
    {
        vector<pair<int, int> >::iterator it;
        for(it = edgelist.begin(); it!=edgelist.end(); it++)
        {
            cout<<it->first<<" "<<it->second<<"\n";
        }
    }

    return 0;
}