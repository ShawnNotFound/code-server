#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 7e5 + 10;

using namespace std;

int n;
int tot, rt;
int b[N], nxt[N << 1], ver[N << 1], head[N], edge[N << 1], size[N];

long long sum, ans;
long long f[N];

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot; 
    ver[++ tot] = x, edge[tot] = z, nxt[tot] = head[y], head[y] = tot; 
}

void dfs1(int u, int pre)
{
    size[u] = 1;
    for(int i = head[u]; i; i = nxt[i])
    {
        int v = ver[i];

        if(v == pre)
            continue;

        dfs1(v, u);

        size[u] += size[v];

        f[1] += (long long)max((long long)edge[i] - b[u], 0ll) * (long long)size[v];
    }
}

void dfs2(int u, int pre)
{
    for(int i = head[u]; i; i = nxt[i])
    {
        int v = ver[i];
        if(v == pre)
            continue;

        f[v] = f[u] - (edge[i] - b[u]) * size[v] + (edge[i] - b[v]) * (n - size[v]);


        if(f[v] <= f[rt]) 
            rt = f[v] < f[rt] ? v : min(rt, v);

        dfs2(v, u);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> b[i];

    for(int i = 1; i <= n - 1; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        add(u, v, w);
    }

    dfs1(1, 0);

    rt = 1;

    dfs2(1, 0);

    cout << rt << endl;
    cout << f[rt] << endl;

    return 0;
}