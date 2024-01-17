#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

string map[50] = {"0", "one", "two", "three", "four", "five", "six", "seven", 
"eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
"sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a",
"both", "another", "first", "second", "third"
};

string m[50] = {"0", "01", "04", "09", "16", "25", "36", "49", "64", "81", "00",
 "21", "44", "69", "96", "25", "56", "89", "24", "61", "00", "01", "04", "01", "01", "04", "09"};

string fm[50] =  {"0", "1", "4", "9", "16", "25", "36", "49", "64", "81", "",
 "21", "44", "69", "96", "25", "56", "89", "24", "61", "", "1", "4", "1", "1", "4", "9"};


int main()
{
    bool fzero = true;
    bool op = false;
    for(int i = 1; i <= 6; i ++)
    {
        string tmp;
        cin >> tmp;
        for(int i = 1; i <= 26; i ++)
        {
            if(map[i] == tmp)
            {
                op = true;
                if(fzero)
                {
                    cout << fm[i];
                    if(!(m[i] == "00"))
                        fzero = false;
                }
                else
                {
                    cout << m[i];
                }
            }  
        }
    }

    if(!op)
        cout << 0;

    cout << endl;

    return 0;
}