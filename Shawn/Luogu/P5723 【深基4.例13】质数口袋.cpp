#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int l;
int sum, cnt;

bool is_prime(int n)
{
    if(n == 2)
        return true;
    for(int i = 2; i * i <= n; i ++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> l;
    int i = 2;
    while(sum + i <= l)
    {
        if(is_prime(i))
        {
            sum += i;
            cout << i << endl;
            cnt ++;
        }
        i ++;
    }

    cout << cnt << endl;

    return 0;
}