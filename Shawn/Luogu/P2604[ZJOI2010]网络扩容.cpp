#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

const int N = 1e4 + 10;

using namespace std;

int n, m, addflow;
int u, v, w, aw;

void add(int x, int y, int z, int k)
{
    ver[++ tot] = y, edge[tot] = z, aflow[tot] = k, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, aflow[tot] = k, nxt[tot] = head[y], head[y] = tot;
}

bool bfs()
{
    memset(d, 0, sizeof(d));
    while(q.size())
        q.pop();
    
    q.push(s);d[s] = 1;
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
    for(int i = now[x]; i && rest; i = nxt[i])
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
}

int main()
{
    cin >> n >> m >> addflow;
    for(int i = 1;i <= m; i ++)
    {
        cin >> u >> v >> w >> aw;
        add(u, v, w, aw);
    }

    
}