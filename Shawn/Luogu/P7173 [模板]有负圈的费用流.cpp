#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

//#define int long long
const int N = 1e6 + 10;
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

bool v[N], ro[N];
int ver[N], nxt[N], cost[N], head[N], edge[N], incf[N], pre[N], d[N], total[N];
int maxflow, ans, u, vv, w, c, n, m, mincost, tot = 1, cnt;
queue<int> q;

// int num(int i,int k)
// {
//     return i + k * n;
// }

void add(int x, int y, int z, int k)
{
    ver[++ tot] = y, edge[tot] = z, cost[tot] = k, nxt[tot] = head[x], head[x] = tot;
    //ver[++ tot] = x, edge[tot] = 0, cost[tot] = -k, nxt[tot] = head[y], head[y] = tot, ro[tot] = false;
}

bool spfa(int s, int t)
{
    //cnt = 0;
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    while(q.size())
        q.pop();
    q.push(s); v[s] = true; d[s] = 0;
    incf[s] = 1 << 30;
    while(q.size())
    {
        int x = q.front(); q.pop(); v[x] = false;
        for(int i = head[x]; i; i = nxt[i])
        {
            if(!edge[i])
                continue;
            int y = ver[i];
            if(d[y] > d[x] + cost[i] || d[x] + cost[i] <= 200)
            {
                //cnt ++;
                d[y] = d[x] + cost[i];
                incf[y] = min(incf[x], edge[i]);
                pre[y] = i;
                if(!v[y])
                {
                    q.push(y);
                    v[y] = true;
                }
            }
        }
    }
    //cout << d[t] << endl;
    if(d[t] >= 0x3f3f3f3f)   
        return false;
    return true;
}

void Edmonds_Karp(int s, int t)
{
    int x = t;
    while(x != s)
    {
        int i = pre[x];
        edge[i] -= incf[t];
        edge[i ^ 1] += incf[t];
        x = ver[i ^ 1];
    }
    //cout << cnt << "" << endl;
    maxflow += incf[t];
    mincost += d[t] * incf[t];
}



signed main()
{
    int s, t;
    cout << "calculating..." << endl;
    //freopen("P3381_8.in", "r", stdin);
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i ++)
    {
        input(u, vv, w, c);
        if(c >= 0)
        {
            add(u, vv, w, c);
            add(vv, u, 0, -c);
        }
        else
        {
            add(vv, u, w, -c);
            add(u, vv, 0, c);
            total[u] -= w;
            total[vv] += w;
            mincost += w * c;
        }
    }

    int st = n + 1, tt = n + 2;
    for(int i = 1; i <= n; i ++){
        if(!total[i])
            continue;
        if(total[i] > 0)
        {
            add(st, i, total[i], 0);
            add(i, st, 0, 0);
        }
        else
        {
            add(i, tt, -total[i], 0);
            add(tt, i, 0, 0);
        }
    }

    add(t, s, INF, 0);
    add(s, t, 0, 0);

    cout << "running main..." << endl;


    while(spfa(st, tt))
    {
        cout << st << " " << tt << endl;
        cout << "EK1" << endl;
        Edmonds_Karp(st, tt);
        cout << "FINISH EK1" << endl;
    }

    cout << "OUT" << endl;

    maxflow = 0;
    while(spfa(s, t))
    {
        cout << "EK" << endl;
        Edmonds_Karp(s, t);
    }
    
    cout << maxflow << " " << mincost << endl;

    return 0;
}