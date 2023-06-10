#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

#define mod %

using namespace std;

long long n, k;
long long ans;

int main()
{   
    cin >> n >> k;

    long long res = n / k;
    ans = res * res * res;

    if(k mod 2 == 0)
    {
        long long tmp = n + k / 2;
        long long a = tmp / k;

        if(tmp mod k == 0)
            ans += a * a * a;
        else
            ans += ((tmp - tmp mod k) / k) * ((tmp - tmp mod k) / k) * ((tmp - tmp mod k) / k);
        //     ans2 = (tmp / k) * (tmp / k) * (tmp / k);
        
        // else
        //     ans2 = ans1;
    }

    cout << ans << endl;

    return 0;
}