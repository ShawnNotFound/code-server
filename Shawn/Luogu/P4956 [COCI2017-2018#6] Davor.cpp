// x = 1092k + 364x

#include<iostream>
#include<cmath>
#include<algorithm>

#define mod %

using namespace std;

int x, k, n;

int main()
{
    cin >> n;
    for(x = 100; ((n - 364 * x) mod 1092) || ((n - 364 * x) / 1092 < 1); x --)
    {
        if(x * 364 > n)
            continue;
    }

    k = (n - 364 * x) / 1092;

    cout << x << endl << k << endl;

    return 0;
}