#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>

const int N = 1e3 + 10;

using namespace std;

struct student
{
    char name[20];
    int a, b, c, s;
}stu[N];

int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> stu[i].name;
        cin >> stu[i].a >> stu[i].b >> stu[i].c;
        stu[i].s = stu[i].a + stu[i].b + stu[i].c;
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = i + 1; j <= n; j ++)
        {
            if(abs(stu[i].a - stu[j].a) <= 5 && abs(stu[i].b - stu[j].b) <= 5 && abs(stu[i].c - stu[j].c) <= 5 && abs(stu[i].s - stu[j].s) <= 10)
                cout << stu[i].name << " " << stu[j].name << endl;
        }
    }

    return 0;
}