#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

const int N = 1e7 + 10;

using namespace std;

int head[N], ver[N], nxt[N], c[N], dcc;
int dfn[N], low[N], n, m, tot, num;
bool bridge[N];

void add(int x, int y)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
    ver[++ tot] = x, nxt[tot] = head[y], head[y] = tot;
}

void tarjan(int x, int in_edge)
{
    dfn[x] = low[x] = ++ num;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(!dfn[y])
        {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if(low[y] > dfn[x])
                bridge[i] = bridge[i ^ 1] = true;
        }
        else if(i != (in_edge ^ 1))
            low[x] = min(low[x], dfn[y]);
    }
}

void dfs(int x)
{
    c[x] = dcc;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(c[y] || bridge[i])
            continue;
        dfs(y);
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
        add(x, y);
    }
    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
            tarjan(i, 0);
        
    for(int i = 1 ; i <= n; i ++)
        if(!c[i])
        {
            ++ dcc;
            dfs(i);
        }
    
    cout << dcc << endl;

    for(int i = 1; i <= n; i ++)
        cout << i << " " << c[i] << endl;

    cout << endl;

    int cnt[dcc + 5];
    vector<int> ans[dcc + 5];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i ++)
    {
        ans[c[i]].push_back(i);
        cnt[c[i]] ++;
    }
    for(int i = 1; i <= dcc; i ++)
    {
        cout << cnt[i] << " ";
        while(ans[i].size())
        {
            cout << ans[i][ans[i].size() - 1] << " ";
            ans[i].pop_back();
        }
        cout << endl;
    }

    return 0;
}