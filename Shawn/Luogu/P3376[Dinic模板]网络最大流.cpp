#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

#define int long long

const int N = 5e3 + 10;
const int  INF = 1 << 29;

using namespace std;

int d[N], ver[N], nxt[N], edge[N], v[N], head[N];
int n, m, s, t, maxflow, flow, tot;

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

void dinic(int x, int flow)
{
    if(x == t)  
        return flow;
    int rest = flow, k, i;
    for(i = head[x]; i && rest; i = nxt[i])
    {
        int y = ver[i];
        now[x] = i;
        if(edge[i] && d[y] == d[x] + 1)
        {
            k = dinic(i, min(rest, edge[i]));
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
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i ++)
    {
        cin >> u >> vv >> w;
        add(u, vv, w);
    }

    while(bfs())
        while(flow = dinic(s, INF))
            maxflow += flow;
        
    cout << maxflow << endl;

    return 0;
}