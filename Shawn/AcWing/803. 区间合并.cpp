#include<iostream>
#include<cmath>
#include<algorithm>
const int N = 1e5 + 10;
using namespace std;

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
    int n;
    cin >> n;
    for(int i = 1; i <= n ; i ++)
        cin >> q[i].l >> q[i].r;
    
    sort(q + 1, q + n + 1, cmp);

    int ans = 1;
    int maxr = q[1].r;   
    for(int i = 1;i <= n; i ++)
    {
        if(q[i].l > maxr)
        {
            ans ++;
            maxr = q[i].r;
            continue;
        }
        if(q[i].r > maxr)
        {
            maxr = q[i].r;
        }
    }

    cout << ans << endl;

    return 0;
}