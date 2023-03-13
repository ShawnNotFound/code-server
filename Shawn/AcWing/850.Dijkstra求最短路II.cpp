#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

const int N = 2e5 + 10;

using namespace std;

priority_queue<pair<int, int>> q;

int nxt[N], ver[N], head[N], edge[N], d[N];
bool v[N];
int n, m, tot;

void add(int a, int b, int c)
{
    ver[++ tot] = b;
    edge[tot] = c;
    nxt[tot] = head[a];
    head[a] = tot;
}

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    q.push(make_pair(0, 1)), d[1] = 0;
    while(q.size())
    {
        int x = q.top().second; q.pop();
        if(v[x]) continue;
        v[x] = true;
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i], z = edge[i];
            if(d[x] + z < d[y])
            {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            } 
        }
    }
}

int main()
{
    int a, b, c;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        cin >> a >> b >> c;
        add(a, b, c);
    }

    dijkstra();

    if(d[n] == 0x3f3f3f3f)
    {
        cout << "-1" << endl;
        return 0;
    }

    cout << d[n] << endl;

    return 0;
}
