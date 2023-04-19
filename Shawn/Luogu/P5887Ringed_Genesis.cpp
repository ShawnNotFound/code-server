#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e6 + 10;

using namespace std;

int n, m, k, ans;
int start[N];
bool v[N];

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    cin >> n >> m >> k;
    
    int gcdn = gcd(n, k);

    for(int i = 1; i <= m; i ++)
    {
        cin >> start[i];
        v[start[i] % gcdn] = true;
    }

    for(int i = 0; i < gcdn; i ++) 
        if(!v[i])
            ans += n / gcdn;

    cout << ans << endl;

    return 0;
}