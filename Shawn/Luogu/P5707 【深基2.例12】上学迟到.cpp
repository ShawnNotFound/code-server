#include<iostream>
#include<cmath>

using namespace std;

int s, v, t;

int main()
{
    cin >> s >> v;
    t = ceil((double)s / v);
    t += 10;

    int h = 24 + 7 - t / 60;
    int m = 60 - t % 60;

    if(h % 24 < 10)
        cout << "0";
    cout << h % 24 << ":";
    if(m < 10)
        cout << "0";
    cout << m << endl;

    return 0;
}