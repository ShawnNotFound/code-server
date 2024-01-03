#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n[5];
    cin >> n[0] >> n[1] >> n[2];
    sort(n, n + 3);
    for(int i = 0; i < 3; i ++)
        cout << n[i] << " ";

    return 0;
}