#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>

const int N = 1e7 + 10;

using namespace std;

int head[N], ver[N], nxt[N];
int dfn[N], low[N], stack[N];
int n, m, tot, num, root, cnt;
bool cut[N];

void add(int x, int y)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, nxt[tot] = head[y], head[y] = tot;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++ num;
    int flag = 0;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if(low[y] >= dfn[x])
            {
                flag ++;
                if(x != root || flag > 1)
                {
                    if(!cut[x]) 
                        cnt ++;
                    cut[x] = true;
                }
            }
        }
        else
            low[x] = min(low[x], dfn[y]);
    }
}

int main()
{
    cin >> n >> m;
    tot = 1;
    for(int i = 1; i <= m; i ++)
    {
        int x, y;
        cin >> x >> y;
        if(x == y)
            continue;
        add(x, y);
    }
    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
        {
            root = i;
            tarjan(i);
        }

    cout << cnt << endl;
    for(int i = 1; i <= n; i ++)
        if(cut[i])
            cout << i << " ";
    cout << endl;
    return 0;
}