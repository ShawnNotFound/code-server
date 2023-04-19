#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long

const int MOD = 10086001;

using namespace std;

int f[5010], num, ans, n, t, k;
int s[5010];

signed main()
{
    cin >> n >> k;

    s[0] = f[0] = 1;

    for(int i = 1; i <= k; i ++)
    {
        cin >> t;
        num += t;

        for(int j = 1; j <= n; j ++)
            s[j] = s[j - 1] + f[j];
        
        for(int j = n; j >= 0; j --)
            f[j] = (f[j] + s[j - 1] - s[j - min(t, j) - 1]) % MOD;
        
        ans = (ans + f[n]) % MOD;
    }

    if(num < n)
        cout << "impossible" << endl;
    else
        cout << ans << endl;

    return 0;
}