#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

const int N = 110;

using namespace std;

char s[N], c[N];

bool flag;

int main()
{
    cin.tie(0);
    cout.tie(0);

	cin >> s >> c;

    for(int i = 0; i <= strlen(s); i ++)
	{
		flag = 1;
		for(int j = 0; j < strlen(s); j ++)
			if(s[j] != c[j])
			{
				flag = 0;
				break;
			}
        
		if(flag)
		{
			cout << "Yes" << endl;
			return 0;
		}

		char combind = c[strlen(s) - 1];

		for(int j = strlen(s) - 1; j; j --)
			c[j] = c[j - 1];
        
		c[0] = combind;
	}

	cout << "No" << endl;

	return 0;
}
