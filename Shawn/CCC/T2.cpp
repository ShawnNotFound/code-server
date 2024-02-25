#include<iostream>
#include<cstring>

#define mod %

const int N = 110;

using namespace std;

int n, l;
int num[N];
char str[N];

int main()
{
    cin >> n >> l;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= 26; j ++)
            num[j] = 0;
        
        bool flag = true;
        cin >> str + 1;
        for(int j = 1; j <= l; j ++)
        {
            num[str[j] - 'a'] ++;
        }
        for(int j = 2; j <= l; j ++)
        {
            if((num[str[j] - 'a'] == 1 && num[str[j - 1] - 'a'] == 1) || (num[str[j] - 'a'] > 1 && num[str[j - 1] - 'a'] > 1))
                flag = false;
        }
        cout << (flag == true ? "T" : "F") << endl;
    }

    // cout << "debug: " << endl;
    // for(int i = 0; i <= 5; i ++)
    //     cout << num[i] << " ";

    return 0;
}