#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>

typedef long long ll;

const int N = 2e5 + 10;

using namespace std;

int w[N], cnt[N];
ll ans[N];
struct Query
{
    int id, l, r;
}q[N];
int n, m, len;
vector<int> nums;

int get(int x)
{
    return x / len;
}

bool cmp(const Query& a, const Query& b)
{
    int x = get(a.l), y = get(b.l);
    if(x != y)
        return x < y;
    return a.r < b.r;
}

void add(int x, ll& res)
{
    cnt[x] ++;
    res = max(res, (ll)cnt[x] * nums[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    len = sqrt(n);
    for(int i = 1; i <= n; i ++)
    {
        cin >> w[i];
        nums.push_back(w[i]);
    }
    sort(nums.begin(), nums.end());

    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for(int i = 1; i <= n; i ++)
        w[i] = lower_bound(nums.begin(), nums.end(), w[i]) - nums.begin();

    //cin >> m;
    for(int i = 0; i < m; i ++)
    {
        int l, r;
        cin >> l >> r;
        q[i] = {i, l, r};
    }
    cout << "finish read" << endl;


    sort(q, q + m, cmp);

    for(int x = 0; x < m;)
    {
        int y = x;
        while(y < m && get(q[y].l) == get(q[x].l))
            y ++;
        int right = get(q[x].l) * len + len - 1;//求这个块的最后一个点

        //暴力求块内的询问
        while(x < y && q[x].r <= right) //当前右端点在块内
        {
            ll res = 0;
            int id = q[x].id, l = q[x].l, r = q[x].r;
            for(int k = l; k <= r; k ++)
                add(w[k], res);
            ans[id] = res;
            for(int k = l; k <= r; k ++)
                cnt[w[k]] --;
            x ++;
        }

        //求块外的询问
        ll res = 0;
        int i = right, j = right + 1;
        while(x < y)
        {
            int id = q[x].id, l = q[x].l, r = q[x].r;
            while(i < r)
                add(w[++ i], res);

            ll backup = res;
            while(j > l)
                add(w[-- j], res);
            ans[id] = res;

            while(j < right + 1)
                cnt[w[j ++]] --;
            res = backup;
            x ++;
        }
        memset(cnt, 0, sizeof(cnt));
    }

    for(int i = 0; i < m; i ++)
        cout << ans[i] << endl;
    return 0;


}