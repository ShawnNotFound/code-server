#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 15;

using namespace std;

int map[N][N];
int f[N * 2][N][N];

inline int max(int a, int b, int c, int d)
{
    int tmp = max(a, b);
    tmp = max(tmp, c);
    return max(tmp, d);
}

int main()
{
    int n, x, y, num;
    cin >> n;
    while(1)
    {
        cin >> x >> y >> num;
        if(x == 0) break;
        else 
        {
            map[x][y] = num;
        }
    }    

    //f[k][i1][i2], j1 = k - i1, j2 = k - i2

    int i1 = 0, i2 = 0;

    for(int k = 1; k <= n * 2; k ++)
    {
        for(int i1 = 1; i1 <= n; i1 ++)
        {
            for(int i2 = 1; i2 <= n; i2 ++)
            {
                /*
                1.①向右，②向右 f[k - 1][i1][i2] + map[i1][k - i1] + map[i2][k - i2]
                2.①向下，②向下 f[k - 1][i1 - 1][i2 - 1] + map[i1][k - i1] + map[i2][k - i2]
                */
                if(i1 == i2)
                {
                    f[k][i1][i2] = max(f[k - 1][i1][i2], f[k - 1][i1 - 1][i2], f[k - 1][i1][i2 - 1], f[k - 1][i1 - 1][i2 - 1]) + map[i1][k - i1];
                    continue;
                }
                f[k][i1][i2] = max(f[k - 1][i1][i2], f[k - 1][i1 - 1][i2], f[k - 1][i1][i2 - 1], f[k - 1][i1 - 1][i2 - 1]) + map[i1][k - i1] + map[i2][k - i2];
            }
        }
    }
    cout << f[2 * n - 1][n][n] << endl;

    return 0;
}