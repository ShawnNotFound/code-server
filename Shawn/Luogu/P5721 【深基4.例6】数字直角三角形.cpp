#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int n, now;

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = n; j >= i; j --)
        {
            now ++;
            if(now < 10)
                cout << 0;
            cout << now;
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}