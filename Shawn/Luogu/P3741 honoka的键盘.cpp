#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

bool c[300];
char s[300];
char pre, test[30];
int ls, cnt;

int main()
{
    cin.getline(test, 10);

    cin.getline(s, 200);
    ls = strlen(s) - 1;

    pre = s[0];

    for(int i = 1; i <= ls; i ++)
    {
        // cout << pre << " " << s[i] << endl;
        if(pre == 'V' && s[i] == 'K')
        {
            // cout << "debug here" << endl;
            cnt ++;
            c[i - 1] = true;
            c[i] = true;
        }
        pre = s[i];
    }

    pre = s[0];
    for(int i = 1; i <= ls; i ++)
    {
        if(pre == 'V' && c[i - 1] == false && s[i] == 'V' && c[i] == false)
        {
            cnt ++;
            break;
        }
        if(pre == 'K' && c[i - 1] == false && s[i] == 'K' && c[i] == false)
        {
            cnt ++;
            break;
        }
        pre = s[i];
    }

    cout << cnt << endl;

    return 0;
}