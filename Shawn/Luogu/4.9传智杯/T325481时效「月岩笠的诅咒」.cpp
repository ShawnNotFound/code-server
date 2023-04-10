#include<iostream>
#include<cstring>
#include<algorithm>

const int N = 50;

using namespace std;

char a[N], b[N];

int main()
{
    cin >> a >> b;
    //cout << strlen(a) << " " << strlen(b) << endl;
    reverse(a, a + strlen(a));
    reverse(b, b + strlen(b));

    for(int i = 0; i <= 11; i++)
    {
        //cout << a[i] << " " << b[i] << endl;
        if(a[i] != b[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}