#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

const int N = 210;
const int INF = 1 << 29;

using namespace std;

int ver[N], head[N], nxt[N], edge[N], d[N], now[N], flag[N][N];
int n, m, u, vv, w, tot, maxflow, s = 1, t;
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
                d[y] = d[x] + 1;
                now[y] = head[y];
                q.push(y);
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
                d[y] = 0;
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k; 
        }
    }
    return flow - rest;
}

int main()
{
    cin >> n >> m;
    t = m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> u >> vv >> w;
        if(!flag[u][vv])
        {
            add(u, vv, w);
            flag[u][vv] = tot;
        }
        else
        {
            edge[flag[u][vv] - 1] += w;
        }
    }

    //cout << "finish read" << endl;

    int flow = 0;
    while(bfs())
        while(flow = dinic(s, INF))
            maxflow += flow;
    
    cout << maxflow << endl;

    return 0;

}