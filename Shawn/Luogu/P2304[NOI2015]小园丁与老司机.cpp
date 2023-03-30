#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>

const int N = 1e5 + 10;

using namespace std;


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


int ver[N], head[N], nxt[N], edge[N], v[N], head[N], now[N];
int l[N], r[N], u[N], lu[N], ru[N];
int n, m, s, t, maxflow, tot;
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
            if(!d[y] && edge[i])
            {
                d[y] = d[x] + 1;
                q.push(y);
                now[y] = head[y];
                if(y == t)
                    return 1;
            }
        }
    }
    return 0;
}

int dinic(int x, int flow)
{
    if(x == t)
        return flow;
    int rest = flow, k, i;
    for(i = now[x]; i && rest; i = nxt[i])
    {
        int y = ver[i];
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

int tot_lu, tot_ru, tot_l, tot_r, tot_u;


struct dir_tt
{
    int val, x, n;
}
dir_tt lu[N], ru[N];

struct dir_t1
{
    int val, n;
}
dir_t1 l[N], r[N], u[N]; 


void lu_add(int val, int x, int num)
{
    lu[++ tot_lu].val = val;
    lu[++ tot_lu].x = x; 
    lu[tot_lu].n = num;
}

void ru_add(int val, int x, int num)
{
    ru[++ tot_ru].val = val;
    ru[tot_ru].x = x;
    ru[tot_ru].n = num;
}

void r_add(int val, int num)
{
    r[++ tot_r].val = val;
    r[tot_r].n = num;
}

void l_add(int val, int num)
{
    l[++ tot_l].val = val;
    l[tot_l].n = num;
}

void u_add(int val, int num)
{
    u[++ tot_u].val = val;
    u[tot_u].n = num;
}


bool cmp_tt(dir_tt x, dir_tt y)
{
    int vx = x.val, vy = y.val;
    if(vx == vy)
        return x.x < x.y;
    return x.val < y.val;
}

bool cmp_t1(dir_t1 x, dir_t1 y)
{
    int vx = x.val, vy = y.val;
    return vx < vy;
}

int main()
{
    input(n);
    for(int i = 1; i <= n; i ++)
    {
        int xx, yy;
        input(xx, yy);
        int sign_lu = xx - yy;
        int sign_ru = xx + yy;
        l_add(yy, i);
        r_add(yy, i);
        u_add(xx, i);
        lu_add(sign_lu, xx, i);
        ru_add(sign_ru, xx, i);
    }
    
    sort(lu + 1, lu + tot_lu + 1, cmp_tt);
    sort(ru + 1, ru + tot_ru + 1, cmp_tt);
    sort(l + 1, l + tot_l + 1, cmp_t1);
    sort(r + 1, r + tot_r + 1, cmp_t1);
    sort(u + 1, u + tot_u + 1, cmp_t1);


    
}