#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif

const int N = 1e7;

using namespace std;
 
template <typename T> void input(T &x)
{
    x = 0; char c = getchar(); bool f = false;
    while (c < '0' or c > '9')
    	f |= (c == '-'), c = getchar();
    while  (c >= '0' and c <= '9')
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

int n, p, x, y, inv[N];


void exgcd(int a, int b, int& x, int& y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return;
    }

    exgcd(b, a % b, y, x);

    y -= a / b * x;
}

int main()
{
    input(n, p);

    inv[1] = 1;
    cout << 1 << endl;
    for (int i = 2; i <= n; i ++) 
    {
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
        
        output(inv[i], '\n');
    }


    return 0;
}