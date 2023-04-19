#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define int long long

const int N = 5e6;

using namespace std;

int p[N], f[N], buc[N], vis[N];
int l, r, tot;

struct miao
{
    int a, b, w;
}edges[N];

bool operator< (const miao &a, const miao &b)
{
	return a.w < b.w;
}


int find(int x)//------?
{
    if(p[x] != x) 
        p[x] = find(p[x]);
    else 
        return x;
} 

void Kruskal()
{
    int res = 0, cnt = 0;
    for(int i = 1;i <= tot; i ++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        if(find(a) != find(b))
        {
            p[find(a)] = p[find(b)];
            cnt ++;
            res += w;
        }
    }

    // if(cnt==n-1) 
        cout << res << endl;
    // else
    //     cout << "impossible" << endl;
}


int gcd(int a, int b)
{
    return b ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}


signed main()
{
    cin >> l >> r;

    // for(int i = s + 1; i <= t; i ++)
    // {
    //     for(int k = 1; k * i <= t; i ++)
    //         edges[++ tot] = {i, i * k, i * k};
    // }

    for (int i = l;i <= r;++i) 
    {
        f[i] = i;
        buc[i] = 1;
    }
    for (int i = 2;i <= r; i ++) 
    {
        int cnt = 0,fis = 0;
        
        for (int j = i; j <= r; j += i) 
        {
            if (buc[j] && !fis) 
                fis = j;
            if (buc[j]) 
                edges[++ tot] = {fis, j, lcm(fis, j)};
            vis[j] = 1;
        }

        if (i >= l) 
            edges[++ tot] = (miao){fis, l, lcm(fis, l)};
    }

    sort(edges + 1, edges + tot + 1);

    Kruskal();

    return 0;
}