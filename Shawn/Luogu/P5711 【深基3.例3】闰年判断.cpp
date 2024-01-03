#include<iostream>

#define mod %

using namespace std;

int main()
{
    int n;
    cin >> n;   

    if((n mod 4 == 0 && n mod 100 != 0) || n mod 400 == 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;   
}