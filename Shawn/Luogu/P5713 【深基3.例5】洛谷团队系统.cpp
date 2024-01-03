#include<iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    if(5 * q < 11 + 3 * q)
        cout << "Local" << endl;
    else
        cout << "Luogu" << endl;

    return 0;
}