#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
char arr[1001][1001];
ll vis[1001][1001];

ll n, m;

bool isvalid(ll i, ll j)
{
    if(i > n || i < 1 || j > m || j < 1)
        return false;

    if(vis[i][j] == true || arr[i][j] == '#')
        return false;

    return true;
}


void dfs(ll i, ll j)
{
    vis[i][j] = true;
    //right
    if( isvalid(i,j+1))
    {
        dfs(i, j+1);
    }
    //left
    if(isvalid(i, j-1))
    {
        dfs(i, j-1);
    }
    //top
    if(isvalid(i-1, j))
    {
        dfs(i-1, j);
    }
    //bpttom
    if(isvalid(i+1, j))
    {
        dfs(i+1, j);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;

    for(ll i=1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cin>>arr[i][j];
        }
    }

    ll cnt = 0;

    for(ll i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j] == '.' && vis[i][j] == false)
            {
                dfs(i, j), cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
