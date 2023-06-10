#include<iostream>
#include<cmath>

#define mod %

using namespace std;

int n;

int calc()
{
    int res = 0, tmp = n;
    
    while(tmp)
    {
        res += (tmp mod 10);
        
        tmp /= 10;
    }

    return res;
}

int main()
{
    cin >> n;

    int Sn = calc();

    //cout << Sn << " " << n << endl;
    if(n mod Sn)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}