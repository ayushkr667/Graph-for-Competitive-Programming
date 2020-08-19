#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

struct edge
{
    int a;
    int b;
    int w;
};
edge arr[100000];
int par[10001];

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int a) 
{
    if(par[a] == -1) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    par[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, w;
    cin>>n>>m;

    memset(par, -1, sizeof(par));

    for(int i=0; i<m; i++)
    {
        cin>>arr[i].a>>arr[i].b>>arr[i].w;
    }
    int sum = 0; 
    sort(arr, arr+m, comp);

    for(int i=0; i<m; i++)
    {
        a = find(arr[i].a); //find the parent
        b = find(arr[i].b);

        if(a != b)
        {
            sum  += arr[i].w;
            merge(a, b);
        }
    }

    cout<<sum;
    return 0;
}

