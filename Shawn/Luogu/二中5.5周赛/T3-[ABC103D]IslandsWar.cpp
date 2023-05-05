#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

struct qwq
{
	int l, r;
}w[N];

int n, m, ans, maxl = 1;

bool cmp(qwq x, qwq y)
{
	return x.r < y.r;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
        cin >> w[i].l >> w[i].r;

    sort(w + 1, w + m + 1, cmp);

    for(int i = 1; i <= m; i ++)
        if(w[i].l >= maxl)
        {
            maxl = w[i].r;
            ans ++;
        }

    cout << ans << endl;

    return 0;
}
