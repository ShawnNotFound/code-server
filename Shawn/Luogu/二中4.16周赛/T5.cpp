//brute force
//n^4,能过一个点就是奇迹hhhc
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

#define int long long

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

int origin_map[210][210], map[210][210]; 
int maxs, s, m, n;

signed main()
{
    input(n, m);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            input(origin_map[i][j]);
            map[i][j] = map[i][j - 1] + map[i - 1][j] - map[i - 1][j - 1] + origin_map[i][j];
        }
        
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            for(int x = i; x <= n; x ++)
                for(int y = j; y <= m; y ++)
                    if(map[x][y] + map[i - 1][j - 1] - map[x][j - 1] - map[i - 1][y] > 0)
                        if(maxs < (x - i + 1) * (y - j + 1))
                            maxs = (x - i + 1) * (y - j + 1);

    output(maxs, '\n');

    return 0;
}