#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e3 + 10;

using namespace std;

int d, g, sum;
int f[N], num[N], ex[N];

void calc(int i, int j, int k)
{
    int tmp;
    tmp = f[j - k] + k * i * 100;
    if(k == num[i])   
        tmp += ex[i];

    f[j] = max(f[j], tmp);
    
    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> d >> g;
    for (int i = 1; i <= d; i ++)
    {
        cin >> num[i] >> ex[i];
        sum += num[i];
    }    

    
    for (int i = 1; i <= d; i ++)
        for (int j = sum; j >= 1; j --) 
            for (int k = min(j, num[i]); k >= 1; k --)
                calc(i, j, k);
    
    // for(int i = 1; i <= d; i ++)
    //     cout << f[i] << " ";
    // cout << endl;

    for (int i = 1; i <= sum; i ++) 
    {
        if (f[i] >= g) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
