#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

struct Segment {
    int l, st, ed;
};

vector<Segment> seg;
vector<int> a, b;

int main() {
    int n;
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) 
        cin >> b[i];

    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;
        while (r <= n && b[r] == b[l])
            r++;
        seg.emplace_back(Segment{l, r - 1, b[l]});
    }

    vector<int> pos(n + 1, 0);
    int p = 1;
    for (int i = 1; i <= seg.size(); i++) { // Start loop at 1
        while (p <= n && a[p] != seg[i-1].ed) // Adjust indexing for seg
            p++;
        if (p <= n) pos[i] = p; // Store position if found
    }

    if (p > n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<Segment> ans;
    int m = seg.size();
    for (int i = m; i >= 1; i--) { // Start loop at 1, adjust for 1-based indexing
        int l = seg[i-1].l, r = seg[i-1].st, v = seg[i-1].ed;
        p = pos[i]; // Adjusted for 1-based loop
        if (p <= l) {
            if (p < r)
                ans.emplace_back(Segment{1, p, r});
            // pos[i] = l; No need to adjust pos here as it's not reused
        } else if (l < p && p <= r) {
            ans.emplace_back(Segment{1, p, r});
        }
    }
    for (int i = 1; i <= m; i++) { // Adjust loop to start at 1
        int l = seg[i-1].l, r = seg[i-1].st, v = seg[i-1].ed;
        if (l != pos[i])
            ans.emplace_back(Segment{0, l, pos[i]});
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].l == 0)
            cout << "L";
        else
            cout << "R";
        cout << " " << ans[i].st << " " << ans[i].ed << endl; // Previously adjusted to -1, now using original values
    }

    return 0;
}