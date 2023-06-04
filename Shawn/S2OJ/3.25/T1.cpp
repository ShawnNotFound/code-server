//直接跑最短路20pts

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

const int N = 3e5 + 10;

using namespace std;

int ver[N], head[N], nxt[N], edge[N], d[N];
bool marked[N], v[N];
int m, n, k, s, t, tot;
priority_queue<pair<int, int> > q;

void add(int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}

void dijkstra()
{
    memset(v, false, sizeof(v));
    memset(d, 0x3f, sizeof(d));
    q.push(make_pair(0, s));
    
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

int main()
{
    cin >> n >> m >> k >> s >> t;
    int x, y, z;
    for(int i = 1; i <= m; i ++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
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
        cin >> mk;
        marked[mk] = true;
    }

}


