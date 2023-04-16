#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e5 + 10;

using namespace std;

int n, ans;
bool timeline[N];

struct blyy
{
    int m, t;
}c[N];

bool cmp(blyy a, blyy b)
{
    return a.m > b.m;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> c[i].m >> c[i].t;

    sort(c + 1, c + n + 1, cmp);

    for(int i = 1; i <= n; i ++)
    {
        bool flag = false;
        for(int j = 0; j < c[i].t; j ++)
        {
            if(!timeline[c[i].t - j])
            {
                timeline[c[i].t - j] = true;
                flag = true;
                break;
            }
        }
        if(flag)
            ans += c[i].m;
    }

    cout << ans << endl;

    return 0;
}
