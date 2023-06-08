#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<deque>

const int N = 2e5 + 10;
const int T = 2e6 + 10;

using namespace std;

int n;
int cnt[N];
char s[N], t[T];

struct AC
{
    struct node
    {
        int son[30];
        int val;
        int fail;
        int head;
        deque<int> index;
    } nd[N];

    struct edge
    {
        int head;
        int nxt;
    } e[N + 10];

    int rt;
    int ncnt; 
    int ecnt;

    void insert(char *str, int i)
    {
        int u = rt;
        for(int i = 1; str[i]; i ++)
        {
            if(!nd[u].son[str[i] - 'a' + 1])
                nd[u].son[str[i] - 'a' + 1] = ++ ncnt;

            u = nd[u].son[str[i] - 'a' + 1];
        }

        nd[u].index.push_back(i);
        return;
    }


    void build()
    {
        deque<int> q;
        for(int i = 1; i <= 26; i ++)
            if(nd[rt].son[i])
                q.push_back(nd[rt].son[i]);

        while(q.size())
        {
            int u = q.front();
            q.pop_front();

            for(int i = 1; i <= 26; i ++)
            {
                if(nd[u].son[i])
                {
                    nd[nd[u].son[i]].fail = nd[nd[u].fail].son[i];
                    q.push_back(nd[u].son[i]);
                }
                else
                {
                    nd[u].son[i] = nd[nd[u].fail].son[i];
                }
            }
        }
        return;
    }

    void query(char *str)
    {
        int u = rt;
        for(int i = 1; str[i]; i ++)
        {
            u = nd[u].son[str[i] - 'a' + 1];
            nd[u].val ++;
        }

        return;
    }

    void add(int tail, int head)
    {
        e[++ ecnt].head = head, e[ecnt].nxt = nd[tail].head, nd[tail].head = ecnt;
    }

    void dfs(int u)
    {
        for(int i = nd[u].head; i; i = e[i].nxt)
        {
            int v = e[i].head;
            dfs(v);

            nd[u].val += nd[v].val;
        }

        for(auto i : nd[u].index)
            cnt[i] += nd[u].val;

        return;
    }


    void ft()
    {
        for(int u = 1; u <= ncnt; u ++)
            add(nd[u].fail, u);

        dfs(rt);

        return;
    }
}ac;

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        cin >> s + 1; 
        ac.insert(s, i);
    }

    ac.build();

    cin >> t + 1; 
    
    ac.query(t);
    
    ac.ft();

    for(int i = 1; i <= n; i ++)
        cout << cnt[i] << endl;

    return 0;
}
