#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>

const int N = 3e3 + 10;

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

// int dist(int x1, int y1, int x2, int y2)
// {
//     return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
// }

struct point
{
    int x, y;
}p[N];
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>

const int N = 3e3 + 10;

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

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct point
{
    int x, y;
}p[N];
	
double dis[N][N];
int cnt;

int main()
{
    int n;
    input(n);
    for(int i = 1; i <= n; i ++)
    {
    	input(p[i].x, p[i].y);
    }

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		{
			dis[i][j] = dist(p[i].x, p[i].y, p[j].x, p[j].y);
		}

    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++)
            for(int k = j; k <= n; k ++)
            {
            	//cout << i << " " << j << " " << k << endl;
            	if(i == j || j == k || i == k)
            		continue;
//                int x1 = p[i].x, x2 = p[j].x, x3 = p[k].x;
//                int y1 = p[i].y, y2 = p[j].y, y3 = p[k].y;
                //if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))
                //    continue;
            	double d12 = dis[i][j], d13 = dis[i][k], d23 = dis[j][k];
            	if(d12 >= d23 + d13 || d13 >= d12 + d23 || d23 >= d12 + d13 || !d12 || !d23 || !d13)
					continue; 
                cnt ++;
//				if(!flag[i][j][k])
//                {
//                	//cout << i << " " << j << " " << k << endl;
//                    cnt ++;
//                    flag[i][j][k] = true;
////                    flag[i][k][j] = true;
////                    flag[j][i][k] = true;
////                    flag[j][k][i] = true;
////                    flag[k][j][i] = true;
////                    flag[k][i][j] = true;
//                }
            }
    
    cout << cnt << endl;

    return 0;

}
bool flag[N][N][N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> p[i].x >> p[i].y;
    }

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            for(int k = 1; k <= n; k ++)
            {
                int x1 = p[i].x, x2 = p[j].x, x3 = p[k].x;
                int y1 = p[i].y, y2 = p[j].y, y3 = p[k].y;
                if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))
                    continue;
                if(!flag[i][j][k])
                {
                    cnt ++;
                    flag[i][j][k] = true;
                }
            }
    
    cout << cnt << endl;

    return 0;

}