#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n[5];
    cin >> n[1] >> n[2] >> n[3];

    sort(n + 1, n + 4);

    int a = n[1], b = n[2], c = n[3];

    if(c >= a + b)
    {
        cout << "Not triangle" << endl;
        return 0;
    }

    int m = c * c  - b * b - a * a;
    if(m == 0)
        cout << "Right triangle" << endl;
    if(m > 0)
        cout << "Obtuse triangle" << endl;
    if(m < 0)
        cout << "Acute triangle" << endl;
    if(a == b || b == c)
        cout << "Isosceles triangle" << endl;
    if(a == c)
        cout << "Equilateral triangle" << endl;

    return 0;
}