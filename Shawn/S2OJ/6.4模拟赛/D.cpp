#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

#define mod %

const int N = 3e5 + 500;
const int MOD = 1e9 + 7;

using namespace std;

int n, m, tot;

int ver[N << 1], head[N], nxt[N << 1], fa[N << 1];
int record[N][22], dpt[N];

int ta[N], tb[N], lca[N];

namespace Math
{
    int qpow(int a, int b)
    {
        int res = 1;
        while(b)
        {
            if(b & 1)
                res = (1LL * res * a) mod MOD;
            
            a = (1LL * a * a) mod MOD;
    
            b >>= 1; 
        }
    
        return res;
    }
}
using namespace Math;

namespace CS
{

    int get_father(int x)
    {
        return fa[x] == x ? x : fa[x] = get_father(fa[x]);
    }

    void merge(int x, int lca)
    {
        while(dpt[record[x][0]] > dpt[lca])
        {
            int f = record[x][0];
            
            int xf = get_father(x);
            int xnf = get_father(x + n);
            int ff = get_father(f);
            int fnf = get_father(f + n);
            
            fa[xf] = ff;
            fa[xnf] = fnf;
            x = ff;
        }
    }
}
using namespace CS;

namespace LCA
{
    void add(int x, int y)
    {
        ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
        ver[++ tot] = x, nxt[tot] = head[y], head[y] = tot;
    }

    void dfs(int u, int pre)
    {
        record[u][0] = pre;
        dpt[u] = dpt[pre] + 1;
        for(int i = 1; i <= 19; i ++)
            record[u][i] = record[record[u][i - 1]][i - 1];
        
        for(int i = head[u]; i; i = nxt[i])
        {
            int v = ver[i];

            if(v == pre)
                continue;

            dfs(v, u);
        }
    }

    int Lca(int x, int y)
    {
        if(dpt[x] < dpt[y])
            swap(x, y);

        for(int i = 19; i >= 0; i --)
            if(dpt[record[x][i]] >= dpt[y])
                x = record[x][i];

        if(x == y)
            return x;

        for(int i = 19; i >= 0; i --)
            if(record[x][i] != record[y][i])
                x = record[x][i], y = record[y][i];

        return record[x][0];
    }
}
using namespace LCA;


signed main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    //init
    for(int i = 1; i <= 2 * n; i ++)
        fa[i] = i;

    for(int i = 1; i < n; i ++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    dfs(1, 0);

    for(int i = 1; i <= m; i ++)
    {
        cin >> ta[i] >> tb[i];
        lca[i] = Lca(ta[i], tb[i]);

        merge(ta[i], lca[i]);
        merge(tb[i], lca[i]);
    }

    for(int i = 1; i <= m; i ++)
    {
        if((lca[i] != ta[i]) && (lca[i] != tb[i]))
        {
            fa[get_father(ta[i] + n)] = get_father(tb[i]);
            fa[get_father(tb[i] + n)] = get_father(ta[i]);
        }
    }

    int ans = 0;

    for(int i = 2; i <= n; i ++)
    {
        int fi = get_father(i);
        int fin = get_father(i + n);

        if(fi == fin)
        {
            cout << 0 << endl;
            return 0;
        }

        if(fi == i)
            ans ++;
        
        if(fin == (i + n))
            ans ++;
    }

    cout << qpow(2, ans / 2) << endl;

    return 0;
}
