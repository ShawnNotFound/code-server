//brute force
//n^4,能过一个点就是奇迹hhhc
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

#define int long long

using namespace std;

int origin_map[210][210], map[210][210]; 
int maxs, s, m, n;

signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            cin >> origin_map[i][j];
            map[i][j] = map[i][j - 1] + map[i - 1][j] - map[i - 1][j - 1] + origin_map[i][j];
        }
    int i, j, x, y;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            for(int x = i; x <= n; x ++)
                for(int y = j; y <= m; y ++)
                    if(map[x][y] + map[i - 1][j - 1] - map[x][j - 1] - map[i - 1][y] > 0)
                        maxs = max(maxs, (x - i + 1) * (y - j + 1));

    cout << maxs << endl;

    return 0;
}