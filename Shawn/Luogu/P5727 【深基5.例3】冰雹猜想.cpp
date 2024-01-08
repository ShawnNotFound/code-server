#include<iostream>
#include<cmath>
#include<algorithm>

const int N = 1e5 + 10;

using namespace std;

int a[N], ans[N];

int main()
{
    int i;

    cin >> a[1];
    
    for(i = 2; a[i - 1] != 1; i ++)
    {
        // cout << a[i] << endl;
        if(a[i - 1] % 2)
            a[i] = a[i - 1] * 3 + 1;
        else
            a[i] = a[i - 1] / 2;
    }
    
    for(int j = i - 1; j >= 1; j --)
        cout << a[j] << " ";

    cout << endl;

    return 0; 
}   