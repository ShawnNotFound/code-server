#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

const int N = 1e5 + 10;
const int INF = 1 << 29;

using namespace std;

bool flag[110][110];
int head[N], ver[N], edge[N], nxt[N], d[N], now[N], raw_edge[N], rst[N];
int n, m, e, s, t, maxflow, u, v, tot = 1;
queue<int> q;

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, raw_edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, raw_edge[tot] = z, nxt[tot] = head[y], head[y] = tot;
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
            rst[i] = flow - rest;
        }
    }
    return flow - rest;
}

int main()
{
    cin >> m >> n;
    s = n + 1, t = n + 2;
    for(e = 1; 1; e ++)
    {
        cin >> u >> v;
        if(u == v && u == -1)
            break;
        //v += m;
        if(!flag[s][u])
            add(s, u, 1);
        flag[s][u] = true;
        //cout << s << " " << u << " " << 1 << endl;

        if(!flag[v][t])
            add(v, t, 1);
        flag[v][t] = true;
        //cout << v << " " << t << " " << 1 << endl;
        if(!flag[u][v])
            add(u, v, 1);
        flag[u][v] = true;
        //cout << u << " " << v << " " << 1 << endl;
    }
    e --;

    int flow = 0;
    while(bfs())
        while(flow = dinic(s, INF))
            maxflow += flow;
            
    cout << maxflow << endl;



    // for(int x = 1; x <= m; x ++)
    // {
    //     for(int i = head[x]; i; i = nxt[i])
    //     {
    //         int y = ver[i], flow = edge[i];
    //         if(rst[i ^ 1] && x <= n && y <= n)
    //             cout << x << " " << y << endl;
    //         // if(flow >= raw_edge[i] || x > n || y > n) 
    //         //     continue;
    //         // else cout << x << " "  << y << endl; 
    //         //cout << raw_edge[i ^ 1] << " " << flow << " " <<  << endl;
    //     }
    // }
    
    for(int i = 2;i <= tot;i += 2)
    {
        if(ver[i] != s && ver[i ^ 1] != s)
        if(ver[i] != t && ver[i ^ 1] != t)
        if(edge[i ^ 1] != 0)
        {
            cout << ver[i ^ 1] << " " << ver[i] << endl;
        }
    }

    return 0; 
}