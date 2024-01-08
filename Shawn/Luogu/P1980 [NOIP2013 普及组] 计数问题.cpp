#include<iostream>
#include<cmath>

using namespace std;

int n, x, ans;

int check(int cur)
{
    int res = 0;
    while(cur)
    {
        int num = cur % 10;
        cur /= 10;
        if(num == x)    
            res ++;
    }
    return res;
}

int main()
{
    cin >> n >> x;

    for(int i = 1; i <= n; i ++)
    {
        ans += check(i);
    }

    cout << ans << endl;

    return 0;
}