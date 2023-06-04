#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 1e5 + 10;

using namespace std;

int n, m;
int L[N], R[N], key[N], npl[N], fa[N];

int get_father(int x)
{
    return fa[x] == x ? x : fa[x] = get_father(fa[x]);
}

int combind(int a, int b)
{
    if(!a)
        return b;
    if(!b)
        return a;
    if(key[a] < key[b])
        swap(a, b);

    R[a] = combind(R[a], b);

    if(npl[R[a]] > npl[L[a]])
        swap(L[a], R[a]);

    npl[a] = npl[R[a]] + 1;

    return a;
}

void work(int a, int b)
{
    a = get_father(a);
    b = get_father(b);

    if(a == b)
    {
        cout << -1 << endl;

        return;
    }

    int rt, art, brt;

    key[a] >>= 1;
    rt = combind(L[b], R[b]);

    key[b] >>= 1;
    brt = combind(rt, b);

    fa[rt] = fa[b] = brt;

    rt = combind(art, brt);
    fa[art] = fa[brt] = rt;

    cout << key[rt] << endl;
}

int main()
{
    while(cin >> n)
    {
        npl[0] = -1;
        for(int i = 1; i <= n; i ++)
        {
            L[i] = R[i] = npl[i] = 0;
            fa[i] = i;
            cin >> key[i];
        }
        cin >> m;

        for(int i = 1; i <= m; i ++)
        {
            int m1, m2;
            cin >> m1 >> m2;
            work(m1, m2);
        }
    }
}