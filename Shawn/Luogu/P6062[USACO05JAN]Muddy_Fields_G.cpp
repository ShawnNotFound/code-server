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
int hang[M][M], lie[M][M], ghang[N], glie[N];
int m, n, ltot, rtot, tot = 1, s, t, cnthang, cntlie;
bool nw = true, f[M][M];
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

    cin >> n >> m;
    s=2 * n * m + 1;
	t=2 * n * m + 2;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> map[i][j];

    for(int i = 1;i <= n; i ++)
    {
		for(int j = 1;j <= m; j ++)
        {
			if(map[i][j] == '.')
                continue;
			if(j == 1)
				hang[i][j] = ++ cnthang;
			else
            {
				if(map[i][j-1] != '.')
					hang[i][j] = hang[i][j-1];
				else
					hang[i][j] = ++ cnthang;
			}

			if(i == 1)
				lie[i][j] = ++ cntlie;
			else
            {
				if(map[i - 1][j] != '.')
					lie[i][j] = lie[i - 1][j];
				else
					lie[i][j] = ++ cntlie;
			}
		}
	}

	for(int i = 1;i <= n; i ++)
    {
		for(int j = 1;j <= m; j ++)
        {
			ghang[hang[i][j]] = i;
			glie[lie[i][j]] = j;
		}
	}

	for(int i = 1;i <= n; i ++)
    {
		for(int j = 1;j <= m; j ++)
        {
			if(map[i][j] == '.')
                continue;
			add(hang[i][j], lie[i][j] + n * m, 1);
		}
	}
	for(int i = 1;i <= cnthang; i ++)
		add(s, i, 1);
    
	for(int i = 1;i <= cntlie; i ++)
		add(i + n * m, t, 1);
    
	int flow = 0, maxflow = 0;
	while(bfs())
        while(flow = dinic(s, INF))
		    maxflow += flow;
            
	cout << maxflow << endl;

    return 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}