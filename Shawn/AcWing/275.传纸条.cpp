#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 55;

using namespace std;

int x, y;
int f[N * 2][N][N], map[N][N];

inline short max(int a, int b, int c, int d)
{
    int tmp = max(a, b);
    tmp = max(tmp, c);
    return max(tmp, d);
}

int main()
{
    cin >> x >> y;
    for(int i = 1; i <= x; i ++)
        for(int j = 1; j <= y; j ++)
            cin >> map[i][j];

    for(int k = 1; k <= x + y; k ++)
        for(int i1 = 1; i1 <= x; i1 ++)
            for(int i2 = 1; i2 <= x; i2 ++)
            {
                if(k - i1 <= 0 || k - i1 > y || k - i2 <= 0 || k - i2 > y) continue;
                if(i1 == i2)
                {
                    f[k][i1][i2] = max(f[k - 1][i1][i2], f[k - 1][i1 - 1][i2], f[k - 1][i1][i2 - 1], f[k - 1][i1 - 1][i2 - 1]) + map[i1][k - i1];
                    continue;
                }
                f[k][i1][i2] = max(f[k - 1][i1][i2], f[k - 1][i1 - 1][i2], f[k - 1][i1][i2 - 1], f[k - 1][i1 - 1][i2 - 1]) + map[i1][k - i1] + map[i2][k - i2];
            }

    cout << f[x + y][x][x];

    return 0;
}