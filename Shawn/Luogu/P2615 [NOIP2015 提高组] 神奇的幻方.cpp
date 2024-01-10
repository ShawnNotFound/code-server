#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int px, py;
int a[50][50];

int main()
{
    memset(a, -1, sizeof(a));
    cin >> n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            a[i][j] = 0;

    for(int i = 1; i <= n * n; i ++)
    {
        if(i == 1)
        {
            a[1][n / 2 + 1] = 1;
            px = 1;
            py = n / 2 + 1;
        }
        else if(px == 1 && py != n)
        {
            px = n;
            py ++;
            a[px][py] = i;
        }
        else if(py == n && px != 1)
        {
            py = 1;
            px --;
            a[px][py] = i;
        }
        else if(px == 1 && py == n)
        {
            px ++;
            a[px][py] = i; 
        }
        else if(a[px - 1][py + 1] == 0)
        {
            px --;
            py ++;
            a[px][py] = i;
        }
        else
        {
            // cout << px << " " << py << endl;
            px ++;
            a[px][py] = i;
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}