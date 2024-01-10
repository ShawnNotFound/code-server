#include<iostream>
#include<cstring>

using namespace std;

int n;
int num[110];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> num[i];

    bool flag;
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        flag = false;
        for(int j = 1; j <= n; j ++)
        {
            for(int k = j + 1; k <= n; k ++)
            {
                // if(j == k)
                //     continue;
                if(num[j] + num[k] == num[i])
                {
                    flag = true;
                    cnt ++;
                    break;
                }
            }
            if(flag)
                break;
        }
    }

    cout << cnt << endl;

    return 0;
}