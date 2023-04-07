#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 310;

using namespace std;

int tot, n, p, ans = 1 << 29;
int ver[N], nxt[N], head[N], f[N][N], tmp[N];
bool hf[N];

void add(int x, int y)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
}

int dp(int u)
{
    int sum = 1;
    for(int i = head[u]; i; i = nxt[i])
    {
        int v = ver[i];
        sum += dp(v);

        for(int j = sum; j; j --)
            for(int k = 1; k < j; k ++)
                f[u][j] = min(f[u][j], f[u][j - k] + f[v][k] - 1);
    }
    //cout << sum << " ";
    return sum;
}

int main()
{
    cin >> n >> p;
    
    memset(f, 0x3f, sizeof(f));

    for(int i = 1; i <= n - 1; i ++)
    {
        int from, to;
        cin >> from >> to;
        hf[to] = true;
        tmp[from] ++;
        add(from, to);
    }


    int root = -1;

    for(int i = 1; i <= n; i ++)
    {
        if(!hf[i])
            root = i;
        f[i][1] = tmp[i];
    }

    //cout << "before dp" << endl;

    dp(root);

    ans = f[root][p];
    //cout << "finish dp" << endl;

    for(int i = 1; i <= n; i ++)
        min(ans, f[i][p] + 1);

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j ++)
    //         cout << f[i][j] << " ";
    //     cout << endl;
    // }

    cout << ans << endl;

    return 0;
}