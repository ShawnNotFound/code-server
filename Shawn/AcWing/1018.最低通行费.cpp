#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
const int N = 1e2 + 10;
using namespace std;

struct road
{
    int t;
    int c;
}f[N][N];

int map[N][N];

int main()
{
    int n;
    cin >> n;
    int t = 2 * n - 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> map[i][j];
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(f[i - 1][j].c + map[i][j] > f[i][j - 1].c + map[i][j])
            {
                f[i][j].c = f[i][j - 1].c + map[i][j];
                f[i][j].t = f[i][j - 1].t + 1;
                if(f[i][j].t == t && i != n && j != n)
                {
                    f[i][j].c = f[i - 1][j].c + map[i][j];
                    f[i][j].t = f[i - 1][j].t + 1;
                        if(f[i][j].t == t && i != n && j != n)
                            f[i][j].c = 0x3f;
                } 
            }
            if(f[i - 1][j].c + map[i][j] < f[i][j - 1].c + map[i][j])
            {
                f[i][j].c = f[i - 1][j].c + map[i][j];
                f[i][j].t = f[i - 1][j].t + 1;
                if(f[i][j].t == t && i != n && j != n)
                {
                    f[i][j].c = f[i][j - 1].c + map[i][j];
                    f[i][j].t = f[i][j - 1].t + 1;
                        if(f[i][j].t == t && i != n && j != n)
                            f[i][j].c = 0x3f;
                } 
            }
            if(f[i - 1][j].c == f[i][j - 1].c)
            {
                f[i][j].c = f[i - 1][j].c;
                f[i][j].t = min(f[i - 1][j].t, f[i][j - 1].t) + 1;
                if(f[i][j].t == t && i != n && j != n)
                    f[i][j].c = 0x3f;
            }
        }
    
    cout << f[n][n].c;

    return 0;
}