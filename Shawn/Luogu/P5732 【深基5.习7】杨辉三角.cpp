#include<iostream>
#include<cstring>

using namespace std;

int n;
int graph[25][25];

int main()
{
    cin >> n;

    graph[1][1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        for(int j = 1; j <= i; j ++)
        {
            graph[i][j] = graph[i - 1][j - 1] + graph[i - 1][j]; 
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= i; j ++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    return 0;
}