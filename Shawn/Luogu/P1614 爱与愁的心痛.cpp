#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 3e3 + 10;

using namespace std;

int n, m;
int a[N], s[N];
int minn = 2e9;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    // for(int i = 1; i <= n; i ++)
    //     cout << s[i] << " ";
    // cout << endl;

    for(int i = m; i <= n; i ++)
    {
        minn = min(minn, s[i] - s[i - m]);
    }

    cout << minn << endl;

    return 0;
}