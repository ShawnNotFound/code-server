#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e2 + 10;

using namespace std;

int f[N], map[N];
int maxn = 1, n;


int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        cin >> n;
        for(int i = 1; i <= n; i ++)
            cin >> map[i];
            
        
        for(int i = 1; i <= n; i ++)
        {
            f[i] = 1;
            for(int j = 1; j <= i; j ++)
            {
                if(map[i] < map[j])
                {
                    f[i] = max(f[i], f[j] + 1);
                    maxn = max(maxn, f[i]);
                }
            }
        }

        memset(f, 0 ,sizeof(f));
        for(int i = n; i >= 1; i --)
        {
            f[i] = 1;
            for(int j = n; j >= i; j --)
            {
                if(map[i] < map[j])
                {
                    f[i] = max(f[i], f[j] + 1);
                    maxn = max(maxn, f[i]);
                }
            }
        }
        
        cout << maxn << endl;
        maxn = 1;
    }

    return 0;
    
}