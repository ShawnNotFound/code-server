
// while(1)
//     rp ++;

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<queue>

#define int long long

const int N = 1e6;

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif

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

priority_queue<int> q;
char f;
int n, num, ans;


signed main()
{
    input(n);
    for(int i = 1; i <= n - 1; i ++)
    {
        f = getchar();
        if(f == 'c')
        {
            input(num);
            q.push(-num);
        }
        if(f == 'e')
        {
            input(num);
            while(q.size() >= num)
                q.pop();
        }
    }

    f = getchar();
    input(num);
    if(num > q.size())
        printf("-1\n");
    else
    {
        while(q.size())
        {
            ans += -q.top();
            q.pop();
        }
        output(ans, '\n');
    }
    

    return 0;

}