#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

const int N = 1e6 + 10;

using namespace std;

int n, m, len;
int cnt[N], ans[N], map[N];
vector<int> nums;

struct Query
{
    int t, l, r;
}q[N];


int get(int x)
{
    return x / len;
}

void add(int x, int& res)
{
    cnt[x] = 0;
    
}


bool cmp(const Query& a, const Query& b)
{
    int i = get(a.l), j = get(b.l);
    if(i != j)
        return i < j;
    else
        return a.l < b.l
    
}

int main()
{
    cin >> n;
    len = sqrt(n);
    for(int i = 1; i <= n; i ++)
    {
        cin >> map[i];
        nums.push_back(w[i]);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for(int i = 1; i <= n; i ++)
        map[i] = lower_bound(nums.begin(), nums.end(), w[i]) - nums.begin();
    
    cin >> m;
    for(int i = 0; i < m; i ++)
    {
        int l, r;
        cin >> l >> r;
        q[i] = {i, l, r};
    }
    sort(q, q + m, cmp);

    for(int x = 0)

}