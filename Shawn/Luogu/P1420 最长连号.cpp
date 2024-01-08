#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
long long cnt = 1, ans = 1, pre = 1e9 + 10, now;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> now;
        if(now == pre + 1)
        {
            cnt ++;
            ans = max(ans, cnt);
            pre = now;
            continue;
        }
        pre = now;
        cnt = 1;
    }

    cout << ans << endl;

    return 0;
}