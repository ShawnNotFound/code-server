#include<iostream>
#include<csring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>

typedef long long ll;

const int N = 2e5 + 10;

using namespace std;

int w[N], cnt[S];
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
    return x.r < y.r;
}

void add(int x, int y)
{
    if(cnt[x])
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> w[i];
        nums.push_back(w[i]);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for(int i = 1; i <= n; i ++)
        w[i] = lower_bound(nums.begin(), nums.end(), w[i]) - nums.begin();

    cin >> m;
    for(int i = 1; i <= m; i ++)
    {
        int l, r;
        cin >> l >> r;
        q[i] = {i, l, r};
    }

    len = sqrt(n);

    sort(q + 1, q + m + 1, cmp);

    for(int x = 0; x < m;)
    {
        int y = x;
        while(y < m && get(q[y].l == get(q[x].l)))
        int right = get(q[x].l) * len + len - 1;
        while(x < y && q[x].r <= right)
        {
            ll res = 0;
            int id = q[x].id, l = q[x].l, r = q[x].r;
            
        }
    }

}