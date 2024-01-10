#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int n, num;
int tot;
bool flag;

int main()
{
    cin >> n;

    int nn = 1;
    while(1)
    {
        cin >> num;
        tot += num;

        nn = (nn + 1) % 2;
        for(int i = 1; i <= num; i ++)
        {
            if((tot - num + i - 1) % n == 0 && (tot - num + i - 1) / n != 0)
            { 
                cout << endl;
            }
            cout << nn;
        }
        if(tot == n * n)
            return 0;
    }
}