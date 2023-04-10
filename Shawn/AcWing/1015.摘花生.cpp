#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int map[110][110], f[110][110];
int t, r, c;

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i ++)
    {
        cin >> r >> c;
        for(int j = 1; j <= r; j ++)
            for(int k = 1; k <= c; k ++)
                cin >> map[j][k];
        //f[i][j]表示走到map[i][j]的最大获得花生数
        for(int j = 1; j <= r; j ++)
            for(int k = 1; k <= c; k ++)
            {
                f[j][k] += max(f[j - 1][k] + map[j][k], f[j][k - 1] + map[j][k]);
            }
        // for(int j = 1; j <= r; j ++)
        // {
        //     for(int k = 1; k <= c; k ++)
        //         cout << f[j][k] << " ";
        //     cout << endl;
        // }
        cout << f[r][c] << endl;
        memset(f, 0, sizeof(f));
        memset(map, 0, sizeof(map));
    }
}