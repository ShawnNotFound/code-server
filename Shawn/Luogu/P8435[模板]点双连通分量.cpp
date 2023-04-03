#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

const int N = 1e7 +10;

using namespace std;

int head[N], ver[N], nxt[N];
int dfn[N], low[N], stack[N];
int n, m, tot, num, root, cnt, top;
bool cut[N];
vector<int> dcc[N];

void add(int x, int y)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, nxt[tot] = head[y], head[y] = tot;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++ num;
    stack[++ top] = x;
    if(x == root && head[x] == 0)
    {
        dcc[++ cnt].push_back(x);
        return;
    }
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
                    cut[x] = true;
                cnt ++;
                int z;
                do
                {
                    z = stack[top --];
                    dcc[cnt].push_back(z);
                }while(z != y);
                dcc[cnt].push_back(x);
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

    for(int i = 1; i <= cnt; i ++)
    {
        cout << dcc[i].size() << " ";
        for(int j = 0; j < dcc[i].size(); j ++)
            cout << dcc[i][j] << " ";
        cout << endl;
    }

    return 0;

}
