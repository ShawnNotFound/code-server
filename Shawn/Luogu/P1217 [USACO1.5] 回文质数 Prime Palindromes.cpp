#include<iostream>
#include<cmath>
#include<algorithm>

#define mod %

const int N = 1e5;

using namespace std;

long long pal[N], ans[N], tot = 11, tt;

void init()
{
    int cp[20] = {0, 5, 7, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    for(int i = 1; cp[i]; i ++)
        pal[i] = cp[i];

    //3 digit
    for(int i = 1; i <= 9; i += 2)
        for(int j = 0; j <= 9; j ++)
            pal[++ tot] = i * 100 + j * 10 + i;
    
    // 4 digits
    for(int i = 1; i <= 9; i += 2)
        for(int j = 0; j <= 9; j ++)
            pal[++ tot] = i * 1000 + j * 100 + j * 10 + i;

    // 5 digits
    for(int i = 1; i <= 9; i += 2)
        for(int j = 0; j <= 9; j ++)
            for(int k = 0; k <= 9; k ++)
                pal[++ tot] = i * 10001 + j * 1010 + k * 100;

    // 6 digits
    for(int i = 1; i <= 9; i += 2)
        for(int j = 0; j <= 9; j ++)
            for(int k = 0; k <= 9; k ++)
                pal[++ tot] = i * 100001 + j * 10010 + k * 1100;
    
    // 7 digits
    for(int i = 1; i <= 9; i += 2)
        for(int j = 0; j <= 9; j ++)
            for(int k = 0; k <= 9; k ++)
                for(int l = 0; l <= 9; l ++)
                    pal[++ tot] = i * 1000001 + j * 100010 + k * 10100 + l * 1000;
                
    // 8 digits
    for(int i = 1; i <= 9; i += 2)
        for(int j = 0; j <= 9; j ++)
            for(int k = 0; k <= 9; k ++)
                for(int l = 0; l <= 9; l ++)
                    pal[++ tot] = i * 10000001 + j * 1000010 + k * 100100 + l * 11000;

}

bool is_prime(int n)
{
    for(int i = 2; i * i <= n; i ++)
    {
        if(n mod i == 0)
            return false;
    }

    return true;
}

int main()
{
    init();

    for(int i = 1; pal[i]; i ++)
    {
        if(is_prime(pal[i]))
            ans[++ tt] = pal[i];
    }

    // for(int i = 1; i <= tot; i ++)
    //     cout << pal[i] << endl;


    // cout << tot << " " << tt << endl;

    int a, b;

    cin >> a >> b;

    for(int i = 1; i <= tt; i ++)
    {
        if(ans[i] >= a && ans[i] <= b)
            cout << ans[i] << endl;
    }

    return 0;
}