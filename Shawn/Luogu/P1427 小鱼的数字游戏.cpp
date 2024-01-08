#include<iostream>
#include<cstring>

using namespace std;

long long n;
long long a[110];

int main()
{
    for(int i = 1; 1; i ++)
    {
        long long tmp;
        cin >> tmp;
        if(tmp == 0)
        {
            n = -- i;
            break;
        }
        a[i] = tmp;
    }

    for(int i = n; i >= 1; i --)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}