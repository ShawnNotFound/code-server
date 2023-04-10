#include<iostream>
#include<cmath>
#include<cstdio>
const int N = 2e9 + 10;
using namespace std;

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked()
#endif

#ifdef __WINDOWS__
#define getchar() getchar_nolock()
#define putchar(a) putchar_nolock()
#endif

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
    if(x < 0) putchar('-'), x = -x;
    static short st[64], top;
    top = 0;
    do st[top ++] = x % 10, x /= 10; while(x);
    while(top --) putchar(st[top] ^ '0');
    putchar(ed);
}
template <typename T, typename ...Args>
void output(T x, char ch = ' ', Args... args)
{
    output(x, ch);
    output(args...);
}

int L, m, a, p, t, n = 0, num[N];
char f;

struct SegmentTree
{
    int l, r;
    int n;
};

SegmentTree s[N];

int Q(int k, int l, int r)
{
    if(s[k].l > l && s[k].r < r)
        return s[k].n;
    int mid = (s[k].l + s[k].r) / 2;
    int val = -(1 << 30);
    if(l <= mid) val = max(val, Q(k * 2, l , r));
    if(l > mid) val = max(val, Q(k * 2 + 1, l, r));
    return val;
}

void A(int k, int l, int r)
{
    s[k].l = l, s[k].r = r;
    if(l == r)  
    {
        s[k].n = num;
        return;
    }
    int mid = (l + r) / 2;
    A(k * 2, l, mid);
    A(k * 2 + 1, mid + 1, r);
    s[k].n = max(s[k * 2].n, s[k * 2 + 1].n);
}

int main()
{

    input(m, p);
    for(int i = 1; i <= m; i ++)
    {
        cin >> f;
        if(f == 'Q')
        {
            input(L);
            a = Q(1, L, n); 
            output(a);
        }
        if(f == 'Q')
        {
            input(t);
            a[n] = (t + a) % p;
            A(1, 1, n);
        }
    }
    return 0;
}