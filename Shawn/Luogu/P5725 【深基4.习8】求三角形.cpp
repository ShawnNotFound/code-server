#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    //rectangle
    int rectot = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(++ rectot < 10)
                cout << 0 << rectot;
            else
                cout << rectot;
        }
        cout << endl;
    }

    cout << endl;

    //triangle
    int tritot = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n - i; j ++)
            cout << "  ";
        for(int j = 1; j <= i; j ++)
        {
            if(++ tritot < 10)
                cout << 0 << tritot;
            else
                cout << tritot;
        }
        cout << endl;
    }
}