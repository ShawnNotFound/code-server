#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

char num[10];
int ans[20];
int a, b;

int main()
{
    cin >> a >> b;

    for(int i = a; i <= b; i ++)
    {
        int t = i;
        for(int j = 0; 1; j ++)
        {
            if(t == 0)
            {
                t = j;
                break;
            }
            t /= 10;
        }
        int tmp = i;
        for(int j = 1; j <= t; j ++)
        {
            num[t - j + 1] = tmp % 10;
            tmp /= 10;
        }

        for(int j = 1; j <= t; j ++)
        {
            ans[num[j]] ++;
        }
    }
    for(int i = 0; i <= 9; i ++)
        cout << ans[i] << " ";

    return 0;
}