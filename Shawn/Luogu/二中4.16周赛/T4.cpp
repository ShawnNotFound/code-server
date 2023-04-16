#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>

const int N = 1e5 + 10;

using namespace std;

int origin_map[N], map[N];
int n;
double mid, l, r;
double minn[N], maxn[N];

bool check()
{
    minn[1] = map[1] - mid * 1;

    for(int i = 2; i <= n; i ++)
        minn[i] = min(minn[i - 1], map[i] - mid * i);


    maxn[n - 1]=map[n - 1] - mid * (n - 1);

    for(int i = n - 2; i >= 1; i --)
        maxn[i] = max(maxn[i+1], map[i] - mid * i);


    for(int i = 2; i < n; i ++)
        if(maxn[i] - minn[i-1] > map[n] - mid * n)
            return false;

    return true;
}


int main()
{
    cin.tie(0);

    //read
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> origin_map[i];

    //前缀和
    for(int i = 1; i <= n; i ++)
        map[i] = map[i - 1] + origin_map[i];

    l = 0, r = 1e4 + 10;
    while(r - l > 1e-5)
    {
        mid = (l + r) / 2;
        if(check())
            l = mid;
        else
            r = mid;
        //cout << l << " " << r << " " << mid << endl;
    }

    cout << fixed << setprecision(3) << mid << endl;

    return 0;

}
