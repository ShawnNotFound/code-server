#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

#define mian main

using namespace std;

const int N = 52;
int n, m;
int t, k;
const int P = 10000;

struct matrix
{
    int m[N][N];

    matrix()
    {
        memset(m, 0, sizeof(m));
    }

    matrix operator * (const matrix &p) const
    {
        matrix tmp;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                for(int k = 0; k < n; k ++)
                    tmp.m[i][j] = (tmp.m[i][j] + m[i][k] * p.m[k][j]) % P;

        return tmp;
    }   
}a[15], b, c;

matrix pow()
{
    matrix ans = b, tmp = a[0];
    int temporary = k / 12;
    while(temporary)
    {
        if(temporary & 1)
            ans = ans * tmp;
        tmp = tmp * tmp;
        temporary >>= 1;
    }
    return ans;
}

int nfish, temp[50], st, ed;

int mian()
{
    cin >> n >> m >> st >> ed >> k;

    while(m --)
    {
        int x, y;
        cin >> x >> y;
        c.m[x][y] = c.m[y][x] = 1;
    }

    for(int i = 1; i <= 12; i ++)
        a[i] = c;
    for(int i = 0; i < n; i ++)
        b.m[i][i] = 1;

    cin >> nfish;

    while(nfish --)
    {
        cin >> t;
        for(int i = 0; i < t; i ++)
            cin >> temp[i];
        temp[t] = temp[0];

        for(int i = 1; i <= 12; i ++)
            for(int j = 0; j < n; j ++)
                a[i].m[j][temp[(i - 1) % t + 1]] = 0;
    }

    a[0] = b;
    for(int i = 1; i <= 12; i ++)
        a[0] = a[0] * a[i];
    
    matrix ans = pow();

    for(int i = 1; i <= k % 12; i ++)
        ans = ans * a[i];
    
    cout << ans.m[st][ed] << endl;

    return 0;
}