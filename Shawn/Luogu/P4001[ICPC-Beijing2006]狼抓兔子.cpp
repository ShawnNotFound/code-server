#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

#define int long long

const int N = 1e4 + 10;
const int INF = 1 << 29;

using namespace std;

int d[N], ver[N], nxt[N], edge[N], v[N], head[N], now[N], flag[N][N];
int n, m, s, t, maxflow, tot = 1;

queue<int> q;

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = z, nxt[tot] = head[y], head[y] = tot;
}

int pos(int x, int y)
{
    return (x - 1) * m + y;
}

bool bfs()
{
    memset(d, 0, sizeof(d));
    while(q.size())
        q.pop();
    
    q.push(s);
    d[s] = 1;
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
                    return true;
            }
        }
    }

    return false;
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
    
    s = 1, t = pos(n, m);

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j < m; j ++)
        {
            int va;
            cin >> va;
            add(pos(i, j), pos(i, j + 1), va);
        }

    for(int i = 1; i < n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            int va;
            cin >> va;
            add(pos(i, j), pos(i + 1, j), va);
        }

    for(int i = 1; i < n; i ++)
        for(int j = 1; j < m; j ++)
        {
            int va;
            cin >> va;
            add(pos(i, j), pos(i + 1, j + 1), va);
        }

    int flow = 0;
    while(bfs())
        while(flow = dinic(s, INF))
            maxflow += flow;

    cout << maxflow << endl;

    return 0;
}