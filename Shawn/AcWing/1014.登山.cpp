#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
const int N = 1e3 + 10;
using namespace std;

int f[N][2],map[N], n, maxn = 1; //f[i][0]表示还在上山，f[i][1]表示正在下山
bool id[N];

void init()
{
    for(int i = 1; i <= n; i ++)
    {
        f[i][0] = 1;
        f[i][1] = 1;
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> map[i];
    
    init();
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= i; j ++)
        {
            if(map[i] > map[j])
            {
                f[i][0] = max(f[i][0], f[j][0] + 1);
            }
        }

    for(int i = n; i >= 1; i --)
        for(int j = n; j >= i; j --)
        {
            if(map[i] > map[j])
            {
                f[i][1] = max(f[i][1], f[j][1] + 1);
            }
        }
    
    // for(int i = 1; i <= n; i ++)
    //     cout << f[i][0] << " ";
    // cout << endl;
    // for(int i = 1; i <= n; i ++)
    //     cout << f[i][1] << " ";
    // cout << endl;
    
    for(int i = 1; i <= n; i ++)
        maxn = max(f[i][0] + f[i][1], maxn);

    cout << maxn - 1 << endl;

    return 0;
}