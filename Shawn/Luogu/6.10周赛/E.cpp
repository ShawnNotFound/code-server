#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define int long long
#define mod %

const int M = 1e9 + 7;

using namespace std;

int n, m;
int nums[50];
int tot;

namespace LUCAS
{
    int qpow(int a, int k, int p)
    {
        int res = 1 mod p;

        while(k)
        {
            if(k & 1)
                res = res * a mod p;
            
            a = a * a mod p;

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
            x = x * i mod p;
            y = y * j mod p;
        }

        return x * qpow(y, p - 2, p) mod p;
    }

    int Lucas(int a, int b, int p)
    {
        if(a < p && b < p)
            return C(a, b, p);
        
        return C(a mod p, b mod p, p) * Lucas(a / p, b / p, p) mod p;
    }
}
using namespace LUCAS;

signed main()
{
    cin >> n >> m;

    for(int i = 2; i * i <= m; i ++)
    {
        int num = 0;
        
        while(!(m mod i))
        {
            m /= i;
            num ++;
        }
        if(num)
            nums[++ tot] = num;
    }

    if(m != 1)
        nums[++ tot] = 1;
    
    int ans = 1;

    for(int i = 1; i <= tot; i ++)
    {
        ans = (ans * Lucas(n + nums[i] - 1, n - 1, M)) mod M; 
    }

    cout << ans << endl;

    return 0;
}