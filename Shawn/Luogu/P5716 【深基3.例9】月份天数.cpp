#include<iostream>

#define mod %

using namespace std;

int y, m;
int ans[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    cin >> y >> m;
    if((y mod 4 == 0 && y mod 100 != 0) || y mod 400 == 0)
        ans[2] = 29;

    cout << ans[m] << endl;

    return 0;
}