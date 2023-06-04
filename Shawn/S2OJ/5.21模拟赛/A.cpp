// %%% sbh，您是神
// 2e7 long long 好像会炸？

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define mod %

const int N = 2e7 + 10;

typedef long long ll;

using namespace std;

int n, k, p, a, b, c, d;
int s[N],f[N], bk[N];
long long ans;

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> p;
    cin >> a >> b >> c >> d;

    s[1] = a;//特殊处理第一位
    f[1] = a;

    //初始化s
    for(int i = 2; i <= n; i ++)
        s[i] = ((ll)s[i - 1] * (ll)b + c) mod d;

    //分块front
    for(int i = 1; i <= n; i ++)
        f[i] = s[i];

    for(int i = 1; i <= n; i ++)
        if(i mod k != 1)
            f[i] = ((ll)f[i - 1] * (ll)s[i]) mod p;

    //分块back
    bk[n + 1] = 1;
    for(int i = 1; i <= n; i ++)
        bk[i] = s[i];

    for(int i = n; i >= 1; i --)
        if(i mod k)
            bk[i] = ((ll)bk[i + 1] * (ll)bk[i]) mod p;

    //solve
    for(int i = 1; i <= n - k + 1; i ++)
    {
        int l = i, r = i + k - 1;
        if(i mod k == 1)
            ans ^= f[r];
        
        else
            ans ^= ((ll)bk[l] * (ll)f[r]) mod p;
    }

    // for(int i = 1; i <= n; i ++)
    //     cout << f[i] << " ";
    // cout << endl;

    // for(int i = 1; i <= n; i ++)
    //     cout << bk[i] << " ";
    // cout << endl;

    
    cout << ans << endl;

    return 0;
}

