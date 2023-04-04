#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

const int N = 3e6 + 10;
const int INF = 1 << 29;

using namespace std;

bool v[100005];
int d[100005], ver[N], nxt[N], cost[N], head[N], edge[N], incf[N], pre[N];
int maxflow, ans, n, m, s, t, mincost, tot = 1;
queue<int> q;

void add(int x, int y, int z, int k)
{
    ver[++ tot] = y, edge[tot] = z, cost[tot] = k, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, cost[tot] = -k, nxt[tot] = head[y], head[y] = tot;
}

bool spfa()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    while(q.size())
        q.pop();

    q.push(s); v[s] = true; d[s] = 0;
    incf[s] = 1 << 30;
    while(q.size())
    {
        int x = q.front(); q.pop(); v[x] = false;
        for(int i = head[x]; i; i = nxt[i])
        {
            if(!edge[i])
                continue;
            int y = ver[i];
            if(d[y] > d[x] + cost[i])
            {
                d[y] = d[x] + cost[i];
                incf[y] = min(incf[x], edge[i]);
                pre[y] = i;
                if(!v[y])
                {
                    q.push(y);
                    v[y] = true;
                }
            }
        }
    }
    if(d[t] == 0x3f3f3f3f)
        return false;
    return true;
}

void Edmonds_Karp()
{
    int x = t;
    while(x != s)
    {
        int i = pre[x];
        edge[i] -= incf[t];
        edge[i ^ 1] += incf[t];
        x = ver[i ^ 1];
    }
    maxflow += incf[t];
    mincost += d[t] * incf[t];
}


int main()
{
    cin >> n >> m;

    s = n + m + 1;
    t = n + m + 2;

    for(int i = 1; i <= n; i ++)
    {
        int num;
        cin >> num;
        add(s, i, num, 0);
    }

    for(int i = 1; i <= n; i ++)
        for(int j = n + 1; j <= n + m; j ++)
        {
            int c;
            cin >> c;
            add(i, j, INF, c);
        }

    for(int i = n + 1; i <= n + m; i ++)
        add(i, t, INF, 0);

    while(spfa())
        Edmonds_Karp();

    cout << mincost << endl;

    return 0;
}