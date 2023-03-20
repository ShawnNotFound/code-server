#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

const int M = 5e2 + 10;
const int N = 5e5 + 10;
const int INF = 1 << 29;

using namespace std;

int map[M][M], x[M][M], y[M][M];
int m, n, tot = 1, s, t, cntx, cnty;
int head[N], ver[N], edge[N], nxt[N], d[N], now[N];
int maxflow;
pair<int, int> match[N];
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


int main()
{
    memset(map, 0x3f, sizeof(map));
    cin >> m >> n;
    s = 2 * m * n + 1;
    t = 2 * m * n + 2;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> map[i][j];


    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(map[i][j] == 2)
                continue;

            if(j == 1)
                x[i][j] = ++ cntx;
            else
            {
                if(map[i][j - 1] != 2)
                    x[i][j] = x[i][j - 1];
                else
                    x[i][j] = ++ cntx;
            }

            if(i == 1)
                y[i][j] = ++ cnty;
            else
            {
                if(map[i - 1][j] != 2)  
                    y[i][j] = y[i - 1][j];
                else
                    y[i][j] = ++ cnty;
            }
        }
    }


    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(map[i][j] == 1 || map[i][j] == 2)
                continue;
            match[tot + 1] = make_pair(i, j);
            match[tot + 2] = make_pair(i, j);
            //cout << "match[tot] " << tot << " has been set to " << i << "," << j << endl;
            add(x[i][j], y[i][j] + n * m, 1);
        }
    }


    for(int i = 1; i <= cntx; i ++)
        add(s, i, 1);
    for(int i = 1; i <= cnty; i ++)
        add(i + n * m, t, 1);

    int flow = 0, maxflow = 0;

    while(bfs())
        while(flow = dinic(s, INF))
        {
            maxflow += flow;
        }

    cout << maxflow << endl;

    // for(int i = head[s]; i; i = nxt[i])
    //     if(!edge[i])
    //     {
    //         //cout << "find " << i << endl;
    //         for(int j = head[ver[i]]; j; j = nxt[j])
    //         {
    //             if(!edge[j])
    //             {
    //                 cout << ver[j] - n * m << " " << ver[j ^ 1] << endl;
    //                 cout << match[ver[j] - n * m].first << " " << match[ver[j] - n * m].second << endl;
    //                 cout << match[ver[j ^ 1]].first << " " << match[ver[j ^ 1]].second << endl;
    //                 cout << endl;
    //             }
    //         }
    //     }

    // for(int i = 2;i <= tot;i += 2)
    // {
    //     if(ver[i] != s && ver[i ^ 1] != s)
    //     if(ver[i] != t && ver[i ^ 1] != t)
    //     if(edge[i ^ 1] != 0)
    //     {
    //         cout << match[ver[i ^ 1]].first << " " << match[ver[i ^ 1]].second << endl;
    //     }
    // }

    for (int e = head[s]; e; e = nxt[e]) {
        for (int j = head[ver[e]]; j; j = nxt[j]) {
            if (!edge[j] && edge[j^1] && ver[j] ^ s) {
                cout << match[ver[j ^ 1]].first << ' ' << match[ver[j ^ 1]].second << endl;
            }
        }
    }

    return 0;

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}