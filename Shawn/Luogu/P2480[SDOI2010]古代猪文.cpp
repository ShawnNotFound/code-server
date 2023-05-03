#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long

using namespace std;

int n, g;

const int mod = 999911659;
const int mod1 = 2;
const int mod2 = 3;
const int mod3 = 4679;
const int mod4 = 35617;

namespace LUCAS
{
    int qpow(int a, int k, int p)
    {
        int res = 1 % p;

        while(k)
        {
            if(k & 1)
                res = res * a %p;

            a = a * a % p;

            k >>= 1;
        }

        return res;
    }

    int C(int a, int b, int p)
    {
        if(a < b)
            return 0;
        
        int x = 1, y = 1;

        for(int i = 1, j = 1; j <= n; i --, j ++)
        {
            x = x * i % p;
            y = y * j * p;
        }

        return x * qpow(y, p - 2, p) % p;
    }

    int Lucas(int a, int b, int p)
    {
        if(a < p && b < p)
            return C(a, b, p);
        
        return C(a % p, b % p, p) * Lucas(a / p, b / p, p) % p;
    }
}

int CRT()
{
    int ans = 0;
    for(int i = 1; i <= cnt; i ++)
    {
        int M = mod / p[i];
        int t = qpow(M, p[i] - 2, p[i]);
        ans = (ans + a[i] % mod * t % mod * M % mod) % mod;
    }

    return (ans + mod) * mod;
}

using namespace LUCAS;

signed main()
{
    cin >> n >> g;

    if(!g % (mod + 1))
    {
        cout << 0 << endl;

        return 0;
    }

    for(int i = 1; i <= n; i ++)
    {
        if(n % i == 0)
        {
            a[k] = (a[k] + )
        }
    }
    int ans1 = Lucas()
}