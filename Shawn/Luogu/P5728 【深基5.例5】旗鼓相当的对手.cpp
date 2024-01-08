#include<iostream>
#include<cstring>

int a[1010][10];

using namespace std;

int n, cnt;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i][2] >> a[i][3] >> a[i][4];
        a[i][1] = a[i][2] + a[i][3] + a[i][4];
    }
    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; j <= n; j ++)
        {
            if((abs(a[i][1] - a[j][1]) <= 10) && (abs(a[i][2] - a[j][2]) <= 5) && (abs(a[i][3] - a[j][3]) <= 5) && (abs(a[i][4] - a[j][4]) <= 5))
            {
                cnt ++;
                // cout << i << " " << j << endl;
            }
        }
    
    cout << cnt << endl;

    return 0;
}