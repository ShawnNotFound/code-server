#include<iostream>
#include<cmath>
const int N = 1e6 + 10;
using namespace std;

int a[N], b[N], ans[N];

int main()
{
    int a1, b1;
    cin >> a1 >> b1;
    for(int i = 0; i <= a1; i ++)
        cin >> a[i];
    for(int i = 0; i <= b1; i ++)
        cin >> b[i];
    
    for(int i = 0; i <= a1; i ++)
        for(int j = 0; j <= b1; j ++)
        {
            ans[i + j] += a[i] * b[j];
        }
    
    for(int i = 0; i <= a1 + b1; i ++)
        cout << ans[i] << " ";
    
    return 0;
}