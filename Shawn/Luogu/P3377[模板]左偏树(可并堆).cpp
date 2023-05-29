#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

int n, m, op, x, y;
int lc[N], rc[N], dist[N], rt[N];
bool tf[N];

struct node
{
    int id, v;
    bool operator<(node x)const
    {
        return v == x.v ? id < x.id : v < x.v;
    }
}v[N];

int find(int x)
{
    return rt[x] == x ? x : rt[x] = find(rt[x]);
}

int merge(int x, int y)
{
    if(!x || !y)
        return x + y;

    if(v[y] < v[x])
        swap(x, y);

    rc[x] = merge(rc[x], y);

    if(dist[lc[x]] < dist[rc[x]])
        swap(lc[x], rc[x]);

    dist[x] = dist[rc[x]] + 1;
    return x;
}

int main()
{
    dist[0] = 1;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
    {
        cin >> v[i].v;
        rt[i] = i;
        v[i].id = i;
    }

    while(m --)
    {
        cin >> op >> x;
        if(op == 1)
        {
            cin >> y;
            if(tf[x] || tf[y])
                continue;
            
            x = find(x);
            y = find(y);

            if(x != y)
                rt[x] = rt[y] = merge(x, y);
        }

        if(op == 2)
        {
            if(tf[x])   
            {
                cout << -1 << endl;
                continue;
            }
            x = find(x);
            cout << v[x].v << endl;

            tf[x] = true;
            rt[lc[x]] = rt[rc[x]] = rt[x] = merge(lc[x], rc[x]);
            lc[x] = rc[x] = dist[x] = 0;
        }
    }

    return 0;
}