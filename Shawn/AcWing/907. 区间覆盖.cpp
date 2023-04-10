#include<iostream>
#include<cmath>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

int s, t, n;

struct qj
{
    int l, r;
}q[N];

bool cmp(qj x, qj y)
{
    return x.l < y.l;
}

int main()
{
    cin >> s >> t >> n ;
    for(int i = 1; i <= n; i ++)
    {
        cin >> q[i].l >> q[i].r;
    }

    sort(q + 1, q + n + 1, cmp);

    //找出包含s的中q.r最大的区间,max对应最大值q.r,maxn对应所在序号
    int max = -1e8, maxn;
    for(int i = 1; q[i].l <= s; i ++)
    {
        if(q[i].r > max)
        {
            max = q[i].r;
            maxn = i;
        }
    }

    //判定所需的区间数目
    int ans = 1;
    for(int i = s; i <= t; i ++ )
    {
        if(max >= t)
        {
            cout << ans << endl;
            return 0;
        }
        
        if(max < i)
        {
            cout << "init1" << endl;
            ans ++;
            for(int j = maxn; q[j].l <= i;j ++)
                if(q[j].r > max)
                {
                    cout << "init 2" << endl;
                    max = q[j].r;
                    maxn = j;
                }
        }
    }
    cout << -1 << endl;

    return 0;
}