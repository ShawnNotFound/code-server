#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

vector<int> chosen;
int n = 3;

void calc(int x)
{
    if(x == n + 1)
    {
        for(int i = 0; i < chosen.size(); i ++)
            cout << chosen[i] << " ";
        cout << endl;
        return;
    }

    calc(x + 1);

    chosen.push_back(x);
    calc(x + 1);

    chosen.pop_back();
}

int main()
{
    calc(1);
}