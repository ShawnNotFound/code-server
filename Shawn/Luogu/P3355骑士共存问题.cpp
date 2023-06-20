#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>

#define int long long 

const int N = 1e6 + 10;
const int INF = 1 << 29;

using namespace std;

int d[N], ver[N], nxt[N], edge[N], v[N], head[N], now[N], flag[1010][1010];
int n, m, s, t, maxflow, tot = 1, u, vv, w;
int dirx[10] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
int diry[10] = {0, 2, -2, 2, -2, 1, -1, 1, -1}; 
queue<int> q;

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, nxt[tot] = head[y], head[y] = tot;
}

int pos(int x,int y)
{
	return (x - 1) * n + y;
}

bool bfs()
{
    memset(d, 0, sizeof(d));
    while(q.size())
        q.pop();
    
    q.push(s); d[s] = 1;
    now[s] = head[s];

    while(q.size())
    {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if(!d[y] && edge[i])
            {
                d[y] = d[x] + 1;
                q.push(y);
                now[y] = head[y];
                if(y == t)
                    return 1;
            }
        }
    }
    return 0;
}

int dinic(int x, int flow)
{
    if(x == t)  
        return flow;
    int rest = flow, k, i;
    for(i = now[x]; i && rest; i = nxt[i])
    {
        int y = ver[i];
        now[x] = i;
        if(edge[i] && d[y] == d[x] + 1)
        {
            k = dinic(y, min(rest, edge[i]));
            if(!k)
                d[y] = INF;
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}


signed main()
{
    cin >> n >> m;

    t = n * n + 1;

    for(int i = 1; i <= m; i ++)
    {
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;

        flag[tmpx][tmpy] = 1;        
    }

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            // if(((i + j) & 1) && !flag[i][j])
            //     add(s, pos(i, j), 1);
            // else if(((i + j) & 0) && !flag[i][j])
            //     add(pos(i, j), t, 1);

            if((i + j) & 1)
            {
                if(!flag[i][j])
                    add(s, pos(i, j), 1);
            }

            else
            {
                if(!flag[i][j])
                    add(pos(i, j), t, 1);
            }
        }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(!((i + j) & 1))
                continue;
            for(int k = 1; k <= 8; k ++)
            {
                int xx = i + dirx[k];
                int yy = j + diry[k];

                if((xx >= 1 && xx <= n) && (yy >= 1 && yy <= n) && !flag[xx][yy])
                    add(pos(i, j), pos(xx, yy), INF);
            }
        }
    }

    int flow = 0;
    while(bfs())
        while(flow = dinic(s, INF))
            maxflow += flow;

    cout << n * n - m - maxflow << endl;

    return 0;
}