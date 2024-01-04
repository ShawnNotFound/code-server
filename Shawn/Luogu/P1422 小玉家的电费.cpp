#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

int n;

int main()
{
    cin >> n;
    if(n <= 150)
        cout << fixed << setprecision(1) << (double)n * 0.4463 << endl;
    
    else if (n <= 400)
        cout << fixed << setprecision(1) << (double)(150 * 0.4463 + (n - 150) * 0.4663) << endl;
    else
        cout << fixed << setprecision(1) << (double)(150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663) << endl;

    return 0;
}