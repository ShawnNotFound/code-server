#include<iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    if(n == 0 || n == 1)
        cout << "Today, I ate " << n << " apple." << endl;
    else
        cout << "Today, I ate " << n <<" apples." << endl;

    return 0;
}