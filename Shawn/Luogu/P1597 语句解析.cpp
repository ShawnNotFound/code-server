#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

#define mod %

using namespace std;

int a, b, c;
char s[500];

int main()
{
    cin.getline(s, 300);
    int ls = strlen(s) - 1;

    char tmpf, tmpt;
    for(int i = 0; i <= ls; i ++)
    {
        if((i + 1) mod 5 == 1)
            tmpf = s[i];
        if((i + 1) mod 5 == 4)
        {
            if(s[i] == 'a')
            {
                if(tmpf == 'b')
                    b = a;
                if(tmpf == 'c')
                    c = a;

                continue;
            }
            if(s[i] == 'b')
            {
                if(tmpf == 'a')
                    a = b;
                if(tmpf == 'c')
                    c = b;
                continue;
            }
            if(s[i] == 'c')
            {
                if(tmpf == 'a')
                    a = c;
                if(tmpf == 'b')
                    b = c;
                continue;
            }
            // cout << "debug here" << endl;
            if(tmpf == 'a')
            {
                // cout << "debug here" << endl;
                a = s[i] - '0';
            }
            if(tmpf == 'b')
                b = s[i] - '0';
            if(tmpf == 'c')
                c = s[i] - '0';
        }
    }

    cout << a << " " << b << " " << c << endl;

    return 0;
}