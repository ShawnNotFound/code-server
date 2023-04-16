#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>

const int N = 1e6 + 10;
const int MEM = 1e5 + 10;

using namespace std;

int n, m, head[MEM], ver[N], nxt[N], a, b, dfn[N], low[MEM];
int scc[N], t, cnt, size[N], minn[N], out[N], cnt2, ans, tot;
bool v[N];
stack<int> q;

void add(int x, int y)
{
    ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++ t;
    v[x] = true;
    q.push(x);

    for(int i = head[x]; i != -1; i = nxt[i])
    {
        int y = ver[i];

        if(!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(v[y])
            low[x] = min(low[x], dfn[y]);
    }


    if(low[x] == dfn[x])
    {
        v[x] = false;
        scc[x] = ++ cnt;
        size[cnt] = 1;

        while(q.top() != x)
        {
            int k = q.top();
            q.pop();

            scc[k] = cnt;
            v[k] = false;
            size[cnt] ++;
        }
        q.pop();
    }
}
int main()
{
    cin.tie(0);
    
    memset(head, -1, sizeof(head));
    memset(low, 0x7f, sizeof(low));
    
    //read
    cin >> n >> m;

    for(int i = 1; i <= m; i ++)
    {
        cin >> a >> b;

        add(a, b);
    }

    //run tarjan
    for(int i = 1;i <= n; i ++)
    {
        if(!dfn[i])
        {
            t = 0;
            tarjan(i);
        }
    }

    //collect answer and make them in the right order
    for(int i = 1; i <= n; i ++)
    {
        for(int j = head[i]; j != -1; j = nxt[j])
        {
            int y = ver[j];

            if(scc[i] != scc[y])
                out[scc[i]] ++;
 		}
    }

    for(int i = 1; i <= cnt; i ++)
    {
        if(out[i] == 0)
        {
            cnt2 ++;
            ans += size[i];
        }
    }

    //output
    cout << (cnt2 == 1 ? ans : 0) << endl;


    return 0;
}
