#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

typedef long long ll;

const ll N = 1e4 + 10;
const ll INF = 1 << 29;

using namespace std;

ll ver[N], edge[N], nxt[N], head[N], d[N], now[N], flag[N][N];
ll tot = 1, maxflow;
ll n, m, s = 1, t, x, u, vv, w;
ll times;
queue<ll> q;

void add(ll x, ll y, ll z)
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
        ll x = q.front(); q.pop();
        for(ll i = head[x]; i; i = nxt[i])
        {
            ll y = ver[i];
            if(!d[y] && edge[i])
            {
                q.push(y);
                now[y] = head[y];
                d[y] = d[x] + 1;
                if(y == t)
                    return 1;
            }
        }
    }
    return 0;
}

ll dinic(ll x, ll flow)
{
    if(x == t)
        return flow;
    ll rest = flow, k, i;
    for(i = now[x]; i && rest; i = nxt[i])
    {
        ll y = ver[i];
        now[x] = i;
        if(edge[i] && d[y] == d[x] + 1)
        {
            k = dinic(y, min(flow, edge[i]));
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
    cin >> n >> m >> x;
    t = n;
    for(ll i = 1; i <= m; i ++)
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

    ll flow = 0;
    while(bfs())
        while(flow = dinic(s, INF))
            maxflow += flow;

    if(!maxflow)
    {
        cout << "Orz Ni Jinan Saint Cow!" << endl;
        return 0;
    }

    if(x % maxflow == 0)
        times = x / maxflow;
    else 
        times = x / maxflow + 1;

    cout << maxflow << " " << times << endl;

    //cout << maxflow << endl;

    return 0;
}