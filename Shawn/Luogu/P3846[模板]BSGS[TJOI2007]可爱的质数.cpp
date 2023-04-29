#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>

#define int long long


using namespace std;

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

    map<int, int> m;

    void sol()
    {
        m.clear();

        y = ((y % p) + p) % p;
        z = ((z % p) + p) % p;

        if(y == 0)
        {
            if(z == 0)
            {
                cout << "1" << endl;
                return;
            }

            cout << "no solution" << endl;
            return;
        }
        if(y == 1)
        {
            if(z == 1)
            {
                cout << "0" << endl;
                return;
            }

            cout << "no solution" << endl;
            return;
        }
        if(z == 1)
        {
            cout << 0 << endl;
            return;
        }

        int m = sqrt(p);

        for(int i = 0, t = z; i < m; i ++, t = t * y % p)
            m[t] = i;
        
        for(int i = 1, T = qpow(y, m), t = T; i <= p / m + 10; i ++, t * T % p)
            if(m.count(t))
            {
                cout << m * i - m[t] << endl;
                return;
            }
        
        cout << "no solution" << endl; 
    }
}

using namespace BSGS;

int x, y, z, p;

signed main()
{
    cin >> p >> y >> z;

    sol();

    return 0;
}