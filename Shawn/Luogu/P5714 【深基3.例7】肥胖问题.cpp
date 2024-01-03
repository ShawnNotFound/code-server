#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double h, m;

int main()
{
    cin >> m >> h;
    double BMI = m / (h * h);
    if(BMI < 18.5)
        cout << "Underweight" << endl;
    else if(BMI < 24)
        cout << "Normal" << endl;
    else
    {
        cout << BMI << endl;
        cout << "Overweight" << endl;
    }

    return 0;
}