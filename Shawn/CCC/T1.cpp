#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int num[N];
int n;
int cnt;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> num[i];

    for(int i = 1; i <= n / 2; i ++)
    {
        if(num[i] == num[i + n / 2])
            cnt ++;
    }

    cout << cnt * 2 << endl;

    return 0;
}