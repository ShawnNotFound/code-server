#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
char tmp[10], opt, sans[50];
int a, b, ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> tmp;
        if(tmp[0] >= 'a' && tmp[0] <= 'z')
        {
            opt = tmp[0];
            cin >> a >> b;
        }
        else
        {
            sscanf(tmp, "%d", &a);
            cin >> b;
        }

        memset(sans, 0, sizeof(sans));
        if(opt == 'a')
            sprintf(sans, "%d+%d=%d", a, b, a + b);
        else if(opt == 'b')
            sprintf(sans, "%d-%d=%d", a, b, a - b);
        else if(opt == 'c')
            sprintf(sans, "%d*%d=%d", a, b, a * b);

        cout << sans << endl << strlen(sans) << endl;
    }
}