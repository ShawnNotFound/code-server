#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define int __int128
#define mian main

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

using namespace std;

const int N = 1e5 + 10;

int x, y, d, n;


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


    template <typename T>
    void output(T x, char ed = ' ')
    {
        if (x < 0) putchar('-'), x = -x;
        static short st[64], top;
        top = 0;
        do st[top ++] = x % 10, x /= 10; while (x);
        while (top --) putchar(st[top] ^ '0');
        putchar(ed);
    }

    template <typename T, typename ...Args>
    void output(T x, char ch = ' ', Args... args) {
        output(x, ch);
        output(args...);
    }
}


namespace exCRT
{
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }

    int lcm(int a, int b)
    {
        return a * b / gcd(a, b);
    }

    void exgcd(int &x, int &y, int a, int b)
    {
        if(!b)
        {
            d = a;
            x = 1;
            y = 0;
        }
        else
        {
            exgcd(y, x, b, a % b);
            y -= a / b * x;
        }
    }

    int a, b, A, B;

    void merge()
    {
        exgcd(x, y, a, A);
        int c = B - b;
        if(c % d)
        {
            cout << "-1" << endl;
            exit(0);
        }
        x = x * c / d % (A / d);
        if(x < 0)
            x += A / d;
        int mod = lcm(a, A);
        b = (a * x + b) % mod;
        if(b < 0)
            b += mod;
        a = mod;
    }
}

using namespace exCRT;
using namespace IO;

signed mian()
{
    input(n);

    for(int i = 1 ; i <= n ; i ++) 
    {
        long long AA, BB;
        input(AA, BB);
        A = AA, B = BB;

        if(i > 1) 
            merge();
        
        else
        {
            a = A;
            b = B;
        }
    }
    output(b % a, '\n');
    return 0;
}