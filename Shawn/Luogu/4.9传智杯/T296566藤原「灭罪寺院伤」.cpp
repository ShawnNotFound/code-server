#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e6 + 10;

long long n, x, y, a[N], b[N], c[N], s;

int main()
{
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i] >> b[i];
        c[i] = i;
    }


    for(int i = n; i >= 2; i --)
    {
        if(x < a[i]) 
            s = s + a[i] - x;
        else if(x >= (a[i] + i))
            s = s + x - a[i] - i + 1;

        
        if(y > b[i]) 
            s = s + y - b[i];
        else if((b[i] - i) >= y)
            s = s + b[i] - i - y + 1;
    }

    s = s + abs(x - a[1]) + abs(y - b[1]);

    cout << s << endl;

    return 0;
}