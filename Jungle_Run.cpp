#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

char arr[31][31];
int vis[31][31];
int dist[31][31];
int n;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


bool isValid(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > n)
        return false;
    
    if(vis[x][y] == 1 || arr[x][y] == 'T')
        return false;

    return true;
}




void bfs(int i, int j)
{
    vis[i][j]  = 1;
    dist[i][j]  = 0;

    queue<pair<int, int> > q;
    q.push(make_pair(i,j));

    while (!q.empty())  
    {
        int X = q.front().first;
        int Y = q.front().second;
        int d = dist[X][Y];
        q.pop();

        for(int i = 0; i<4; i++)
        {
            int nX = X + dx[i];
            int nY = Y + dy[i];
            if(isValid(nX, nY))
            {
                dist[nX][nY] = d+1;
                vis[nX][nY] = 1;
                q.push(make_pair(nX, nY));
            }
        }
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    int srcX, srcY, endX, endY;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 'S') srcX = i , srcY = j;
            if(arr[i][j] == 'E') endX = i , endY = j;
        }
    }
    
    bfs(srcX, srcY);

    cout<<dist[endX][endY];

    return 0;
}
