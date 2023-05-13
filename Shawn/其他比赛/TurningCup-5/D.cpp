#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        while (b[i] != i + 1) {
            if (i + 1 > b[i]) {
                ans.emplace_back(2, i + 1);
                b[i] = i + 1 - b[i];
            } else {
                ans.emplace_back(1, b[i] - i - 1);
                b[i] += b[i] - i - 1;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto [opt, val] : ans) {
        cout << opt << " " << val << endl;
    }

    return 0;
}
