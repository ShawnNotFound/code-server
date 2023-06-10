#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 110;

using namespace std;

int tot = 1;
int n, m;
char map[N][N];
bool f[N];

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
    {
        bool flag = false;
        char tmp[N];
        cin >> tmp + 1;
        for(int j = 1; j <= m; j ++)
        {
            if(tmp[j] == '#')
                flag = true;
        }
        if(flag)
        {
            tot ++;
            for(int j = 1; j <= m; j ++)
                map[tot][j] = tmp[j];
        }
    }

    for(int j = 1; j <= m; j ++)
    {
        bool flag = false;
        for(int i = 1; i <= tot; i ++)
        {
            if(map[i][j] == '#')
                flag = true;
        }
        if(!flag)
            f[j] = true;
    }

    for(int i = 2; i <= tot; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(!f[j])
                cout << map[i][j];
        }
        cout << endl;
    }
}