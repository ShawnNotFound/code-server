//给定一个长度为n的序列，有m种操作，每个物品可以操作序列中l~r（包括l,r）的元素，并且当且仅当这个范围内还有没有被操作过的元素才可以使用这个操作，使用每个操作还可以获得对应的收益，求最大收益

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int dp[N];
struct Op {
    int l, r, w;
}ops[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ops[i].l >> ops[i].r >> ops[i].w;
    }
    for (int i = 1; i <= m; i++) {
        dp[ops[i].r] = max(dp[ops[i].r], dp[ops[i].l - 1] + ops[i].w);
    }
    cout << dp[n] << endl;
    return 0;
}
