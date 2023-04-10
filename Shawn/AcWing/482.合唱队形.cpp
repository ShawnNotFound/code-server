#include<iostream>
#include<cmath>
#include<cstring>

const int N = 1e3 + 10;

using namespace std;

int f[N][2], map[N];
int n, maxn;

//1 1 1 2 3 1 3 4
//1 1 2 1 2 3 2 1

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
    
    //init();
    for(int i = 1; i <= n; i ++)
    {
        f[i][0] = 1;
        for(int j = 1; j <= i - 1; j ++)
        {
            if(map[i] > map[j])
            {
                f[i][0] = max(f[i][0], f[j][0] + 1);
            }
        }
    }

    // for(int i = 1; i <= n; i ++)
    //     cout << f[i][0] << " ";
    // cout << endl;
    
    //init();
    // for(int i = 1; i <= n; i ++)
    // {
    //     f[i][1] = 1;
    //     for(int j = 1; j <= i - 1; j ++)
    //     {
    //         if(map[i] < map[j])
    //         {
    //             f[i][1] = max(f[i][1], f[j][1] + 1);
    //         }
    //     }
    // }
    
    for(int i = n; i >= 1; i --)
    {
        f[i][1] = 1;
        for(int j = n; j >= i; j --)
        {
            if(map[i] > map[j])
            {
                f[i][1] = max(f[i][1], f[j][1] + 1);
            }
        }
    }
    
    for(int i = 1; i <= n; i ++)
        maxn = max(maxn, f[i][0] + f[i][1]);

    
    // for(int i = 1; i <= n; i ++)
    //     cout << f[i][1] << " ";
    // cout << endl;

    cout << n - (maxn - 1) << endl;
    
    return 0;
}