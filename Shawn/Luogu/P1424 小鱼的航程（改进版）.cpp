#include<iostream>

const int N = 1e6 + 10;

using namespace std;

int daily[N];
int st, n, ans;

int main()
{
    cin >> st >> n;
    for(int i = 1; i <= n + 8; i ++)
    {
        if(i % 7 == 6 || i % 7 == 0)
            continue;
        daily[i] = 250;
    }

    for(int i = st; i <= st + n - 1; i ++)
    {
        // cout << daily[i] << endl;
        ans += daily[i];
    }

    cout << ans << endl;

    return 0;
}