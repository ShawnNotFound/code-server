#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 5e3 + 10;

using namespace std;

int n, m, k;
int f[N][30];
int nxt[N], match[N][50];
char md[N];

void kmp()
{
    nxt[0] = -1;

    for(int i = 1; i <= m; i ++)
    {
        int j = nxt[i - 1];
        while(j != -1 && md[j + 1] != md[i])
            j = nxt[j];
        
        nxt[i] = j + 1;
    }

    nxt[0] = 0;

    for(int i = 0; i < m; i ++)
    {
        for(int j = '0'; j <= '9'; j ++)
        {
            int tmp = i;
            while(md[tmp + 1] != j && tmp > 0)
                tmp = nxt[tmp];
            
            if(md[tmp + 1] == j)    
                tmp ++;
            
            if(tmp < m)
                match[i][tmp] ++;
        }
    }
}


struct matrix
{
    int mt[25][25];

    matrix()
    {
        memset(mt, 0, sizeof(mt));
    }

    matrix operator * (matrix B)
    {
        matrix res;

        memset(res.mt, 0, sizeof(res.mt));

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < m; j ++)
                for(int p = 0; p < m; p ++)
                {
                    (res.mt[i][j] += mt[i][p] * B.mt[p][j]) %= k;
                }

        return res;
    }
}F, G;

matrix qpow(matrix A, int pw)
{
    matrix res;

    for(int i = 0; i <= m; i ++)
        res.mt[i][i] = 1;

    while(pw)
    {
        if(pw & 1)
            res = res * A;

        pw >>= 1;
        A = A * A;
    }

    return res;
}

int main()
{
    cin >> n >> m >> k >> md + 1;

    kmp();

    F.mt[0][0] = 1;

    for(int i = 0; i <= m; i ++)
        for(int j = 0; j <= m; j ++)
            G.mt[i][j] = match[i][j];

    G = qpow(G, n);

    F = F * G;

    int ans = 0;

    for(int i = 0; i < m; i ++)
        (ans += F.mt[0][i]) %= k;
  
    cout << ans << endl;

    return 0;
}