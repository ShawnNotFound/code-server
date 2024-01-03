#include<iostream>

using namespace std;

int main()
{
    int n; 
    cin >> n;

    int ans = (n % 2 == 0) + (n > 4 && n <= 12);
    
    cout << (ans == 2) << " " << (ans >= 1) << " " << (ans == 1) << " " << (ans == 0) << endl;

    return 0;
}