#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

const int M = 2e5 + 10;
const int N = 5e2 + 10;

using namespace std;

int n, m, q;
int l[M], r[M], f[N][N];

int main()
{
    cin >> n >> m >> q;

    for(int i = 1; i <= m; i ++)
    {
        cin >> l[i] >> r[i];
        f[l[i]][r[i]] ++;
    }

    for(int i = n; i >= 1; i --)
        for(int j = 1; j <= n; j ++)
            f[i][j] = f[i][j] + f[i][j - 1] + f[i + 1][j] - f[i + 1][j - 1];

    while(q --)
    {
        int ll, rr;
        cin >> ll >> rr;
        cout << f[ll][rr] << endl;
    }

    return 0;

}