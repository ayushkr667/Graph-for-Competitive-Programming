#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
const double PI = 3.141592653589793238460;
vector<pair<int, int> > adj[1001]; //adjacency matrix
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, w;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b>>w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w)); //comment this if directed graph
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(n+1, INT_MAX);
    pq.push(mp(0, 1));// to calculate sortest path from 1
    dist[1] = 0;
    
    while (!pq.empty()) 
    {
        int curr =  pq.top().second;// node
        int curr_d = pq.top().first;//dist
        pq.pop();

        vector< pair<int, int> >::iterator edge;
        for(edge = adj[curr].begin(); edge !=adj[curr].end(); edge++)
        {
            if((curr_d + edge->second) < dist[edge->first])
            {
                dist[edge->first] = curr_d + edge->second;
                pq.push(mp(dist[edge->first], edge->first));
            }
        }
    }

    for (int i =  1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}

