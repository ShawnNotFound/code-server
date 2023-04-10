#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int x, y, xx, yy;
int dx, dy;

int main()
{
    cin >> x >> y >> xx >> yy;
    dx = x - xx; 
    dy = y - yy;
    if(dx % 2 == 0 && dy % 2 == 0)
    {
        cout << abs(dx) + abs(dy) << endl;
        return 0;
    }    
    else if((dx - 1) % 2 == 0 && (dy - 1) % 2 == 0)
    {
        if((dx + 1) % 2 == 0 && (dy + 1) % 2 == 0)
        {
            cout << min(abs(dx - 1) + abs(dy - 1), abs(dx + 1) + abs(dy + 1)) + 1 << endl;
            return 0;
        }
        else    
            cout << abs(dx - 1) + abs(dy - 1) + 1 << endl;
        return 0;
    }
    if((dx + 1) % 2 == 0 && (dy + 1) % 2 == 0)
    {
        cout << abs(dx + 1) + abs(dy + 1) + 1 << endl;
        return 0;
    }
    cout << "-1" << endl;
    return 0;
}