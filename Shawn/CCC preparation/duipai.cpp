#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int ans;

int main()
{
    int m, n;
    for(int i = 1; i <= n; i ++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ans += d;
    }    

    cout << ans << endl;

    return 0;
}