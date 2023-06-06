#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

struct node
{
    int f, c, l;
}R[N << 2];

int n, m;
long long ans;
int size[N], root[N], dis[N], ls[N], rs[N];
long long sum[N];

void build(int now)
{
    size[now] =  1;
    root[now] = now;
    sum[now] = R[now].c;
}

int merge(int a, int b)
{
    if(!a || !b)
        return a + b;
    
    if(R[a].c < R[b].c)
        swap(a, b);
    
    rs[a] = merge(rs[a], b);

    if(dis[ls[a]] < dis[rs[a]])
        swap(ls[a], rs[a]);

    dis[a] = dis[rs[a]] + 1;

    return a;
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
    {
        int b, c, l;
        cin >> b >> c >> l;

        R[i] = (node){b, c, l};

        ans = max((long long)(R[i].l), ans);

        build(i);
    }

    for(int i = n; i > 1; i --)
    {
        int fa = R[i].f;
        
        root[fa] = merge(root[i], root[R[i].f]);
        size[fa] += size[i];
        sum[fa] += sum[i];

        while(sum[fa] > m)
        {
            sum[fa] -= R[root[fa]].c;
            root[fa] = merge(ls[root[fa]], rs[root[fa]]);
            size[fa] --;
        }

        ans = max(ans, (long long)(R[fa].l) * (long long)(size[fa]));
    }

    cout << ans << endl;

    return 0;
}