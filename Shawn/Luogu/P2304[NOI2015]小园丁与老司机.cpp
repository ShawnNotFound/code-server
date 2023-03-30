#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>

const int N = 1e5 + 10;

using namespace std;

int ver[N], head[N], nxt[N], edge[N], v[N], head[N], now[N];
int l[N], r[N], u[N], lu[N], ru[N];
int n, m, s, t, maxflow, tot;
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

int tot_lu, tot_ru;

void lu_add(int val, int num)
{
    lu[++ tot_lu].val = val; 
    lu[tot_lu].n = num;
}
void ru_add(int val, int num)
{
    ru[++ tot_ru].val = val;
    ru[tot_ru].n = num;
}

bool cmp(dir_t x, dir_t y)
{
    int vx = x.val, vy = y.val;
    if(vx == vy)
        return x.x < x.y;
    return x.val < y.val;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int xx, yy;
        cin >> xx >> yy;
        int sign_lu = xx - yy;
        int sign_ru = xx + yy;
        lu_add(sign_lu, xx, i);
        ru_add(sign_ru, xx, i);
    }
    
    sort(lu + 1, lu + tot_lu + 1, cmp);
    sort(ru + 1, ru + tot_ru + 1, cmp);

    
}