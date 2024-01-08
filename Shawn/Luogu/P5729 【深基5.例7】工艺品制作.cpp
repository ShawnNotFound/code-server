#include<iostream>
#include<cmath>

using namespace std;

int x, y, z;
bool cube[25][25][25];
int q;

int main()
{
    cin >> x >> y >> z;
    for(int i = 1; i <= x; i ++)
        for(int j = 1; j <= y; j ++)
            for(int k = 1; k <= z; k ++)
                cube[i][j][k] = true;
    
    cin >> q;
    for(int l = 1; l <= q; l ++)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        for(int i = x1; i <= x2; i ++)
            for(int j = y1; j <= y2; j ++)
                for(int k = z1; k <= z2; k ++)
                    cube[i][j][k] = false;
    }

    int ans = 0;
    for(int i = 1; i <= x; i ++)
        for(int j = 1; j <= y; j ++)
            for(int k = 1; k <= z; k ++)
                if(cube[i][j][k])
                    ans ++;

    cout << ans << endl;

    return 0;
}