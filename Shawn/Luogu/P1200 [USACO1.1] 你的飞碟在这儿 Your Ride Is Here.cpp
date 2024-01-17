#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

char star_name[10];
char team_name[10];

int star_num = 1, team_num = 1;

int main()
{
    cin.getline(star_name, 8);
    cin.getline(team_name, 8);

    int ls = strlen(star_name) - 1;
    int lt = strlen(team_name) - 1;

    for(int i = 0; i <= ls; i ++)
    {
        star_num *= (star_name[i] - 'A' + 1);
    }

    for(int i = 0; i <= lt; i ++)
    {
        team_num *= (team_name[i] - 'A' + 1);
    }

    // cout << "debug: " << star_num << " " << team_num << endl;

    if(star_num % 47 == team_num % 47)
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;

    return 0;
}