#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

#define len strlen(s)

const int N = 1e5 + 10;

using namespace std;

int n, tot, w, top;
char s[N], tmp[N];
int t[N][26], fail[N], hp[N], mark[N], ie[N];

void insert(char *s)
{
    int now = 0;

    for(int i = 0; i < len; i ++)
    {
        int x = s[i] - 'a';
        if(!t[now][x])
            t[now][x] = ++ tot;

        now = t[now][x];
    }

    ie[now] = len;
}

void solve()
{
    queue<int> q;
    for(int i = 0; i < 26; i ++)
        if(t[0][i])
            q.push(t[0][i]);
    
    while(q.size())
    {
        int now = q.front();
        q.pop();

        for(int i = 0; i < 26; i ++)
        {
            if(!t[now][i])
            {
                t[now][i] = t[fail[now]][i];
                continue;
            }

            fail[t[now][i]] = t[fail[now]][i];
            q.push(t[now][i]);
        }
    } 

    int now = 0;
    w = 0;

    for(int i = 0; i < len; i ++)
    {
        int x = s[i] - 'a';
        now = t[now][x];
        mark[++ top] = now;
        hp[top] = i;

        if(ie[now])
        {
            top -= ie[now];
            if(!top)
                now = 0;
            else
                now = mark[top];
        }
    }
}

int main()
{
    cin >> s >> n;

    for(int i = 1; i <= n; i ++)
    {
        cin >> tmp;
        insert(tmp);
    }

    solve();

    for(int i = 1; i <= top; i ++)
        cout << s[hp[i]];

    return 0;
}