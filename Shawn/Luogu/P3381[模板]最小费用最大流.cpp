#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

//#define int long long
const int N = 1e6 + 10;

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
int ver[N], nxt[N], cost[N], head[N], edge[N], incf[N], pre[N], d[N];
int maxflow, ans, u, vv, w, c, n, m, s, t, mincost, tot = 1, cnt;
queue<int> q;

// int num(int i,int k)
// {
//     return i + k * n;
// }

void add(int x, int y, int z, int k)
{
    ver[++ tot] = y, edge[tot] = z, cost[tot] = k, nxt[tot] = head[x], head[x] = tot, ro[tot] = true;
    ver[++ tot] = x, edge[tot] = 0, cost[tot] = -k, nxt[tot] = head[y], head[y] = tot, ro[tot] = false;
}

bool spfa()
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
            if(d[y] > d[x] + cost[i])
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
    if(d[t] == 0x3f3f3f3f)   
        return false;
    return true;
}

void Edmonds_Karp()
{
    int cnt = 0;
    int x = t;
    while(x != s)
    {
        int i = pre[x];
        if(ro[i])
            cnt ++;
        else
            cnt --;
        edge[i] -= incf[t];
        edge[i ^ 1] += incf[t];
        x = ver[i ^ 1];
    }
    //cout << cnt << "" << endl;
    maxflow += incf[t];
    mincost += (d[t] - 200 * cnt) * incf[t];
}



signed main()
{
    //cout << "calculating..." << endl;
    //freopen("P3381_8.in", "r", stdin);
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i ++)
    {
        input(u, vv, w, c);
        //add(num(u, 1), num(vv, 0), w, 0);
        //add(num(u, 0), num(u, 1), w, c);
        add(u, vv, w, c + 200);
    }

    //cout << "running main..." << endl;

    while(spfa())
    {
        //cout << "EK" << endl;
        Edmonds_Karp();
    }
    
    cout << maxflow << " " << mincost << endl;

    return 0;
}