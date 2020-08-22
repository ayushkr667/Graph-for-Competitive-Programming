#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
const double PI = 3.141592653589793238460;
int n, m;
vector<int> arr[100001];
int vis[100001], par[100001];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    par[src] = -1;
    vis[src] = 1;
    while(!q.empty())
    {
        int curr =  q.front();
        q.pop();
        vector<int>::iterator it;
        for(it = arr[curr].begin(); it!=arr[curr].end(); it++)
            if(!vis[*it])
            {
                vis[*it] = 1;
                par[*it] = curr;
                q.push(*it);
            }
    }
}

void print()
{
    stack<int> temp;
    temp.push(n);
    while (1)
    {
        int t = par[n]; temp.push(t);
        if(t ==1)
            break;
        n = t; 
    }
    cout<<temp.size()<<"\n";
    while (!temp.empty())
    {
        cout<<temp.top()<<" "; temp.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(par, -1, sizeof(par));
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    bfs(1);
    if(par[n] == -1)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        print();
    }
    return 0;
}
