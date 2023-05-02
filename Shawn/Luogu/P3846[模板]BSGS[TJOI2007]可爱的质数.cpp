#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>

#define int long long

using namespace std;

int y, z, p;

namespace BSGS
{
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

    int bsgs(int y, int z, int p) 
    {
        map<int, int> hash;
        z %= p;
        int t = sqrt(p) + 1;

        for (int i = 0; i < t; i ++)
            hash[z * qpow(y, i, p) % p] = i;

        y = qpow(y, t, p);

        if(!y)
            return z == 0 ? 1 : -1;

        for (int i = 1; i <= t; i ++) 
        {
            int val = qpow(y, i, p);

            if (hash.count(val)) 
            {
                int j = hash[val];
                if (i * t - j >= 0) return i * t - j;
            }
        }

        return -1;
    }
}




using namespace BSGS;


signed main()
{
    cin >> p >> y >> z;

    int ans = bsgs(y, z, p);

    if (ans == -1)
        cout << "no solution" << endl;
    
    else
        cout << ans << endl;

    
    return 0;
}