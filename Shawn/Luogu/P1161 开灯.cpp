#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int n;
double a;
int t;
bool map[2000010];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a >> t;
        for(int j = 1; j <= t; j ++)
        {
            int tmp = a * j;
            map[tmp] = !map[tmp];
        }
    }

    for(int i = 1; 1; i ++)
    {
        if(map[i])
        {
            cout << i << endl;

            return 0;
        }
    }
}