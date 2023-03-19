#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

const int M = 1e3 + 10;
const int N =  5e5 + 10;
const int INF = 1 << 29;

using namespace std;

char map[M][M];
int m, n, ltot, rtot, tot = 1, s, t, cnt;
bool flag = true;
int head[N], ver[N], edge[N], nxt[N], d[N], now[N], raw_edge[N], rst[N];
int maxflow, u, v;
queue<int> q;

struct tai_nan_le_wo_yao_tui_sai
{
    int num, x, y;
}l[N], r[N];// 用于二分图匹配

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

    cin >> m >> n;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> map[i][j];

    //cout << "读入完成" << endl;
    
    // cout << map[1][1] << endl;

    // for(int i = 0; i <= 5; i ++)
    // {
    //     for(int j = 0; j <= 5; j ++)
    //         cout << map[i][j] << " ";
    //     cout << endl;
    // }

    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(flag && map[i][j] == '*')  
            {
                cout << "ltot ++ on " << i <<"," << j << endl;
                l[++ ltot] = {++ cnt, i, j};
                flag = false;
            }
            if(map[i][j] == '#')
                flag = true;
        }
        flag = true;
    }
        
    for(int i = 1; i <= n; i ++)
    {
        flag = true;
        for(int j = 1; j <= m; j ++)
        {
            if(flag && map[i][j] == '*')  
            {
                cout << "rtot ++ on " << i <<"," << j << "; where map[i][j] = " << map[i][j] <<endl;
                r[++ rtot] = {++ cnt, i, j};
                flag = false;
            }
            if(map[i][j] == '#')
                flag = true;
        }
    }
    cout << ltot << " " << rtot << " " << cnt << endl;

    //cout << "图存储完成" << endl;

    s = cnt + 2, t = cnt + 3;

    for(int i = 1; i <= ltot; i ++)
    {
        add(s, i, 1);
        //cout << s << " " << i << " 1" << endl;
    }
    for(int i = ltot + 1; i <= rtot + ltot; i ++)
    {
        add(i, t, 1);
        //cout << i << " " << t << " 1" << endl;
    }
    for(int i = 1; i <= ltot; i ++)
        for(int j = ltot + 1; j <= rtot + ltot; j ++)
        {
            add(i, j, INF);
            //cout << i << " " << j << " 1" << endl;
        }

    //cout << "预处理完成" << endl;

    int flow = 0;
    while(bfs())
        while(flow = dinic(s, INF)) 
            maxflow += flow;

    cout << maxflow << endl;

    // for(int i = 2;i <= ltot;i += 2)
    // {
    //     if(ver[i] != s && ver[i ^ 1] != s)
    //     if(ver[i] != t && ver[i ^ 1] != t)
    //     if(edge[i ^ 1] != 0)
    //     {
    //         //cout << map[l[ver[i ^ 1]].x][l[ver[i ^ 1]].y] << endl;
    //         cout << l[ver[i ^ 1]].x << " " << l[ver[i ^ 1]].y << endl;
    //     }
    // }
    // for(int i = ltot + 2;i <= tot;i += 2)
    // {
    //     if(ver[i] != s && ver[i ^ 1] != s)
    //     if(ver[i] != t && ver[i ^ 1] != t)
    //     if(edge[i ^ 1] != 0)
    //     {
    //         //cout << map[r[ver[i ^ 1]].x][r[ver[i ^ 1]].y] << endl;
    //         cout << r[ver[i ^ 1]].x << " " << r[ver[i ^ 1]].y << endl;
    //     }
    // }

    return 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}