#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int ans, n;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        int tmp;
        cin >> tmp;

        ans = gcd(ans, abs(tmp));
    }

    cout << ans;
}