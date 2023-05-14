#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 2e6;

using namespace std;

int T, tot;
int a[N], c[N];

int main()
{
    cin >> T;
    while(T --)
    {
        int ans = 1e9;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++)
            cin >> a[tot + i];
        for(int i = 1; i <= n; i ++)
            cin >> c[tot + i];
        
        if(c[tot + 1] == c[tot + n])
            ans = a[tot + 1] + a[tot + n];
        for(int i = 1; i <= n - 1; i ++)
        {
            if(c[tot + 1] == c[tot + i] && c[tot + i + 1] == c[tot + n])
                ans = min (ans, a[tot + 1] + a[tot + i] + a[tot + i + 1] + a[tot + n]);
        }

        cout << ans << endl;
        
        tot += n;
    }
    
}