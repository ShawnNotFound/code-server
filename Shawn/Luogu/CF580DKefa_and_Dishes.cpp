#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long

const int N = 20;

using namespace std;

int n, m, k, ans;
int a[N], ad[N][N], f[(1 << 18) + 10][N];

int calc(int a)
{
    int res = 0;
    for(int i = 0; i < n; i ++)
        res += ((a >> i) & 1);
    
    return res;
}

signed main()
{
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        f[1 << (i - 1)][i] = a[i];
    }

    for(int i = 1; i <= k; i ++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cin >> ad[t1][t2];
    }

    for(int i = 1; i < (1 << n); i ++)
    {
        int tmp = calc(i);
        if(tmp > m)
            continue;
        
        if(tmp == m)
        {
            for(int j = 1; j <= n; j ++)
                if((i >> (j - 1)) & 1)
                    ans = max(ans, f[i][j]);
                
            continue;
        }

        for(int j = 1; j <= n; j ++)
        {
            if((i >> (j - 1)) & 1)
                continue;
            
            for(int kk = 1; kk <= n; kk ++)
                if((i >> (kk - 1)) & 1)
                    f[i | (1 << (j - 1))][j] = max(f[i | (1 << (j - 1))][j], f[i][kk] + a[j] + ad[kk][j]);
        }
    }

    cout << ans << endl;

    return 0;
}