#include<iostream>
#include<cmath>
#include<algorithm>
const int N = 1e6 + 10;
using namespace std;

int a[N];

int main()
{
    int n, tt, tmp;
    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> tmp;
        while(tt && a[tt] >= tmp)
            tt --;
        if(!tt) cout << "-1 ";
        else cout << a[tt] << " ";
        a[++ tt] = tmp;
    }

    return 0;
    
}