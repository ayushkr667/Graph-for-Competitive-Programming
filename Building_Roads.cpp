#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
const double PI = 3.141592653589793238460;

vector<int>arr[100001];
int vis[100001];
int n, m;
void dfs(int node)
{
    vis[node] = 1;
    vector<int>:: iterator it;
    for(it = arr[node].begin(); it!=arr[node].end(); it++)
        if(!vis[*it])
            dfs(*it);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;   cin>>a>>b;
        arr[a].pb(b);   arr[b].pb(a);
    }
    vector<int> ans;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            ans.pb(i);  dfs(i);
        }
    }
    if(ans.size()-1)
    {
        cout<<ans.size()-1<<"\n";
        for(int i=1; i<ans.size(); i++)
        {
            cout<<ans[i]<<" "<<ans[i-1]<<"\n";
        }
    }
    else
    {
        cout<<0<<"\n";
    }
    
    return 0;
}
