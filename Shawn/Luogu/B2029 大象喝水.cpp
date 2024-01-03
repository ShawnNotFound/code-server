#include<iostream>
#include<cmath>

using namespace std;

int h, r;

double calc()
{
    return (double)3.14 * r * r * h / 1000;
}


int main()
{
    cin >> h >> r;
    
    cout << ceil(20.0 / calc()) << endl;

    return 0;
}