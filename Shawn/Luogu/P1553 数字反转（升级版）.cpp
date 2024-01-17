#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int cnt = 0;
char s[50], tmp[50], ans[50];

void flip(int from, int to)
{
    for(int i = 0; i <= to - from; i ++)
    {
        tmp[i] = s[from + i];
    }
    int ed = to - from;
    bool flag = false;
    for(int i = ed; i >= 0; i --)
    {
        // cout << "debug: " << (tmp[i] == 0) << " " << (flag == false) << endl;
        if((tmp[i] == '0') && (flag == false))
        {
            // cout << "here" << endl;
            s[to - i] = 'f';
            continue;
        }
        flag = true;
        s[to - i] = tmp[i];
    }
}
void flip_reverse(int from, int to)
{
    for(int i = 0; i <= to - from; i ++)
    {
        tmp[i] = s[from + i];
    }
    int ed = to - from;
    bool flag = false;
    for(int i = 0; i <= ed; i ++)
    {
        // cout << "debug: " << (tmp[i] == 0) << " " << (flag == false) << endl;
        if((tmp[i] == '0') && (flag == false))
        {
            // cout << "here" << endl;
            s[to - i] = 'f';
            continue;
        }
        flag = true;
        s[to - i] = tmp[i];
    }

    bool have_num = false;
    for(int i = 0; i <= ed; i ++)
    {
        if(s[to - i] != 'f')
            have_num = true;
    }
    if(!have_num)
        s[to] = '0';
}

int main()
{
    cin.getline(s, 30);
    int ls = strlen(s) - 1;

    int type = 1;
    for(int i = 0; i <= ls; i ++)
    {
        if(s[i] == '.')
        {
            type = 2;
            flip(0, i - 1);
            flip_reverse(i + 1, ls);
        }
        if(s[i] == '/')
        {
            type = 3;
            flip(0, i - 1);
            flip(i + 1, ls);
        }
        if(s[i] == '%')
        {
            type = 4;
            flip(0, ls - 1);
        }
    }

    if(type == 1)
    {
        flip(0, ls);
    }

    // if(type == 2)
    // {
    //     for(int i = 0; i <= ls; i ++)
    // }
    for(int i = 0; i <= ls; i ++)
    {
        if(s[i] == 'f')
            continue;
        if(cnt == 0 && (s[i] == '/' || s[i] == '.' || s[i] == '%'))
            cout << 0;
        cnt ++;
        cout << s[i];
    }
    if(cnt == 0 && type == 1)
        cout << 0;

    // for(int i = 0; i <= ls; i ++)
    // {
    //     if(s[ls - i] != 'f')
    //         break;
    //     if(s[ls - i] == '.')
    //     {
    //         cout << 0;
    //         break;
    //     }
    // }

    cout << endl;

    return 0;
}