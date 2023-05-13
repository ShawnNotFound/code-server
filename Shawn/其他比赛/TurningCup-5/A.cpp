// #include<iostream>
// #include<algorithm>
// #include<cstring>
// #include<cmath>

// using namespace std;

// int main()
// {
//     int T;

//     return 0; 
// }
// #include <iostream>
// #include <vector>
// #include <set>

// using namespace std;

// vector<bool> flag;

// bool canDivide(const vector<int>& a) {
//     set<int> diffs;
//     for (size_t i = 1; i < a.size(); ++i) {
//         //cout << "insert: " << a[i] - a[i - 1] << endl;
//         if(!flag[a[i] - a[i - 1]])
//         diffs.insert(a[i] - a[i - 1]);
//         flag[a[i] - a[i - 1]] = true;
//         if (diffs.size() > 2) {
//             return false;
//         }
//     }
//     //cout << "size:" << diffs.size() << endl;
//     return true;
// }

// int main() {

//     freopen("1.in", "r", stdin);
//     freopen("1.out", "w", stdout);

//     int T;
//     cin >> T;

//     while (T--) {
//         int n;
//         cin >> n;

//         vector<int> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }

//         if (canDivide(a)) {
//             cout << "Yes" << endl;
//         } else {
//             cout << "No" << endl;
//         }
//     }

//     return 0;
// }
// #include<iostream>
// #include<cmath>
// #include<cstring>
// #include<algorithm>
// #include<vector>
// #include<set>

// const int N = 1e3 + 10;

// using namespace std;

// int T;
// bool flag;

// int main()
// {
//     cin >> T;
//     while(T --)
//     {
//         set<int> map[N];
//         int a[5010];
//         int n; 
//         cin >> n;
//         for(int i = 1; i <= n; i ++)
//         {
//             cin >> a[i];
//         }

//         for(int i = 1; i <= n; i ++)
//         {
//             for(int j = i + 1; j <= n; j ++)
//             {
//                 map[a[j] - a[i]].insert(i);
//                 map[a[j] - a[i]].insert(j);
//                 cout << "insert " << i << ", " << j << " into " << a[j] - a[i] << endl;
//                 if(map[a[j] - a[i]].size() == n)
//                 {
//                     cout << "Yes" << endl;
//                     flag = true;
//                     break;
//                 }
//             }
//             if(flag)
//                 break;
//         }
//         if(flag)
//         {
//             flag = false;
//             continue;
//         }
//         cout << "No" << endl;

//     }
// }

// #include <iostream>
// #include <cmath>
// #include <cstring>
// #include <unordered_set>
// #include <vector>

// using namespace std;

// bool canDivide(const vector<int>& a) {
//     unordered_set<int> elements;

//     for (int x : a) {
//         elements.insert(x);
//     }

//     for (size_t i = 0; i < a.size(); ++i) {
//         for (size_t j = i + 1; j < a.size(); ++j) {
//             int diff = a[j] - a[i];
//             int target1 = a[j] + diff;
//             int target2 = a[i] - diff;

//             if ((elements.count(target1) == 0 || elements.count(target1 + diff) == 0) &&
//                 (elements.count(target2) == 0 || elements.count(target2 + diff) == 0)) {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         int n;
//         cin >> n;

//         vector<int> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }

//         if (canDivide(a)) {
//             cout << "Yes" << endl;
//         } else {
//             cout << "No" << endl;
//         }
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <set>
#include <cstring>

const int N = 1e8 + 10;

using namespace std;

// vector<vector<int>> diff;
int diff[N];
int count[10];
int cnt;

bool canDivide(const vector<int>& a) 
{
    // diff.clear();
    memset(diff, 0, sizeof(diff));
    cnt = 0;
    memset(count, 0, sizeof(count));

    for (int i = 1; i < a.size(); i ++)
    {
        diff[a[i] - a[i - 1]] ++;
        if(diff[a[i] - a[i - 1]] == 1)
        {
            cnt ++;
            if(cnt > 3)
                return false;
            count[cnt] = i;
        }
    }
    if(cnt == 3)
    {
        if(count[3] - count[2] == 1 && count[2] - count[1] == 1)
            return true;
        else
            return false;
    }
    return true;
}
int main() {

    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (canDivide(a)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}