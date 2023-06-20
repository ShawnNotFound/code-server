// A. 简单的序列（bracket）

#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>


#define mod %

#define int long long 

const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int N2 = 2e3 + 10;

using namespace std;

int n, m, minn;
int x[N], f[N2][N2];
int ans, be;
char tmp[N];

signed main()
{
    cin >> n >> m;

    cin >> tmp + 1;

    for(int i = 1; i <= m; i ++)
    {
        x[i] = (tmp[i] == '(' ? 1 : -1);
    }

    // for(int i = 1; i <= m; i ++)
    //     cout << x[i] << endl;

    f[0][0] = 1;
    f[1][1] = 1;

    for(int i = 2; i <= n - m; i ++)
    {
        f[i][0] = f[i - 1][1];

        for(int j = 1; j <= n - m; j ++)
        {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1]) mod M;
        }
    }

    // for(int i = 1; i <= 10; i ++)
    // {
    //     for(int j = 1; j <= 10; j ++)
    //         cout << f[i][j] << " ";
    //     cout << endl;
    // }

    for(int i = 1; i <= m; i ++)
    {
        be += x[i];
        
        minn = min(minn, be);

        // cout << "minn = " << minn << endl;
    }

    for(int i = -minn; i <= n - m; i ++)
    {
        for(int j = -minn; j <= i; j ++)
        {
            int len = n - m - i;
            int ansj = be + j;

            // cout << len << " " << ansj << endl;

            if(ansj >= 0)
            {
                ans = (f[len][ansj] * f[i][j] + ans) mod M;

                // cout << "ans = "<< ans << endl;
            }
        }
    }

    cout << ans << endl;

    return 0;
}