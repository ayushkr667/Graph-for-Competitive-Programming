#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

ll dist[100001];
ll vis[100001];
vector<ll> arr[100001];
vector<ll>primes;

bool isprime(ll n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n % i == 0) return false;
    }
    return true; 
}


bool is_path(ll a, ll b)
{
    ll cnt = 0;
    while(a > 0)
    {
        if((a % 10) !=(b % 10))  cnt++;
        
        a/=10, b/10;
    }

    if(cnt==1)  return true;
    else return  false;
}

void build_graph()
{
    for(ll i=1000; i<=9999; i++)
    {
        if(isprime(i))
            primes.pb(i);
    }   

    for(ll i=0; i<primes.size(); i++)
    {
        for(int j = i+1; j<primes.size(); j++)
        {
            ll u = primes[i];
            ll v = primes[j];

            if(is_path(u, v))
            {
                arr[u].pb(v);   arr[v].pb(u);
            }
        }
    }
}


void bfs(int src)
{
    queue<ll> q;
    q.push(src);

    dist[src] = 0;
    vis[src] = 1;

    while(!q.empty())
    {
        int curr =  q.front();
        q.pop();

        vector<ll>::iterator it;
        for(it = arr[curr].begin(); it!=arr[curr].end(); it++)
            if(!vis[*it])
            {
                vis[*it] = 1;
                dist[*it] = dist[curr] + 1;
                q.push(*it);
            }

    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    build_graph();  
    ll t;   cin>>t;
    while(t--)
    {
        ll a, b;     cin>>a>>b;

        for(ll i=1000; i<=9999; i++)
        {
            dist[i] = -1;   vis[i] = 0;
        }

        bfs(a);

        if(dist[b] == -1)
            cout<<"Impossible\n";
        else
            cout<<dist[b]<<"\n";
    }
    return 0;
}