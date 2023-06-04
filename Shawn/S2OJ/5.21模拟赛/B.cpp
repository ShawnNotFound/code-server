// %%% GCY_XZT，这个问题只能交给被万人顶礼膜拜的GCY_XZT来解决了。 
// 我爱打表60pts?

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define int long long
#define mod %

const int N = 20;

using namespace std;

int n, k;
int possibility[N] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000};
int nn, kk, qd, kkk, ans, cnt;
bool vis[N];


signed main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    
    kk = k;
    nn = n;

    while(nn --)
    {
        qd = kk / possibility[nn];

        kkk = kk;

        kk = (kk mod possibility[nn] == 0) ? possibility[nn] : kk mod possibility[nn];

        qd * possibility[nn] < kkk ? qd ++ : 0;
        
        cnt = 0;
        for(ans = 1; ans <= n; ans ++)
        {
            if(!vis[ans]) 
                cnt ++;

            if(cnt == qd)
                break;
        }
        vis[ans] = true;

        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
