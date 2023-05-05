#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

struct Matrix
{
    int m[5][5];

    Matrix()
    {
        memset(m, 0, sizeof(m));
    }

    Matrix operator*(const Matrix &b) const
    {
        Matrix res;
        for(int i = 1; i <= 2; i ++)
            for(int j = 1; j <= 2; j ++)
                for(int k = 1; k <= 2; k ++)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * b.m[k][j]) % mod;

        return res;
    }
} ans, base;

void init()
{
    base.m[1][1] = base.m[1][2] = base.m[2][1] = 1;
    ans.m[1][1] = ans.m[1][2] = 1;
}

void qpow(int b)
{
    while(b)
    {
        if(b & 1)
            ans = ans * base;
        base = base * base;
        
        b >>= 1;
    }
}

signed main()
{
    int n;

    cin >> n;

    if(n <= 2)
    {
        cout << 1 << endl;
        return 0;
    }

    init();

    qpow(n - 2);

    cout << ans.m[1][1] % mod << endl;

    return 0;
}