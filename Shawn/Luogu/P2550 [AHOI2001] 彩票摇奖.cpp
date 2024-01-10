#include<iostream>

using namespace std;

int n;
int now[10], target[10], prize[10];

int main()
{
    cin >> n;
    for(int i = 1; i <= 7; i ++)
        cin >> target[i];
    
    for(int i = 1; i <= n; i ++)
    {
        int cnt = 0;
        for(int j = 1; j <= 7; j ++)
        {
            cin >> now[j];
            for(int k = 1; k <= 7; k ++)
            {
                if(now[j] == target[k])
                {
                    cnt ++;
                    break;
                }
            }
        }
        prize[8 - cnt] ++;
    }

    for(int i = 1; i <= 7; i ++)
        cout << prize[i] << " ";

    return 0;        
}   