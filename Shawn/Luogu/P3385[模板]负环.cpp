#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;

int d[N], v[N], nxt[N], edge[N], head[N], cnt[N], ver[N];
int t, n, m, u, vv, w, tot;
queue<int> q;

void init()
{
    memset(nxt, 0, sizeof(nxt));
    memset(edge, 0, sizeof(edge));
    memset(head, 0, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
    while(q.size())
        q.pop();
}

void add(int x, int y, int z)
{
    if(z >= 0)
        ver[++ tot] = x, edge[tot] = z, nxt[tot] = head[y], head[y] = tot;
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}

void spfa()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    q.push(1); d[1] = 0, v[1] = 1;
    while(q.size())
    {
        int x = q.front(); q.pop();
        v[x] = 0;
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i], z = edge[i];
            if(d[y] > d[x] + z)
            {
                if(!v[y])
                {
                    q.push(y);
                    v[y] = 1;
                }
                d[y] = d[x] + z;
                cnt[y] = cnt[x] + 1;
                if(cnt[y] >= n)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    cin >> t;
    while(t --)
    {
        init();
        cin >> n >> m;
        for(int i = 1; i <= m; i ++)
        {
            cin >> u >> vv >> w;
            add(u, vv, w);
        }

        spfa();
    }

    return 0;
}