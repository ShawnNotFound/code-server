#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

#define int long long
const int mod = 10000007;

using namespace std;

int n, tot, ans = 1;
int num[55];

int qpow(int m, int k, int p)
{
    int res = 1 % p, t = m;

    while(k)
    {
        if(k & 1)
            res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }

    return res;
}


signed main()
{
    cin >> n;

    for(int i = 49; ~i; i --)
    {
        for(int j = 49; j; j --)
            num[j] += num[j - 1];

        if(n >> i & 1)
            num[tot ++] ++;
    }num[tot] ++;

    for(int i = 1; i <= 49; i ++)
    {
        ans = (ans * qpow(i, num[i], mod)) % mod;
    }

    cout << ans << endl;

    return 0;    
}