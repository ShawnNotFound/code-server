#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define int long long

const int N = 1e6 + 10;

using namespace std;

int Ans, n, k;
int q[N], a[N], up[N], far[N];

signed main()
{
    cin >> n >> k;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    int head = 0;
    int tail = 0;

    for(int i = 1; i <= k; i ++)
    {
        while(head <= tail && a[q[tail]] >= a[i])
            tail --;
        q[++ tail] = i;
    } 

    for(int i = k; i <= n; i ++)
    {
        while(head <= tail && a[q[tail]] >= a[i])
            tail --;
        q[++ tail] = i;
        while(head <= tail && q[head] < i - k + 1)
            head ++;
        up[i - k + 1] = a[q[head]];
    }

    head = 0;
    tail = 0;
    for(int i = 1; i <= n; i ++)
    {
        while(head <= tail && up[q[tail]] <= up[i])
            tail --;
        q[++ tail] = i;

        if(i >= k)
            while(head <= tail && q[head] < i - k + 1)
                head ++;
        
        far[i] = up[q[head]];
        Ans += (a[i] - far[i]);
    }

    cout << Ans << endl;

    Ans = 0;

    int Up = 0, right = 0;
    for(int i = 1; i <= n; i ++)
        if(far[i] ^ Up || right < i)
        {
            Ans ++;
            Up = far[i];
            right = i + k - 1;
        }

    cout << Ans << endl;

    return 0;
}