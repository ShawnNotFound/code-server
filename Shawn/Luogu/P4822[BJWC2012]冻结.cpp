#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

const int N = 5000 + 5;
const int M = 1e3 + 5; 
const int K = 5000 + 5;

using namespace std;

int head[M * K], ver[M * K], edge[M * K], nxt[M * K], tot;
bool v[M * K];
int n, m, k, a, b, t, ans = 0x3f3f3f3f;

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
    for(int i = 0; i < k; i ++)
    {
        add(n * i + x, n * i + y, z);
        add(n * i + y, n * i + x, z);
        add(n * i + x, n * (i + 1) + y, z / 2);
        add(n * i + y, n * (i + 1) + x, z / 2);
    }
    add(n * k + x, n * k + y, z);
    add(n * k + y, n * k + x, z);
}

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    //for(int i = 1 ; i <= k + 1; i ++)
    //    d[n * i - n + 1] = 0;
    d[1] = 0;

    q.push(make_pair(0, 1));

    while(q.size())
    {
        int x = q.top().second; q.pop();
        if(v[x]) continue;
        v[x] = true;
        
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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++)
    {
        cin >> a >> b >> t;
        build(a, b, t);
    }

    dijkstra();

    for(int i = 1; i <= k + 1; i ++)
        ans = min(ans, d[n * i]);

    // for(int i = 0; i <= k; i ++)
    // {
    //     for(int j = 1; j <= n; j ++)
    //         cout << d[i * n + j] << " ";
    //     cout << endl;
    // }

    cout << ans << '\n';
    
    return 0;
}
/*
1 --4--> 2
4 --6--> 2

*/

