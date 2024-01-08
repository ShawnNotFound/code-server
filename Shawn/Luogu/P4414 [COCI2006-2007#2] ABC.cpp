#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>

using namespace std;

map<char, int> m;

int main()
{
    int n[5];
    cin >> n[1] >> n[2] >> n[3];
    sort(n + 1, n + 4);
    m['A'] = n[1], m['B'] = n[2], m['C'] = n[3];

    char c[5];
    cin >> c;

    // cout << c[0] << " " << c[1] << " " << c[2] << endl;

    cout << m[c[0]] << " " << m[c[1]] << " " << m[c[2]] << endl;
}