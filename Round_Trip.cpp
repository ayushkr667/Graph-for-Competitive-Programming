/*-------------------------------*
| Name: Ayush Kumar              |
| College: SOE, CUSAT            |
| Dept: CSE                      |
| Email: ayushkr667@gmail.com    |
*-------------------------------*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
const double PI = 3.141592653589793238460;
ll n, m, t;
vector<int>arr[100001];
int vis[100001], par[100001];
stack<int> res;
bool check(int node, int p)
{
    res.push(p);
    res.push(node);
    int count = 1;
    while (node != p)
    {
        node = par[node];
        res.push(node);
        count++;
    }
    if(count >= 3)
    {
        return true;
    }
    return false;
}

bool dfs(int node, int p)
{
    //cout<<"call "<<node<<" parent "<<p<<"\n";
    vis[node] = 1;
    par[node] = p;
    vector<int>:: iterator it;
    for(it = arr[node].begin(); it!=arr[node].end(); it++)
    {
        if((vis[*it]==1) && *it != p)
        {
            if(check(node, *it))
                return true;
            else
            {
                while (!res.empty())
                {
                    res.pop();
                }   
            }
            
        }

        if(!vis[*it])
        {
            if(dfs(*it, node))
                return true;
        }
    }
    return false;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        arr[a].pb(b); arr[b].pb(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(dfs(i, -1))
            {
                cout<<res.size()<<"\n";
                while (!res.empty())
                {
                    cout<<res.top()<<" "; res.pop();
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
