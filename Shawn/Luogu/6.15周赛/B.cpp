// B. [ABC112D] Partition

#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

#define int long long
#define mod %

using namespace std;

int n, m;
int ys[1000000];
int tot, ans = -1;

signed main()
{
    cin >> n >> m;

    if(m mod n == 0)
    {
        cout << m / n << endl;

        return 0;
    }

    for(int i = 1; i * i <= m; i ++)
    {
        if(m mod i == 0)
        {
            ys[++ tot] = i;
            
            if(m / i != i)
                ys[++ tot] = m / i;
        }
    }

    for(int i = 1; i <= tot; i ++)
        if(ys[i] * n <= m)
            ans = max(ans, ys[i]);

    cout << ans << endl;

    return 0;
}