#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

int n;
int map[3000][3000];

void calc(int x, int y, int d)
{
    if(d == 0)
        return;

    for(int i = x; i <= x + d - 1; i ++)
        for(int j = y; j <= y + d - 1; j ++)
            map[i][j] = 0;

    calc(x + d, y, d / 2);
    calc(x, y + d, d / 2);
    calc(x + d, y + d, d / 2);
}

int main()
{
    cin >> n;

    int l = 1 << n;

    for(int i = 1; i <= l; i ++)
        for(int j = 1; j <= l; j ++)
            map[i][j] = 1;

    calc(1, 1, l / 2);

    for(int i = 1; i <= l; i ++)
    {
        for(int j = 1; j <= l; j ++)
            cout << map[i][j] << " ";
        cout << endl;
    }    

    return 0;
}