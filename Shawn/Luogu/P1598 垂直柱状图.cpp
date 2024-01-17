#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>

#define mod %

using namespace std;

int times[500], num[500];
char wd[200];
int maxn = -1;

int main()
{
    for(int i = 1; i <= 4; i ++)
    {
        memset(wd, 0, sizeof(wd));
        cin.getline(wd, 150);
        int lwd = strlen(wd) - 1;

        for(int j = 0; j <= lwd; j ++)
        {
            times[(int)wd[j]] ++;
        }
    }

    for(int i = 'A'; i <= 'Z'; i ++)
    {
        maxn = max(times[i], maxn);
        for(int j = 1; j <= times[i]; j ++)
        {
            num[j] ++;
        }
    }

    // for(int i = 'A'; i <= 'Z'; i ++)
    //     cout << times[(int)i] << " ";
    // cout << endl;

    // for(int i = 1; i <= maxn; i ++)
    //     cout << num[i] << " ";
    // cout << endl;

    for(int i = maxn; i >= 1; i --)
    {
        int t = 0;
        for(int j = 3; j <= 100; j ++)
        {
            // cout << "debug times:" << times['A' + j / 2 - 1] << " " << i << endl;
            if(times['A' + j / 2 - 1] >= i)
            {
                // cout << "here" << i << " " << j << endl;
                if(j mod 2 == 0)
                    cout << " ";
                else
                {
                    cout << "*";
                    t ++;
                    if(t == num[i])
                    {
                        cout << endl;
                        break;
                    }
                }
            }
            else
                cout << " ";
        }
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

    return 0;
}