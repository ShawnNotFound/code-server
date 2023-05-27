#include <iostream>
#include <vector>
#include<cstring>

using namespace std;

const int N = 35;

int a[1010][1010], b[1010];

void Gauss(int n) 
{
    for(int i = 1; i <= n; i ++) 
    {
        int r = i;
        for (int j = i + 1; j <= n; j ++)
            if (a[j][i]) 
            { 
                r = j; 
                break; 
            }

        if(r != i) 
            for(int j = 1; j <= n + 1; j ++) 
                swap(a[i][j], a[r][j]);

        for(int k = i + 1; k <= n; k ++)
            if(a[k][i])
                for(int j = i; j <= n + 1; j ++)
                    a[k][j] ^= a[i][j];

    }
    for(int i = n; i >= 1; i --) 
    {
        b[i] = a[i][n + 1];
        for(int j = i - 1; j >= 1; j --)
            if(a[j][i])    
                a[j][n + 1] ^= b[i];
    }
}
int main() 
{
    // freopen("t2.in", "r", stdin);
    // freopen("t2.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T --)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n * m; i ++) 
        {
            char tmp;
            int x;
            cin >> tmp;
            
            x = tmp - 'A';
            
            if(x) 
                a[i][n * m + 1] ^= 1;
            
            a[i][(i - 1) % m + 1 + m * ((i - 1) / m)] ^= 1;

            if((i - 1) % m != 0) 
                a[i][(i - 2) % m + 1 + m * ((i - 2) / m)] ^= 1;

            if((i - 1) % m != m - 1) 
                a[i][i % m + 1 + m * (i / m)] ^= 1;

            if((i - 1) / m != 0) 
                a[i][(i - 1) % m + 1 + m * ((i - 1) / m - 1)] ^= 1;

            if((i - 1) / m != n - 1) 
                a[i][(i - 1) % m + 1 + m * ((i - 1) / m + 1)] ^= 1;
        }

        Gauss(n * m);

        int ans = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if(b[(i - 1) * m + j])  
                    ans ++;
            
        cout << ans << endl;
    }

    return 0;
}
