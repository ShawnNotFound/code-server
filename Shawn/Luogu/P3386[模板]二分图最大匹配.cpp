#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

const int N = 5e4 + 10;
const int inf = 1 << 29;

using namespace std;

int head[N], ver[N], edge[N], nxt[N], d[N], now[N];
int n, m, e, s = 0, t = N - 9, maxflow, u, v, tot;
queue<int> q;

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, nxt[tot] = head[y], head[y] = tot;
}

bool bfs()
{
    memset(d, 0, sizeof(d));
    while(q.size()) q.pop();
    q.push(s); d[s] = 1; now[s] = head[s];
    while(q.size())
    {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i])
        {
            q.push(ver[i]);
            now[ver[i]] = head[ver[i]];
            d[ver[i]] = d[x] + 1;
            if(ver[i] == t)
                return 1;
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
        now[x] = i;
        if(edge[i] && d[ver[i]] == d[x] + 1)
        {
            k = dinic(ver[i], min(rest, edge[i]));
            if(!k)
                d[ver[i]] = 0;
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}

int main()
{
    cin >> n >> m >> e;
    for(int i = 1; i <= e; i ++)
    {
        cin >> u >> v;
        add(s, u, 1);
        add(u, v, 1);
        add(u, v, 1);
    }
    int flow = 0;
    while(bfs())
        while(flow = dinic(s, inf))
            maxflow += flow;

    cout << maxflow << endl;
    return 0; 
}