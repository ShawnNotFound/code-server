#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

const int N = 156, L = 1e6 + 10;

const int SZ = N * 80;

using namespace std;

namespace AC
{
    int tot; 
    int tr[SZ][26];
    int fail[SZ], idx[SZ], val[SZ];
    int cnt[N];

    void init()
    {
        tot = 0;
        memset(tr, 0, sizeof(tr));
        memset(val, 0, sizeof(val));
        memset(idx, 0, sizeof(idx));
        memset(cnt, 0, sizeof(cnt));
        memset(fail, 0, sizeof(fail));
    }  

    void insert(char *s, int id)
    {
        int u = 0;
        for(int i = 1; s[i]; i ++)
        {
            if(!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++ tot;

            u = tr[u][s[i] - 'a'];
        }

        idx[u] = id;
    }

    queue<int> q;

    void build()
    {
        for(int i = 0; i < 26; i ++)
            if(tr[0][i])
                q.push(tr[0][i]);

        while(q.size())
        {
            int u = q.front();

            q.pop();

            for(int i = 0; i < 26; i ++)
            {
                if(tr[u][i])
                {
                    fail[tr[u][i]] = tr[fail[u]][i];
                    q.push(tr[u][i]);
                }
                else
                    tr[u][i] = tr[fail[u]][i];
            }
        }
    }

    int query(char *t)
    {
        int u = 0, res = 0;

        for(int i = 1; t[i]; i ++)
        {
            u = tr[u][t[i] - 'a'];
            for(int j = u; j; j = fail[j])
                val[j] ++;
        }

        for(int i = 0; i <= tot; i ++)
            if(idx[i])
            {
                res = max(res, val[i]);
                cnt[idx[i]] = val[i];
            }

        return res;
    }
}
using namespace AC;

int n;
char s[N][100], t[L];

int main()
{
    while(cin >> n)
    {
        if(n == 0)
            break;
            
        init();

        for(int i = 1; i <= n; i ++)
        {
            cin >> s[i] + 1;
            insert(s[i], i);
        }

        build();
        
        cin >> t + 1; 
        int x = query(t);

        cout << x << endl;

        for(int i = 1; i <= n ; i ++)
            if(cnt[i] == x)
                cout << s[i] + 1 << endl;
    }

    return 0;
}