// %%% GrainRain，谷神永远的神Orz
// c好水

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define mod %
#define int long long 

const int N = 1e5 + 10;

using namespace std;

int ans[N];//2k - 1
int cnt;
int n;

bool cmp(int a, int b)
{
    return a < b;
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 1; i <= sqrt(n * 1.0); i ++)
    {
        if(!(n mod i))
        {
            if(i % 2 && i != 1) 
                ans[++ cnt] = i;
            
            if((n / i) mod 2 && n / i != 1)
                ans[++ cnt] = n / i;
        }
    }

    cout << cnt << " ";

    sort(ans + 1, ans + cnt + 1, cmp);

    for(int i = 1; i <= cnt; i ++)
    {
        int res = n / ans[i];
        
        res *= (ans[i] - 1);

        cout << res << " ";
    }

    return 0;
}
