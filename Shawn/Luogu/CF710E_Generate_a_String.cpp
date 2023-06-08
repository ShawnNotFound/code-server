#include<iostream>

#define int long long 
#define mod %

const int N = 1e7 + 10;

using namespace std;

int n;
int x, y;
int f[N];

signed main()
{
    cin >> n >> x >> y;
    f[0] = 0;

    for(int i = 1; i <= n; i ++)
    {
        if(!(i mod 2))
            f[i] = min(f[i - 1] + x, f[i / 2] + y);
        else
            f[i] = min(f[i - 1] + x, f[(i + 1) / 2] + x + y);
    }

    cout << f[n];

    return 0;
}