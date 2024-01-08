#include<iostream>

using namespace std;

double dis, stlength = 2, tot;
long long step;

int main()
{
    cin >> dis;
    for(; tot < dis; step ++)
    {
        tot += stlength;
        stlength *= 0.98;
        // cout << tot << " " << stlength << endl;
    }

    cout << step << endl;

    return 0;
}
