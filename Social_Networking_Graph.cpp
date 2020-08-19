#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

vector<int> arr[1000001];

int vis[1000001];
int dist[1000001];
int level[1000001];//nodes at level i

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    dist[src]  =0;
    level[dist[src]]++;
    while(!q.empty())
    {
        int curr  = q.front();
        q.pop();
        vector<int>::iterator it;
        for(it  = arr[curr].begin(); it!=arr[curr].end(); it++)
        {
            if(!vis[*it])
            {
                dist[*it] = dist[curr] + 1;
                q.push(*it);
                vis[*it] = 1;
                level[dist[*it]] ++ ;
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a,b , src, d, q;

    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    cin>>q;
    while (q--)
    {
        cin>>src>>d;
        for(int i=0; i<=n; i++)
        {
            level[i] = 0;
            vis[i] = 0;
        }
        bfs(src);
        cout<<level[d]<<"\n";
    }
    

    return 0;
}
