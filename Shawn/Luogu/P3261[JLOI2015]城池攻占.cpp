#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long

const int N = 3e5 + 10;

using namespace std;

int n, m;
int fa[N], c[N], a[N], rt[N];
int h[N], v[N], s[N];
int ls[N], rs[N], dep[N];
int Dep[N], die[N], ans[N];
int add[N], tim[N];

void pushdown(int x)
{
    if(add[x] == 0 && tim[x] == 1)
        return;
    
    if(ls[x])
    {
        tim[ls[x]] *= tim[x];
        add[ls[x]] *= tim[x];
        add[ls[x]] += add[x];
        s[ls[x]] *= tim[x];
        s[ls[x]] += add[x];
    }

    if(rs[x])
    {
        tim[rs[x]] *= tim[x];
        add[rs[x]] *= tim[x];
        add[rs[x]] += add[x];
        s[rs[x]] *= tim[x];
        s[rs[x]] += add[x];
    }

    add[x] = 0;
    tim[x] = 1;
}

int merge(int x, int y)
{
    if(!x || !y)
        return x ^ y;
    pushdown(x);
    pushdown(y);
    if(s[x] > s[y])
        swap(x, y);
    rs[x] = merge(rs[x], y);

    if(dep[ls[x]] < dep[rs[x]])
        swap(ls[x], rs[x]);
    
    dep[x] = dep[ls[x]] + 1;
    return x;
}

signed main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
    {
        scanf("%lld", h + i);
        rt[i] = -1;
    }

    Dep[1] = 1;
    dep[0] = -1;

    for(int i = 2; i <= n; i ++)
    {
        scanf("%lld%lld%lld", fa + i, a + i, v + i);
        
        Dep[i] = Dep[fa[i]] + 1;
    }

    for(int i = 1; i <= m; i ++)
    {
        scanf("%lld%lld", s + i, c + i);
        tim[i] = 1;
        if(rt[c[i]] == -1)
            rt[c[i]] = i;
        else
            rt[c[i]] = merge(rt[c[i]], i);
    }

    for(int i = n; i >= 1; i --)
    {
        while(rt[i] != -1)
        {
            if(s[rt[i]] < h[i])
            {
                die[rt[i]] = i;
                pushdown(rt[i]);
                if(!ls[rt[i]])
                    rt[i] = -1;
                else 
                    rt[i] = merge(ls[rt[i]], rs[rt[i]]);
            }
            else 
                break;
        }

        if(i == 1)
            break;
        if(rt[i] == -1)
            continue;
        if(a[i])
        {
            tim[rt[i]] *= v[i];
            add[rt[i]] *= v[i];
            s[rt[i]] *= v[i];
        }
        else 
        {
            add[rt[i]] += v[i];
            s[rt[i]] += v[i];
        }

        pushdown(rt[i]);
        if(rt[fa[i]] == -1)
            rt[fa[i]] = rt[i];
        else
            rt[fa[i]] = merge(rt[fa[i]], rt[i]);
    }

    for(int i = 1; i <= m; i ++)
        ans[die[i]] ++;
    
    for(int i = 1; i <= n; i ++)
        cout << ans[i] << endl;
    
    for(int i = 1; i <= m; i ++)
        cout << Dep[c[i]] - Dep[die[i]] << endl;
    
    return 0;
}
