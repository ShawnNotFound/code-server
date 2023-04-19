#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 1e6;

using namespace std;

int T, n, k, tmp;
bool cj[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> T;
    
    while(T --)
    {
        cin >> n >> k;

        int ans = n;
        
        for(int i = 1; i <= n; i ++)
            cj[i] = true;
        
        for(int i = 1; i <= k; i ++)
        {
            cin >> tmp;
            cj[tmp] = false;
        }

        if(n == 1 && k == 1)
        {
            cout << -1 << endl;
            cj[1] = false;
            continue;
        }

        for(int i = 1; i <= n; i ++)
        {
            if(cj[i])
                ans = gcd(ans, i);
            //cout << "gcd(" << ans << ", " << i << ")" << endl;
        }
        //cout << ans << endl;
        if(ans <= 1)
            cout << n << endl;
        else
            cout << -1 << endl;

        for(int i = 1; i <= n; i ++)
            cj[i] = false;

    }

    return 0;
}