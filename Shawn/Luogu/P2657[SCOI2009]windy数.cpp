#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long

using namespace std;

int f[20][20], a[20];
int ans, len, l, r;

int dp(int pos, int pre, int st, int limit)
{
    if(pos > len)
        return 1;
    
    if(!limit && f[pos][pre] != -1)
        return f[pos][pre];
    
    int result = 0, res;

    if(limit)
        res = a[len - pos + 1];
    else
        res = 9;
    
    for(int i = 0; i <= res; i ++)
    {
        if(abs(i - pre) < 2)
            continue;
        if(st && i == 0)
            result += dp(pos + 1, -2, 1, limit and i == res);
        else
            result += dp(pos + 1, i, 0, limit and i == res);
    }

    if(!limit and !st)
        f[pos][pre] = result;
    
    return result;
        
}

int solve(int x)
{
    len = 0;
    while(x)
    {
        a[++ len] = x % 10;
        x /= 10;
    }

    memset(f, -1, sizeof(f));

    return dp(1, -2, 1, 1);
}

signed main()
{
    cin >> l >> r;

    cout << solve(r) - solve(l - 1) << endl;

    return 0;
}

