#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
const double PI = 3.141592653589793238460;
char arr[1001][1001];
int vis[1001][1001];
int  n, m;

map<pair<int, int>, pair<pair<int, int>, char> > parent;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isvalid(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    
    if(vis[x][y] == 1 || arr[x][y] == '#')
        return false;

    return true;
}


void bfs(int srcX, int srcY, int d)
{
    vis[srcX][srcY] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(srcX, srcY));

    int flag=0;
    while (!q.empty())
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nX = X + dx[i];
            int nY = Y + dy[i];
            if(isvalid(nX, nY))
            {
                char dir;
                if(dx[i] == 1 && dy[i] == 0)
                    dir = 'D';
                if(dx[i] == -1 && dy[i] == 0)
                    dir = 'U';
                if(dx[i] == 0 && dy[i] == 1)
                    dir = 'R';
                if(dx[i] == 0 && dy[i] == -1)
                    dir = 'L';

                parent[make_pair(nX, nY)] = make_pair(make_pair(X, Y), dir);

                if(arr[nX][nY] == 'B')
                {
                    pair<int, int> end = make_pair(nX, nY);
                    string res = "";
                    while(true)
                    {
                        res += parent[end].second;
                        end = parent[end].first;
                        if(end.first == srcX && end.second == srcY)
                        {
                            break;
                        }
                    }
                    reverse(res.begin(), res.end()); 
                    cout << "YES\n";
                    cout << res.length() << "\n";
                    cout << res;
                    flag= 1;
                    break;
                }

                vis[nX][nY] = 1;
                q.push(mp(nX, nY));
            }
        }
        if(flag)
            break;
    }
    if(!flag)
        cout<<"NO"<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    int srcX, srcY, endX, endY;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 'A') srcX = i , srcY = j;
            if(arr[i][j] == 'B') endX = i , endY = j;
        }
    }
    bfs(srcX, srcY, 0);

    return 0;
}
