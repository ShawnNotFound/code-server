#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define int long long

namespace LUCAS
{
    int qpow(int a, int k, int p)
    {
        int res = 1 % p;

        while(k)
        {
            if(k & 1)
                res = res * a % p;
            
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

        for(int i = a, j = 1; j <= b; i --, j ++)
        {
            x = x * i % p;
            y = y * j % p;
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

using namespace std;
using namespace LUCAS;

int T;

signed main()
{
    cin >> T;

    while(T --)
    {
        int n, m, p;
        cin >> n >> m >> p;

        cout << Lucas(n + m, n, p) << endl;
    }

    return 0;
}