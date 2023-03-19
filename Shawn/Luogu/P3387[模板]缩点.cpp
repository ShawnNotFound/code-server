#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>

#define maxn 100001
#define maxm 500001

using namespace std;

int nxt[maxm], fr[maxm], ver[maxm];
queue <int> q;
vector <int> cb[maxn];
vector <int> rdr[maxn];
int ans[maxn], totq, x, y, v, rd[maxn], u, n, m, sum, vis[maxn], d[maxn], dis[maxn];
int dfn[maxn], low[maxn], f[maxn], times, cntqq;
int stk[maxn], heads[maxm], visit[maxn], cnt, tot, idx;
void add(int x, int y)
{
    nxt[++ cntqq] = heads[x], fr[cntqq] = x, ver[cntqq] = y, heads[x] = cntqq;
}

void tuopu()
{
	for(int i = 1;i <= tot; i ++)
    {
        if(rd[i] == 0)
        q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans[++ totq] = u;
        for(int i = 1;i <= cb[u].size(); i ++)
        {
            v = cb[u][i - 1];
            rd[v] --;
            if(rd[v] == 0)
                q.push(v);
        }
    }
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++ times;
    stk[++ idx] = x;
    visit[x] = 1;

   	for(int i = heads[x];i != -1; i = nxt[i])
    {
        if(!dfn[ver[i]])
        {
           	tarjan(ver[i]);
            low[x] = min(low[x], low[ver[i]]);
       	}
       	else if(visit[ver[i]])
            low[x] = min(low[x], dfn[ver[i]]);
    }

    if(low[x] == dfn[x])
   	{
   		tot ++;
   		while(1)
       	{
       		vis[stk[idx]] = tot;
       		d[tot] += dis[stk[idx]];
       		visit[stk[idx]] = 0;
            idx --;
       		if(x == stk[idx + 1])
                break;
       	}
    }
}
int main(){

    memset(heads, -1, sizeof(heads));

    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n; i ++)
    scanf("%d", &dis[i]);
    for(int i = 1;i <=m;i ++)
    {
        scanf("%d%d", &x, &y);
       	add(x, y);
    }

    for(int i = 1;i <= n;i ++)
        if(!dfn[i])
            tarjan(i);
    
    for(int i = 1;i <= cntqq;i ++)
    {
        if(vis[fr[i]] != vis[ver[i]])
        {
            x = vis[fr[i]];y=vis[ver[i]];
			rd[y] ++;
            cb[x].push_back(y);
            rdr[y].push_back(x);
        }
    }

    tuopu();

    for(int i = 1;i <= tot;i ++)
    {
        int w = ans[i];
        f[w] = d[w];
        for(int j = 1;j <= rdr[w].size(); j ++)
        f[w] = max(f[w], f[rdr[w][j - 1]] + d[w]);
    }

    for(int i = 1;i <= tot;i ++)
        sum = max(f[i], sum);

    cout << sum << endl;
    return 0;
}