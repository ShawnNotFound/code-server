#include<iostream>
#include<cstring>

using namespace std;

int cntb, cntg, lm;
char map[300];

int main()
{
    cin.getline(map, 275);
    lm = strlen(map) - 1;

    for(int i = 0; i <= lm; i ++)
    {
        if(map[i] == 'b')
        {
            cntb ++;
            if(map[i + 1] == 'o')
                map[i + 1] = '.';
            if(map[i + 2] == 'y')
                map[i + 2] = '.';
        }
        if(map[i] == 'o')
        {
            cntb ++;
            if(map[i + 1] == 'y')
                map[i + 1] = '.';
        }
        if(map[i] == 'y')
            cntb ++;
        if(map[i] == 'g')
        {
            cntg ++;
            if(map[i + 1] == 'i')
                map[i + 1] = '.';
            if(map[i + 2] == 'r')
                map[i + 2] = '.';
            if(map[i + 3] == 'l')
                map[i + 3] = '.';
        }
        if(map[i] == 'i')
        {
            cntg ++;
            if(map[i + 1] == 'r')
                map[i + 1] = '.';
            if(map[i + 2] == 'l')
                map[i + 2] = '.';
        }
        if(map[i] == 'r')
        {
            cntg ++;
            if(map[i + 1] == 'l')
                map[i + 1] = '.';
        }
        if(map[i] == 'l')
            cntg ++;
    }

    cout << cntb << endl << cntg << endl;

    return 0;
}