#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 10010, S = 1e7 + 10;

int n, m, len, mq, mc;//len记录每个块的长度
int w[N], cnt[S], ans[N];
struct Query
{
    int id, l, r, t;//t是时间戳
}q[N];//存储所有询问
struct Modify
{
    int p, c;//时间戳，将第p个数修改成c
}c[N];

int get(int x)
{
    return x / len;
}

bool cmp(const Query& a, const Query& b)
{
    int al = get(a.l), ar = get(a.r);
    int bl = get(b.l), br = get(b.r);
    if(al != bl)//左端点排序
        return al < bl;
    if(ar != br)//右端点排序
        return ar < br;
    return a.t < b.t;//时间戳排序
}

void add(int x, int& res)
{
    if(!cnt[x])
        res ++;
    cnt[x] ++;
}
void del(int x, int& res)
{
    cnt[x] --;
    if(!cnt[x])
        res --;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> w[i];
    for(int i = 0; i < m; i ++)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == 'Q')
        {
            mq ++;
            q[mq] = {mq, a, b, mc};
        }
        else
        {
            c[++ mc] = {a, b};
        }
    }

    len = cbrt((double)n * max(mc, 1)) + 1;
    sort(q + 1, q + mq + 1, cmp);

    for(int i = 0, j = 1, t = 0, k = 1, res = 0; k <= mq; k ++)
    {
        int id = q[k].id, l = q[k].l, r = q[k].r, tm = q[k].t;
        while(i < r)
            add(w[++ i], res);
        while(i > r)
            del(w[i --], res);
        while(j < l)
            del(w[j ++], res);
        while(j > l)
            add(w[-- j], res);
        while(t < tm)
        {
            t ++;
            if(c[t].p >= j && c[t].p <= i)
            {
                del(w[c[t].p], res);
                add(c[t].c, res);
            }
            swap(w[c[t].p], c[t].c);
        }
        while(t > tm)
        {
            if(c[t].p >= j && c[t].p <= i)
            {
                del(w[c[t].p], res);
                add(c[t].c, res);
            }
            swap(w[c[t].p], c[t].c);
            t --;
        }
        ans[id] = res;
    }
    for(int i = 1; i <= mq; i ++)
        cout << ans[i] << endl;
    
    return 0;
}

