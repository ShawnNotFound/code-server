#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

#define int long long

const int N = 1e4 + 10;
const int INF = 1 << 29;

using namespace std;

int ver[N], edge[N], nxt[N], head[N], d[N], now[N];
int tot, maxflow;
int n, m, s = 1, t, x, u, vv, w;
int times;
queue<int> q;

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, nxt[tot] = head[y], head[y] = tot;
}

bool bfs()
{
    memset(d, 0, sizeof(d));
    while(q.size())
        q.pop();
    
    q.push(s); d[s] = 1; now[s] = head[s];
    while(q.size())
    {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if(!d[y] && edge[i])
            {
                q.push(y);
                now[y] = head[y];
                d[y] = d[x] + 1;
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
            k = dinic(y, min(flow, edge[i]));
            if(!k)
                d[y] = 0;
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}

signed main()
{
    cin >> n >> m >> x;
    t = n;
    for(int i = 1; i <= m; i ++)
    {
        cin >> u >> vv >> w;
        add(u, vv, w);
    }

    int flow = 0;
    while(bfs())
        while(flow = dinic(s, INF))
            maxflow += flow;

    if(!maxflow)
    {
        cout << "Orz Ni Jinan Saint Cow!" << endl;
        return 0;
    }

    if(x % maxflow == 0)
        times = x / maxflow;
    else 
        times = x / maxflow + 1;

    cout << maxflow << " " << times << endl;

    //cout << maxflow << endl;

    return 0;
}