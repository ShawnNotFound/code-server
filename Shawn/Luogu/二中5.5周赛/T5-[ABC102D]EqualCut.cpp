#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define int long long

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

int n, ans = INF; 
int a[N], qz[N];

// inline int max(int a, int b, int c, int d)
// {
//     return max(a, max(b, max(c, d)));
// }
// inline int min(int a, int b, int c, int d)
// {
//     return min(a, min(b, min(c, d)));
// }

signed main(){
	cin.tie(0);
	cout.tie(0);
	
    cin >> n;

    for (int i = 1; i <= n; i ++) 
    {
        cin >> a[i];
        qz[i] = qz[i - 1] + a[i];
    }
    for (int i = 1, j = 2, k = 3; j < n; j ++) 
    {
        for(; i + 1 < j; i ++)
        {
            int ta = qz[j] - qz[i] * 2;
            int tb = qz[j] - qz[i + 1] * 2;
            if(abs(ta) <= abs(tb))
                break;
        }

        for(; k + 1 < n; k ++)
        {
            int tmp = qz[n] + qz[j];
            if(abs(tmp - qz[k] * 2) <= abs(tmp - qz[k + 1] * 2))
                break;
        }

        int maxn = max({qz[i], qz[j] - qz[i], qz[k] - qz[j], qz[n] - qz[k]});
        int minn = min({qz[i], qz[j] - qz[i], qz[k] - qz[j], qz[n] - qz[k]});

        ans = min(ans, maxn - minn);
    }
    
    cout << ans << endl;
    
    return 0;
}
