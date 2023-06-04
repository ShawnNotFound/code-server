#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

int n, m, q, now;

struct node
{
    char a[50];
}qs[N], s[N];

bool cmp(node a, node b)
{
    // if(strlen(a.a) != strlen(b.a))
    //     return strlen(a.a) > strlen(b.a);
    for(int i = 0; i < m; i ++)
    {
        // cout << "cmp " << i << " " << a.a[i] << " " << b.a[i] << endl;
        if(a.a[i] == '-')
            a.a[i] = s[now].a[i];
        if(a.a[i] > b.a[i])
            return true;
        else if(a.a[i] < b.a[i])
            return false;
    }
}

node build(node tmp)
{
    node ans;
    for(int i = 0; i < m; i ++)
    {
        if(tmp.a[i] == '-')
            ans.a[i] = s[now].a[i];
        else
            ans.a[i] = tmp.a[i];
    }

    return ans;
}

int main()
{
    cin >> m >> n >> q;
    for(int i = 1; i <= n; i ++)
    {
        cin >> qs[i].a ;
    }


    for(int i = 1; i <= q; i ++)
    {
        cin >> s[i].a;
    }
    for(now = 0; now <= n; now ++)
    {
        for(int i = 1; i <= 10000; i ++)
        {
            sort(qs + 1, qs + 1 + n, cmp);

            if(!cmp(s[now], qs[1]))
                for(int j = 1; j <= m; j ++)
                    s[now].a[j] = build(qs[1]).a[j];
        }
        cout << s[now].a << endl;

    }


    // for(int i = 1; i <= q; i ++)
    // {
    //     if(cmp(s[i], qs[1]))
    //         cout << s[i].a << endl;
    //     else 
    //         cout << qs[1].a << endl;
    // }

    return 0;
}

/*
5 3 1
-1-01
011-0
--010
00000
*/