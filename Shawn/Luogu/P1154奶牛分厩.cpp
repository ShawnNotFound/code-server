#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

const int N = 1e6 + 10;

using namespace std;

int n;
int cow[N];
bool v[N];

int main()
{
    //read
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> cow[i];

    //solve
    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; j <= n; j ++)
            v[abs(cow[i] - cow[j])] = true;
    
    for(int i = n;i < N; i ++)
    {
        if(!v[i])
        {
            int f = 1;
            for(int j = i;j < N; j += i)
                if(v[j])
                {
                    f=0;
                    break;
                }

            if(f)
            {
                cout << i << endl;
                return 0;
            }
        }
    }
}