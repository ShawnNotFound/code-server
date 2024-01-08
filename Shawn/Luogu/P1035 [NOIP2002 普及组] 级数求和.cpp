#include<iostream>
#include<cmath>

using namespace std;

int n;
double sum = 1;
int cnt = 1;

int main()
{
    cin >> n;

    while(sum <= n)
    {
        sum += (double) 1 / (cnt + 1);
        cnt ++;
    }

    cout << cnt << endl;
}