#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

const int N = 1e6 + 10;

using namespace std;

int n, m;
int x[N], y[N];
int ansx = 1, ansy = 1;
long long l, r, z;
long long s;

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> z;

    for(int i = 1; i <= m; i ++)
    {
        long long xx, yy, qq;
        cin >> xx >> yy >> qq;

        l += (xx - 1);
        r += (yy - 1);
        s += qq;

        x[xx] ++;
        y[yy] ++;
    }

    long long lad = l, rad = r;

    for(int i = 2; i <= n; i ++)
    {
        x[i] += x[i - 1];
        y[i] += y[i - 1];
    }
    for(int i = 2; i <= n; i ++)
    {
        l += (x[i - 1] * 2 - m);
        if(l < lad)
        {
            ansx = i;
            lad = l;
        }
    }

    for(int i = 2; i <= n; i ++)
    {
        r += (y[i - 1] * 2 - m);
        if(r < rad)
        {
            ansy = i;
            rad = r;
        }
    }

    cout << s + lad + rad << endl;
    cout << ansx << " " << ansy << endl;

    return 0;
}

// 3 3 1
// 1 1 1
// 1 2 1
// 1 3 1