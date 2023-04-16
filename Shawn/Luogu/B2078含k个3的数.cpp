#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

char num[20];
int k;
int cnt;

int main()
{
    cin >> num + 1 >> k;
    
    for(int i = 1; i <= 20; i ++)
        if(num[i] == '3')
            cnt ++;
    

    if(cnt == k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}