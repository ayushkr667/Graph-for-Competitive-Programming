/*-------------------------------*
| Name: Ayush Kumar              |
| College: SOE, CUSAT            |
| Dept: CSE                      |
| Site: CSES                     |
| Email: ayushkr667@gmail.com    |
*-------------------------------*/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define INF (ll) 1e18
const double PI = 3.141592653589793238460;
vector<pair<ll, ll> > adj[100001];
ll n, m;
vector<ll> dist(100001, INF);
 
struct comp{
    bool operator() (const ll &a, const ll &b) const{
        return dist[a] < dist[b];
    }
 
};
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, p;
        cin>>a>>b>>p; 
        adj[a].pb(mp(b, p));
    }
 
 
    //priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    set<pair<ll, ll> > pq;
    
    //pq.push(mp(0, 1));// to calculate sortest path from 1
    pq.insert(mp(0, 1));
    dist[1] = 0;
 
    // while (!pq.empty()) 
    // {
    //     ll curr =  pq.top().second;// node
    //     ll curr_d = pq.top().first;//dist
    //     pq.pop();
 
    //     vector< pair<ll, ll> >::iterator edge;
    //     for(edge = adj[curr].begin(); edge !=adj[curr].end(); edge++)
    //     {
    //         if((curr_d + edge->second) < dist[edge->first])
    //         {
    //             dist[edge->first] = curr_d + edge->second;
    //             pq.push(mp(dist[edge->first], edge->first));
    //         }
    //     }
    // }
    while(!pq.empty())
    {
        pair <ll,ll> f = *pq.begin(); 
        pq.erase(pq.begin());
        ll e = f.second;
        vector< pair<ll, ll> >::iterator x;
        for( x = adj[e].begin(); x != adj[e].end(); x++)
        {
            ll to=x->first; ll len=x->second;
            if(dist[e]+len < dist[to])
            {
                pq.erase(mp(dist[to],to));
                dist[to] = dist[e] + len;
                pq.insert(mp(dist[to],to));
            }
        }
    }
 
    for (ll i =  1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}