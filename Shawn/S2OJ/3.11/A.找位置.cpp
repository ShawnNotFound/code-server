#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 1e5 + 10;

using namespace std;

int n, q, k, s;
int ta, tb;

struct WA
{
    int num;
    int nxt;
}map[N];

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i ++)
    {
        cin >> ta >> tb;
        map[ta].num = i;
        map[ta].nxt = tb;
    }
    for(int i = 1; i <= q; i ++)
    {
        cin >> k >> s;
        int t = 0;
        for(int j = k; 1; j = map[j].nxt)
        {
        	
			//如果t的下一位就到时间，那么就输出下一位的位置 
            if(++ t >= s)
            {
                cout << map[map[j].nxt].num << endl;
                break;
            } 
            if(t != 1 && j == k)
            {#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 1e5 + 10;

using namespace std;

int n, q, k, s;
int ta, tb;

struct WA
{
    int num;
    int nxt;
}map[N];

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i ++)
    {
        cin >> ta >> tb;
        map[ta].num = i;
        map[ta].nxt = tb;
    }
//    for(int i = 1; i <= n ; i ++)
//    	cout << map[i].num << " ";
//    cout << endl;
    for(int i = 1; i <= q; i ++)
    {
        cin >> k >> s;
        for(int j = 1; j <= n; j ++)
        {
        	//cout << map[i].num << " ";
        	if(map[j].num == k)
        	{
        		//cout << "set k from " << k << " to " << j << endl;
        		k = j;
        		break;
			}
		}
        int t = 0;
        for(int j = k; 1; j = map[j].nxt)
        {
        	
			//如果t的下一位就到时间，那么就输出下一位的位置 
            if(++ t >= s)
            {
                cout << map[map[j].nxt].num << endl;
                break;
            } 
            if(t != 1 && j == k)
            {
                //j = map[j].nxt;
            	if(s % (t - 1) == 0)
				{
					cout << map[map[j].nxt].num << endl;
					break;
				} 
            	int tmp = t - 1; 
                while(s > 0) s -= tmp;
                s += tmp;
                //cout << " s = " << s << " tmp = " << tmp << " t = " << t << " map[j],nxt = " << map[j].nxt << endl;
                t = 0;
                if(t + 1 >= s)
                {
                	cout << map[map[j].nxt].num << endl;
                	break;
				}
            }
        }
    }
}
                //j = map[j].nxt;
            	if(s % (t - 1) == 0)
				{
					cout << map[map[j].nxt].num << endl;
					break;
				} 
            	int tmp = t - 1; 
                while(s > 0) s -= tmp;
                s += tmp;
                cout << " s = " << s << " tmp = " << tmp << " t = " << t << " map[j],nxt = " << map[j].nxt << endl;
                t = 0;
                if(t + 1 >= s)
                {
                	cout << map[map[j].nxt].num << endl;
                	break;
				}
            }
        }
    }
}