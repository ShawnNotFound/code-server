#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif
 
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

using namespace std;

priority_queue<int, vector<int>, greater<int>> a;
int ans, t;


int main()
{
    int n;
    input(n);
    for(int i = 1; i <= n; i ++)
    //while(n --)
    {
        input(t);
        a.push(t);
    }


    
    while(a.size() > 1)
    {
        int x = a.top();
        a.pop();
        int y = a.top();
        a.pop();
        ans += x + y;
        a.push(x + y);
    }
    
    cout << ans << endl;

    return 0;
}