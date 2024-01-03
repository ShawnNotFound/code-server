#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long

const int N = 300 + 10;

using namespace std;

int n;
int h[N];
int map[N][N];

signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> h[i];

    cout << "0 ";

    for(int i = 1; i <= n; i ++)    
    {
        map[1][i] = 0;
    }
    for(int d = 2; d <= 3; d ++)
    {
        int minn = 1e15 + 10;
        for(int i = 1; i <= n - d + 1; i ++)
        {
            map[d][i] = abs(h[i + d - 1] - h[i]);
            minn = min(minn, map[d][i]);
        }

        cout << minn << " ";
    }

    for(int d = 4; d <= n; d ++)
    {
        int minn = 1e15 + 10;

        for(int i = 1; i <= n - d + 1; i ++)
        {
            map[d][i] = map[d - 2][i + 1] + abs(h[i + d - 1] - h[i]);
            minn = min(minn, map[d][i]);
        }

        cout << minn << " ";
    }


    return 0;
}