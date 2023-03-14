#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

const int N = 50 + 5;
const int M = 1e3 + 5; 
const int K = 50 + 5;

using namespace std;

int head[N * K], ver[M * K], edge[M * K], nxt[M * K] tot;
bool v[M * K];
int n, m, k, a, b, t, ans = 0x3f;

priority_queue<pair<int, int>> q;
int d[M * K];

void add(int x, int y, int z)
{
    ver[++ tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void build(int x, int y, int z)
{
    for(int i = 0; i <= k - 1; i ++)
    {
        add(n * i + x, n * (i + 1) + y, z / 2);
    }
}

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[1] = 0;
    q.push(make_pair(0, 1));

    while(q.size())
    {
        int x = q.top().second; q.pop();
        if(v[x]) continue;
        v[x] = true;
        
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i], z = edge[z];
            if(d[y] > d[x] + z)
            {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], ))
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a >> b >> t;
        build(a, b, t);
        build(b, a, t);
    }

    dijkstra();

    for(int i = 1; i <= k; i ++)
        ans = min(ans, d[n * i]);

    cout << ans;
    
    return 0;
}