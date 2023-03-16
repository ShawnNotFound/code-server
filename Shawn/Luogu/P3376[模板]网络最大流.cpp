#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

typedef long long ll;

const ll INF = 1e9;
const ll N = 1e4 + 10;

using namespace std;

ll n, m, s, t, u, vv, w, maxflow, flow, tot = 1;
ll ver[N], edge[N], nxt[N], head[N];
ll v[N], incf[N], pre[N], flag[N][N];

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, nxt[tot] = head[y], head[y] = tot;
}

ll bfs()
{
    //cout << "bfs-ing" << endl;
    memset(v, 0, sizeof(v));
    queue<ll> q;
    q.push(s); v[s] = 1;
    incf[s] = INF;
    while(q.size())
    {
        ll x = q.front(); q.pop();
        for(ll i = head[x]; i; i = nxt[i])
        {
            if(edge[i])
            {
                ll y = ver[i];
                if(v[y])
                    continue;
                incf[y] = min(incf[x], edge[i]);
                pre[y] = i;
                v[y] = 1;
                q.push(y), v[y] = 1;
                if(y == t)
                    return 1;
            }
        }
    }
    return 0;
}

void update()
{
    //cout << "updating" << endl;
    ll x = t;
    while(x != s)
    {
        //cout << "in while" << endl;
        ll i = pre[x];
        edge[i] -= incf[t];
        edge[i ^ 1] += incf[t];
        x = ver[i ^ 1];
    }
    maxflow += incf[t];
}

int main()
{
    cin >> n >> m >> s >> t;
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
    //cout << "finish read" << endl;

    while(bfs())
    {
        //cout << "bfs success!" << endl;
        update();
        //cout << "update success!" << endl;
    }
    
    cout << maxflow << endl;

    return 0;
}