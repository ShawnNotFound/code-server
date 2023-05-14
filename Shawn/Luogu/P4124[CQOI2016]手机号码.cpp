#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>


using namespace std;

long long num[15], f[15][15][15][2][2][2][2];
long long l, r;

long long dp(long long p, long long first, long long second, long long same, long long pre, long long four, long long eight)
{
    if(four and eight)
        return 0;
    
    if(p <= 0)
        return same;
    
    if(~ f[p][first][second][same][pre][four][eight])   
        return f[p][first][second][same][pre][four][eight];
    
    long long res = 0, limit;
    if(pre)
        limit = 9;
    else
        limit = num[p];

    for(long long i = 0; i <= limit; i ++)
        res += dp(p - 1, i, first, same || ( i == first and i == second), pre || (i < limit), four || (i == 4), eight || (i == 8));

    f[p][first][second][same][pre][four][eight] = res;

    return res;
}

long long solve(long long x)
{
    if(x < 1e10)    
        return 0;
    memset(f, -1, sizeof(f));

    long long len = 0; 

    while(x)
    {
        num[++ len] = x % 10;
        x /= 10;
    }
    
    // for(len=0;x;x/=10) num[++len]=x%10;
    
    long long res = 0;
    for(long long i = 1; i <= num[len]; i ++)
        res += dp(10, i, 0, 0, i < num[len], i == 4, i == 8);

    return res;

}

signed main()
{
    cin >> l >> r;

    cout << solve(r) - solve(l - 1) << endl;

    return 0;
}