#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

#define int long long

using namespace std;

int a, b;
int ten[20], f[20];
int cnta[20], cntb[20];

void work(int x, int *cnt)
{
    int num[20];
    memset(num, 0, sizeof(num));

    num[0] = 0;

    while(x)
    {
        num[++ num[0]] = x % 10;
        x /= 10;
    }
    for(int i = num[0]; i >= 1; i --)
    {
        for(int j = 0; j <= 9; j ++)
            cnt[j] += f[i - 1] * num[i];
        
        for(int j = 0; j < num[i]; j ++)
            cnt[j] += ten[i - 1];
        
        int num2 = 0;
        for(int j = i - 1; j >= 1; j --)
            num2 = num2 * 10 + num[j];

        cnt[num[i]] += num2 + 1;
        
        cnt[0] -= ten[i - 1];
    }
   
}

signed main()
{
    cin >> a >> b;

    ten[0] = 1;

    for(int i = 1; i <= 13; i ++)
    {
        f[i] = f[i - 1] * 10 + ten[i - 1];
        ten[i] = 10 * ten[i - 1];
    }

    work(a - 1, cnta);
    work(b, cntb);

    for(int i = 0; i <= 9; i ++)
        cout << cntb[i] - cnta[i] << " ";
    
    cout << endl;
    
    return 0;
}