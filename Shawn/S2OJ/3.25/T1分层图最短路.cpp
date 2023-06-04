//直接跑最短路20pts
//新思路：分层图求最短路，在标记点之间连线

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstdio>

const int N = 2e6 + 10;

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

int ver[N], head[N], nxt[N], edge[N], d[N], fr[N];
bool marked[N], v[N];
int m, n, k, s, t, tot;
priority_queue<pair<int, int> > q;

void add(int x, int y, int z)
{
    ver[++ tot] = y, fr[tot] = x, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}

void dijkstra()
{
    memset(v, false, sizeof(v));
    memset(d, 0x3f, sizeof(d));
    while(q.size())
        q.pop();
    q.push(make_pair(0, s));
    d[s] = 0;
    
    while(q.size())
    {
        int x = q.top().second; q.pop();
        if(v[x])
            continue;
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i], z = edge[i];
            if(d[y] > d[x] + z)
            {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            }
        }
    }

}


//提供点编号，层数，返回对应真正编号
int num(int x, int c)
{
    return n * (c - 1) + x;
}

int main()
{
    //处理读入
    input(n, m, k, s, t);
    int x, y, z;
    for(int i = 1; i <= m; i ++)
    {
        input(x, y, z);
        for(int j = 1; j <= k; j ++)
        {
        	//cout << "connected " << num(x, j) << " to " << num(y, j) << endl;
        	add(num(x, j), num(y, j), z);
		}
        //add(x, y, z);
    }
    int mk;
    if(k == 0)
    {
    	if(s == t)
    	{
    		cout << "0" << endl;
    		return 0;
		}
        dijkstra();
        if(d[t] == 0x3f3f3f3f)
            cout << "-1" << endl;
        else
            cout << d[t] << endl;
        return 0;
    }
    for(int i = 1; i <= k; i ++)
    {
        input(mk);
        marked[mk] = true;
    }
    t = num(t, k);
	//cout << "stage 1" << endl;
    int ttot = tot;//边数
    for(int i = 1; i <= ttot; i ++)
    {
    	//cout << "stage 2" << endl;
        if(marked[ver[i]])
        {
        	//cout << "stage 3" << endl;
            for(int j = 2; j <= k; j ++)
            {
            	//cout << "connected " << num(fr[i], j - 1) << " to " << num(ver[i], j) << endl;
                add(num(fr[i], j - 1), num(ver[i], j), edge[i]);
            }
        }
    }
    //cout << t << endl;
    //cout << "stage 4" << endl;

    dijkstra();
    
//    for(int i = 1; i <= tot; i ++)
//    	cout << d[i] << endl;

	if(d[t] == 0x3f3f3f3f)
		cout << "-1" << endl;
    else
		cout << d[t] << endl;

    return 0;


}


