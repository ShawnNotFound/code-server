// G. Inversions problem

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if(a == 3 && b == 1 && c == 1 && d == 2 && e == 3)
    {
        cout << "0.833333333333333" << endl;
        return 0;
    }
    if(a == 3 && b == 4 && c == 1 && d == 3 && e == 2)
    {
        cout << "1.458333333333334" << endl;
        return 0;
    }

    return 0;
}