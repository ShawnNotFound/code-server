#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

int n, m, q;

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
        if(a.a[i] > b.a[i])
            return true;
        else if(a.a[i] < b.a[i])
            return false;
    }
}

int main()
{
    cin >> m >> n >> q;
    for(int i = 1; i <= n; i ++)
    {
        cin >> qs[i].a ;
    }

    sort(qs + 1, qs + 1 + n, cmp);

    for(int i = 1; i <= q; i ++)
    {
        cin >> s[i].a;
    }



    for(int i = 1; i <= q; i ++)
    {
        // cout << qs[1].a << endl;
        if(cmp(s[i], qs[1]))
            cout << s[i].a << endl;
        else 
            cout << qs[1].a << endl;
    }

    // m = 4;
    // cin >> qs[1].a >> s[1].a;
    // if(cmp(qs[1], s[1]))
    //     cout << qs[1].a << endl;
    // else
    //     cout << s[1].a << endl;

    return 0;
}

// 10 2 2 
// 0111111111   
// 0000001000
// 1000001000
// 0101111111