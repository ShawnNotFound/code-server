#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

const int N = 1e7 + 10;
const int INF = 1 << 29;

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
    while(c < '0' or c > '9')
        f |= (c == '-'), c = getchar();
    while(c >= '0' and c <= '9')
        x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    x =  f ? -x : x;
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

int d[100005], ver[N], nxt[N], edge[N], v[N], head[N], now[N];
int n, m, s, t, maxflow, tot = 1, totcost;

queue<int> q;

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, edge[tot] = 0, nxt[tot] = head[y], head[y] = tot;
}

bool bfs()
{
    memset(d, 0, sizeof(d));
    while(q.size())
        q.pop();
    
    q.push(s); d[s] = 1;
    now[s] = head[s];

    while(q.size())
    {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if(!d[y] && edge[i])
            {
                d[y] = d[x] + 1;
                q.push(y);
                now[y] = head[y];
                if(y == t)
                    return true;
            }
        }
    }
    return false;
}

int dinic(int x, int flow)
{
    if(x == t)
        return flow;
    int rest = flow, k, i;
    for(i = now[x]; i && rest; i = nxt[i])
    {
        int y = ver[i];
        now[x] = i;
        if(edge[i] && d[y] == d[x] + 1)
        {
            k = dinic(y, min(rest, edge[i]));
            if(!k)
                d[y] = INF;
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}

int main()
{
    input(n, m);
    s = n + m + 1;
    t = n + m + 2;
    for(int i = 1; i <= n; i ++)
    {
        int cost;
        input(cost);
        add(i, t, cost);
    }
    for(int i = 1; i <= m; i ++)
    {
        int from, to, w;
        input(from, to, w);
        totcost += w;
        add(s, i + n, w);
        add(i + n, from, INF);
        add(i + n, to, INF);
    }

    int flow = 0;
    while(bfs())
        while(flow = dinic(s, INF))
            maxflow += flow;

    
    cout << totcost - maxflow << endl;

    return 0;
}