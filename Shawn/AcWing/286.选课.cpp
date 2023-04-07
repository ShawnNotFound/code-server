#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 310;

using namespace std;

int tot, n, m;
int ver[N], nxt[N], head[N], f[N][N];

void add(int x, int y)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
}

void dp(int u)
{
    for(int i = head[u]; ~i; i = nxt[i])
    {
        int v = ver[i];
        dp(v);

        for(int j = m + 1; j; j --)
            for(int k = 0; k < j; k ++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
    }
}

int main()
{
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; i ++)
    {
        int from, to;
        cin >> from >> to;
        f[i][1] = to;
        add(from, i);
    }

    dp(0);

    cout << f[0][m + 1] << endl;

    return 0;
}