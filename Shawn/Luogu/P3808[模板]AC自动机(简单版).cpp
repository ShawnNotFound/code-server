#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

const int N = 1e6 + 10;

using namespace std;

namespace AC
{
    int tr[N][26], tot;
    int e[N], fail[N];

    void insert(char *s)
    {
        int u = 0;

        for(int i = 1; s[i]; i ++)
        {
            if(!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++ tot;

            u = tr[u][s[i] - 'a'];
        }

        e[u] ++;
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
        int u, res = 0;

        for(int i = 1; t[i]; i ++)
        {
            u = tr[u][t[i] - 'a'];

            for(int j = u; j && e[j] != -1; j = fail[j])
            {
                res += e[j];
                e[j] = -1;
            }
        }

        return res;
    }
}

using namespace AC;

int n;
char s[N];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        cin >> s + 1;
        insert(s);
    }

    cin >> s + 1;

    build();

    cout << query(s) << endl;

    return 0;
}
