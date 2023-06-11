#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<bitset>

using namespace std;

int n, k, c;
int a[510][10];

struct node
{
    bool ok[510];
    vector<int> can_choose;
    int pos, val;
    bool operator<(const node& b) const
    {
        return val < b.val;
    }
} M;

priority_queue<node> q;

void bind(node x)
{
    int tmp[10];
    memset(tmp, 0, sizeof(tmp));

    x.pos = x.can_choose.size();

    // cout << x.pos << endl;

    for(int i = 1; i <= x.pos; i ++)
        for(int j = 1; j <= k; j ++)
            tmp[j] = max(tmp[j], a[x.can_choose[i - 1]][j]);
    
    // for(int i = 1; i <= 6; i ++)
    //     cout << tmp[i] << " ";
    // cout << endl;

    for(int i = x.pos + 1; i <= k; i ++)
    {
        int use;
        bool flag = false;

        for(int j = 1; j <= n; j ++)
            if(x.ok[j] && (!flag || a[j][i] >= a[use][i]))
            {
                // cout << j << endl;

                flag = true;
                use = j;

                // cout << "use: " << use << endl;
            }

        if(!flag)
            return;
        
        for(int j = 1; j <= k; j ++)
            tmp[j] = max(tmp[j], a[use][j]);

        // for(int i = 1; i <= 6; i ++)
        //     cout << tmp[i] << " ";
        // cout << endl;

        x.ok[use] = false;

        x.can_choose.push_back(use);
    }

    int value = 0;

    for(int i = 1; i <= k; i ++)
        value += tmp[i];

    x.val = value;

    q.push(x);
}

// void reset_ok(int n)
// {
    
//     for(int i = n + 1; i < k; i ++)
//         tx.ok[x.can_choose[i]] = true;
// }

int main()
{
    cin >> n >> k >> c;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= k; j ++)
            cin >> a[i][j];

    // cout << "finish read" << endl;

    memset(M.ok, true, sizeof(M.ok));
    
    // cout << "memset" << endl;

    bind(M);

    while(c --)
    {
        node x = q.top();

        // cout << c << ": " << x.val << " " << x.pos << endl;

        q.pop();

        if(!c)
        {
            cout << x.val << endl;
            return 0;
        }

        for(int i = x.pos; i < k; i ++)
        {
            // cout << "here ~" << endl;

            node tx = x;
            tx.can_choose.resize(i);

            tx.ok[x.can_choose[i]] = false;

            for(int j = i + 1; j < k; j ++)
                tx.ok[x.can_choose[j]] = true;


            // for(int i = 1; i <= 6; i ++)
            //     cout << tx.ok[i] << " ";
            // cout << endl;
            
            // cout << "now bind" << endl;

            bind(tx);

            // cout << "finish bind" << endl;
        }
    }

    return 0;
}