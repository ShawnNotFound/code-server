#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 210;

using namespace std;

int n, ans = 0;
int map[N][N];
char tmp[N];

int getl(int x, int y)
{
    int cnt = 0;
    for(int i = 1; i <= min(x, y); i ++)
    {
        if(map[x + i][y + i] == 2 && map[x - i][y - i] == 2)
            continue;
        if(map[x + i][y + i] == 0 && map[x - i][y - i] == 0)
            return cnt;
        if(map[x + i][y + i] == 1 && map[x - i][y - i] == 1)
        {
            cnt += 2;
        }
    }
}

int getr(int x, int y)
{
    int cnt = 0;
    for(int i = 1; i <= min(x, y); i ++)
    {
        if(map[x + i][y - i] == 2 && map[x - i][y + i] == 2)
            continue;
        if(map[x + i][y - i] == 0 && map[x - i][y + i] == 0)
            return cnt;
        if(map[x + i][y - i] == 1 && map[x - i][y + i] == 1)
        {
            cnt += 2;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n * 2; i += 2)
    {
        cin >> tmp + 1;
        for(int j = 1; j <= n; j ++)
            map[i][j * 2 - 1] = tmp[j] - '0';
        // cout << i << " " << j << endl;;
    }    
        
    for(int i = 2; i < n * 2; i += 2)
        for(int j = 2; j < n * 2; j += 2)
            map[i][j] = 2;

    // for(int i = 1; i <= n * 2; i ++)
    // {
    //     for(int j = 1; j <= n * 2; j ++)
    //         cout << map[i][j] << " ";
    //     cout << endl;
    // }

    for(int i = 1; i <= n * 2; i ++)
        for(int j = 1; j <= n * 2; j ++)
        {
            if(map[i][j])
            {
                int l = getl(i, j);
                int r = getr(i, j);
                //cout << l << " " << r << endl;
                int res = min(l, r);
                for(; res >= 2; res -= 2)
                    ans ++;

            }
        }

    cout << ans << endl;
}


// 1 0 0 0 0 0 0 0 1
// 0 2 0 2 0 2 0 2 0
// 0 0 1 0 0 0 1 0 0
// 0 2 0 2 0 2 0 2 0
// 0 0 0 0 1 0 0 0 0
// 0 2 0 2 0 2 0 2 0
// 0 0 1 0 0 0 1 0 1
// 0 2 0 2 0 2 0 2 0
// 0 0 0 0 0 0 1 0 1
