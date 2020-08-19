#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
ll vis[10001];

ll maxDist, maxNode;
vector<ll> arr[10001];
void dfs(ll node, ll d)
{
vis[node] = 1;
if( d>maxDist )
{maxDist = d,    maxNode  = node;}

vector<ll>:: iterator it;
for(it = arr[node].begin(); it!= arr[node].end(); it++)
    if(!vis[*it])
        dfs(*it, d+1);

}

int main()
{
ll t;  cin>>t;
while(t--)
{
    int a,b;
    cin>>a>>b;
    arr[a].pb(b);
    arr[b].pb(a);
}

maxDist  = -1;
dfs(1, 0 );

for (ll i = 0; i < 10001; i++)
{
    vis[i] = 0;
}

dfs(maxNode, 0);
cout<<maxDist;

return 0;
}
