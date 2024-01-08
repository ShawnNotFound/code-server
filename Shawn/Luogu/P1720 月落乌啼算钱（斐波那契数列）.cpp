#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

double calc(double k)
{
    return (pow((1 + sqrt(5)) / 2, k) - pow((1 - sqrt(5)) / 2, k)) / sqrt(5);
}

int main()
{
    int n;
    double ans = 0.0;
    cin >> n;
    // for(double i = 1; i < n + 1; i ++)
    // {
    //     cout << calc(i) << endl;
    //     ans += calc(i);
    // }

    cout << fixed << setprecision(2) << calc(n) << endl;

    return 0;
}