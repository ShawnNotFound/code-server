#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

#define mod %
#define int long long

const int N = 1 << 18 + 10;

using namespace std;

int f[N][110], a[30];
int cnt = -1, m, n;
bool vis[10];

int main()
{
    cin >> n >> m;
    while(n)
    {
        a[++ len] = n % 10;
        n /= 10;
    }
    f[0][0] = 1;
    for(int i = 1; i < 1 << cnt + 1; i ++)
    {
        memset(vis, false, sizeof(vis));
        
    }
}