#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e3 + 10;

struct AcWing
{
    int sum;
    int n;
}f[N];

using namespace std;

int n, map[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> map[i];

    f[1].sum = map[1];

    for(int i = 1; i <= n; i ++)
    {
        f[i].n = 1;
        for(int j = i; j >= 1; j --)
        {
            f[i].sum = max(map[i], f[i].sum);
            
            if(map[i] > map[j])
            {
                if(f[i].n < f[j].n + 1)
                {
                    f[i].n = f[j].n + 1;
                    f[i].sum = f[j].sum + map[i];
                }
                else
                {
                    f[i].sum = max(f[i].sum, f[j].sum + map[i]);
                }
            }
        }
    }

    // for(int i = 1; i <= n; i ++)
    //     cout << f[i].n << " ";
    // cout << endl;
    
    // for(int i = 1; i <= n; i ++)
    //     cout << f[i].sum << " ";
    // cout << endl;


    int maxn = -0x3f;
    for(int i = 1; i <= n; i ++)
        maxn = max(maxn, f[i].sum);
    
    cout << maxn << endl;

    return 0;
}