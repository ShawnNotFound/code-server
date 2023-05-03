#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int __int128

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked()
#endif

#ifdef __WINDOWS__
#define getchar() getchar_nolock()
#define putchar(a) putchar_nolock()
#endif

using namespace std;

namespace IO
{
    template <typename T> void input(T &x)
    {
        x = 0; char c = getchar(); bool f = false;
        while(c < '0' or c > '9')
            f |= (c == '-'), c = getchar();
        while(c >= '0' and c <= '9')
            x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
        x = f ? -x : x;
    }

    template <typename T, typename... Args>
    void input(T &x, Args&... args)
    {
        input(x), input(args...);
    }

    
    template<typename T>
    void output(T x, char ed =' ')
    {
        if(x < 0) putchar('-'), x = -x;
        static short st[64], top;
        top = 0;
        do st[top ++] = x % 10, x /= 10; while(x);
        while(top --) putchar(st[top] ^ '0');
        putchar(ed);
    }

    template<typename T, typename ...Args>
    void output(T x, char ch = ' ', Args... args)
    {
        output(x, ch);
        output(args...);
    }
}

using namespace IO;

namespace exLUCAS
{
    void exgcd(int a, int b, int &x, int &y)
    {
        if(!b)
        {
            x = 1;
            y = 0;
            return;
        }
        exgcd(b, a % b, x, y);
        int tmp = x;
        x = y;
        y = tmp - a / b * y;
    }

    int qpow(int a, int k, int p)
    {
        int res = 1 % p, t = a;

        while(k)
        {
            if(k & 1)
                res = res * t % p;
            t = t * t % p;
            k >>= 1;
        }

        return res;
    }


    int inv(int a, int p)
    {
        int x, y;
        exgcd(a, p, x, y);
        return (x + p) % p;
    }

    int F(int n, int P, int PK)
    {
        if(n == 0)
            return 1;

        int rou = 1;
        int rem = 1;

        for(int i = 1; i <= PK; i ++)
            if(i % P)
                rou = rou * i % PK;
        
        rou = qpow(rou, n / PK, PK);

        for(int i = PK * (n / PK); i <= n; i ++)
            if(i % P)
                rem = rem * (i % PK) % PK;

        return F(n / P, P, PK) * rou % PK * rem % PK;

    }

    int G(int n, int P)
    {
        if(n < P)
            return 0;
        return G(n / P, P) + n / P; 
    }

    int C_PK(int n, int m, int P, int PK)
    {
        int fz = F(n, P, PK);
        int fm1 = inv(F(m, P, PK), PK);
        int fm2  = inv(F(n - m, P, PK), PK);
        int pow = qpow(P, G(n, P) - G(m, P) - G(n - m, P), PK);
        return fz * fm1 % PK * fm2 % PK * pow % PK;
    }

    int A[1010], B[1010];

    int exLucas(int n, int m, int P)
    {
        int ljc = P, tot = 0;
        for(int tmp = 2; tmp * tmp <= P; tmp ++)
        {
            if(!(ljc % tmp))
            {
                int PK = 1;
                while(!(ljc % tmp))
                {
                    PK *= tmp;
                    ljc /= tmp;
                }
                A[++ tot] = PK;
                B[tot] = C_PK(n, m, tmp, PK);
            }
        }
        if(ljc != 1)
        {
            A[++ tot] = ljc;
            B[tot] = C_PK(n, m, ljc, ljc);
        }
        int ans = 0;
        for(int i = 1; i <= tot; i ++)
        {
            int M = P / A[i], T = inv(M, A[i]);
            ans = (ans + B[i] * M % P * T % P) % P;
        }

        return ans;
    }
}

using namespace exLUCAS;

signed main()
{
    int n, m, p;
    input(n, m, p);

    int ans = exLucas(n, m, p);
    output(ans, '\n');

    return 0;
}