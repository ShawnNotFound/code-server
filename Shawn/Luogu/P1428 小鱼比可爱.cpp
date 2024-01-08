#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int n;
int a[110], ans[110];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    
    for(int i = 2; i <= n; i ++)
    {
        for(int j = 1; j <= i - 1; j ++)
        {
            if(a[i] > a[j])
                ans[i] ++;
        }
    }

    for(int i = 1; i <= n; i ++)
        cout << ans[i] << " ";

    cout << endl;

    return 0;
}