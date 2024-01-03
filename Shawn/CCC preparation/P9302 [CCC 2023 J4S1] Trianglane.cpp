#include<iostream>
#include<cstring>
#include<cmath>
#include<cstring>

#define mod %

const int N = 2e5 + 10;

using namespace std;

int main()
{
    bool black[N][3];
    memset(black, false, sizeof(black));
    int n;
    int ans = 0;

    cin >> n;
    for(int i = 1; i <= n; i ++)    
    {
        int tmp;
        cin >> tmp;
        black[i][1] = (tmp == 1);
        if(tmp == 1 && i % 2 == 0)
            ans ++; // top
    }
    for(int i = 1; i <= n; i ++)    
    {
        int tmp;
        cin >> tmp;
        black[i][2] = (tmp == 1);
        if(tmp == 1 && i mod 2 == 0)
            ans ++;
    }   

    for(int i = 1; i <= n; i ++)
    {
        // second
        if(black[i][1])
        {
            if(!black[i - 1][1])
                ans ++;
            if(!black[i + 1][1])
                ans ++;
        }

        if((i mod 2) && ((black[i][1] + black[i][2]) == 1))
            ans ++;

        if(black[i][2])
        {
            if(!black[i - 1][2])
                ans ++;
            if(!black[i + 1][2])
                ans ++;
        }
    }

    cout << ans << endl;

    return 0;
}