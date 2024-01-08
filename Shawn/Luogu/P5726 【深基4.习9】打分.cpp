#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int n;
int score[1010];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        int tmp;
        cin >> tmp;
        score[i] = tmp;
    }

    sort(score + 1, score + n + 1);

    int sum = 0;
    for(int i = 2; i <= n - 1; i ++)
    {
        sum += score[i];
    }

    cout << fixed << setprecision(2) << (double)sum / (n - 2) << endl;

    return 0;
}