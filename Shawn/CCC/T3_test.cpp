#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<tuple>

using namespace std;

int main() 
{
int n;
cin >> n;
vector<int> a(n), b(n);
for(int i = 0; i < n; i ++)
cin >> a[i];
for(int i = 0; i < n; i ++)
cin >> b[i];

vector<tuple<int, int, int>> seg;
for (int l = 0, r; l < n; l = r) 
{
    r = l;
    while (r < n && b[r] == b[l])
        r++;
    seg.emplace_back(l, r - 1, b[l]);
}

vector<int> pos;
int p = 0;
for (auto [l, r, v] : seg)
{
    while (p < n && a[p] != v)
        p++;
    pos.emplace_back(p);
}

if (p == n) {
    cout << "NO" << endl;
    return 0;
}

cout << "YES" << endl;

vector<tuple<int, int, int>> ans;

int m = (int)seg.size();

for (int i = m - 1; i >= 0; i--) 
{
    auto [l, r, v] = seg[i];

    int p = pos[i];

    if (p <= l) 
    {
        if (p != r)
            ans.emplace_back(1, p, r);
        pos[i] = l;
    } 
    else if (l < p && p < r) 
        ans.emplace_back(1, p, r);
}
for (int i = 0; i < m; i++) 
{
    auto [l, r, v] = seg[i];
    if (l != pos[i])
    ans.emplace_back(0, l, pos[i]);
}

cout << ans.size() << endl;

for(auto [op, l, r] : ans) 
{
    if(op == 0)
        cout << "L";
    else
        cout << "R";
    cout << " " << l << " " << r << endl;
}

return 0;
}