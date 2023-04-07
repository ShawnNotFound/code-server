#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1010;

using namespace std;

int n, m;
int w[N], c[N], d[N], ver[N], nxt[N], head[N];

void add(int x, int y)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        cin >> w[i];
    for(int i = 1; i <= n; i ++)
        cin >> c[i];
    for(int i = 1; i <= n; i ++)
        cin >> d[i];
    for(int i = 1; i < n; i ++)
    {
        int from, to;
        cin >> from >> to;
        add(from, to);
    }

    
}