#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int s[50];
long long sum = 0;

int main()
{
    int n;
    while(cin >> s[++ n]);

    n --;
    // cout << "debug" << n << endl;

    for(int i = 1; i <= n; i ++)
        sum += s[i];
    
    cout << sum * (long long)pow(2, n - 1) << endl;

    return 0;
}