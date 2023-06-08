#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 1e7 + 1e6 + 10;

using namespace std;

int mr = 0, mid;
int n, ans, cnt = 1;
int hwc[N << 1], l[N << 1], r[N << 1];
char a[N], s[N << 1];
    


int main()
{
    cin >> a + 1; 
    n = strlen(a + 1);

    s[0] = '#';
    s[1] = '$';
    
    for(int i = 1; i <= n; i ++)
    {
        s[++ cnt] = a[i];
        s[++ cnt] = '$';
    }

    n = (n << 1) + 2;
    s[n] = '~';

    for(int i = 1; i <= n; i ++)
    {
        if(i < mr)
            hwc[i] = min(hwc[(mid << 1) - i], mr - i);
        else
            hwc[i] = 1;
        
        while(s[i + hwc[i]] == s[i - hwc[i]])
            ++ hwc[i];
        
        if(hwc[i] + i > mr)
        {
            mr = hwc[i] + i;
            mid = i;
        }

        r[i + hwc[i] - 1] = max(r[i + hwc[i] - 1], hwc[i] - 1);
        l[i - hwc[i] + 1] = max(l[i - hwc[i] + 1], hwc[i] - 1);
    }

    for(int i = n; i >= 1; i -= 2)
        r[i] = max(r[i], r[i + 2] - 2);
    
    for(int i = 1; i <= n; i += 2)
        if(i - 2 >= 0)
            l[i] = max(l[i], l[i - 2] - 2);

    for(int i = 1; i <= n; i += 2)
        if(r[i] && l[i])
            ans = max(ans, l[i] + r[i]);

    cout << ans << endl;

    return 0;
}