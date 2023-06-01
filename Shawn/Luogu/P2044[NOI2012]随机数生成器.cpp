#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define int long long
#define mod %

const int N = 40;

using namespace std;

int M, a, c, x0, n, g;

int mul(int x, int y)
{
    int ans = 0;
    while(y)
    {
        if(y & 1)
            ans = (ans + x) mod M;

        x = (x + x) mod M;

        y >>= 1;
    }

    return ans;
}

struct Mat
{
    int a[N][N];
    int n, m;

    Mat()
    {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }

    Mat(int k)
    {
        n = m = k;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= k; i ++)
            a[i][i] = 1;
    }

    Mat(int x, int y)
    {
        n = x;
        m = y;
        memset(a, 0, sizeof(a));
    }

    Mat operator *(Mat b)
    {
        Mat c(n, b.m);

        for(int i = 1; i <= c.n; i ++)
            for(int j = 1; j <= c.m; j ++)
                for(int k = 1; k <= m; k ++)
                    c.a[i][j] = (c.a[i][j] + mul(a[i][k], b.a[k][j])) mod M;

        return c;
    }

    Mat operator *=(Mat b)
    {
        return *this = *this * b;
    }

    Mat operator ^(int k)
    {
        Mat ans(n), t = *this;
        while(k)
        {
            if(k & 1)
                ans *= t;
            
            t *= t;
            k >>= 1;
        }
        return ans;
    }

    Mat operator ^= (int k)
    {
        return *this = *this ^ k;
    }
};

signed main()
{
    cin >> M >> a >> c >> x0 >> n >> g;

    if(!n)
    {
        cout << x0 << endl;
        return 0;
    }

    Mat res(4, 4);
    res.a[1][1] = a;
    res.a[1][2] = 1;
    res.a[2][2] = 1;

    Mat p(2, 1);
    p.a[1][1] = x0;
    p.a[2][1] = c;

    res ^= n;
    res *= p;

    cout << res.a[1][1] mod g << endl;

    return 0;
}