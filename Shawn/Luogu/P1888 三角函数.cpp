#include<iostream>
#include<algorithm>
#include<cstring>

#define mod %

using namespace std;

int n[10];
int a, b, c;
int sin;

int gcd(int x, int y)
{
    return y ? gcd(y, x mod y) : x;
}

int main()
{
    cin >> n[1] >> n[2] >> n[3];
    sort(n + 1, n + 4);
    a = n[1], b = n[2], c = n[3];

    int g = gcd(a, c);
    cout << a / g << "/" << c / g << endl;

    return 0;
}