#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

vector<int> arr[1001];
const int maxN = 10; //log2(N)
int level[1001], LCA[1001][maxN+1];//lca table to store 2^i th parent of node
void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    LCA[node][0] = par; //immidiate parent of node

    vector<int>:: iterator child;
    for(child = arr[node].begin(); child!=arr[node].end(); child++)
        if(*child != par)
            dfs(*child, lvl+1, node);
}
void initialize(int n)
{
    dfs(1, 0, -1);//root is 1
    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //if 2^(i-1) th parent exist then only 2^i th may exist 
            if(LCA[j][i-1] != -1)
            {
                int par = LCA[j][i-1];
                // and it is equal to 2^(i-1) th parent of 2^(i-1)th parent
                LCA[j][i] =  LCA[par][i-1];
            }
        }  
    }    
}
int getLCA(int a, int b)
{
    if(level[b] < level[a]) swap(a, b);//to make level b bigger
    int d = level[b] - level[a];
    while (d > 0)
    {
        int i = log2(d);//max power of 2 lesser than d
        b =  LCA[b][i]; //get 2^i th parent
        d -= 1 << i ;//subtract 2^i 
    }
    //if both comes same then they are in same line
    if(a == b) return a;
    for(int i=maxN; i>=0; i--)
    {
        //if 2^i th parent exists and are not equal
        if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i], b = LCA[b][i];  
        }
    }
    return LCA[a][0]; //return the immidiate parent 
}
/////////////////////////////////////////////////////////////////////////////////
// above is the code for lca dont forgot to inititalize lca table in main()
// and call initialize function to fill LCA table from main()
/////////////////////////////////////////////////////////////////////////////////
int getDist(int a, int b)
{
    int lca = getLCA(a, b);
    return level[a] + level[b] - 2*level[lca];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, a, b, q;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 0 ; j<=maxN; j++)
            LCA[i][j] = -1 ;//-1 if no parent
    }
    
    for (int i = 1; i < n; i++)
    {
        cin>>a>> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    initialize(n);//initialize the lca table
    cin>>q;
    while (q--)
    {
        cin>>a>>b;
        cout<<getDist(a,b)<<"\n";
    }
    return 0;
}