#include<iostream>
#include<cstring>

#define mod %

const int LEN = 5050;

using namespace std;


namespace gjd
{
    void clear(int a[]) 
    {
        for (int i = 0; i < LEN; ++i) 
            a[i] = 0;
    }

    void read(int a[]) 
    {
        static char s[LEN + 1];
        scanf("%s", s);

        clear(a);

        int len = strlen(s);
        for (int i = 0; i < len; ++i) 
            a[len - i - 1] = s[i] - '0';
    }

    void print(int a[]) 
    {
        int i;
        for (i = LEN - 1; i >= 1; --i)
            if (a[i] != 0) 
                break;

        for (; i >= 0; --i) 
            putchar(a[i] + '0');
        
        putchar('\n');
    }

    void add(int a[], int b[], int c[]) 
    {
        clear(c);

        for (int i = 0; i < LEN - 1; ++i) 
        {
            c[i] += a[i] + b[i];
            if (c[i] >= 10) 
            {
                c[i + 1] += 1;
                c[i] -= 10;
            }
        }
    }
};

using namespace gjd;        

int main()
{
    int n;
    cin >> n;

    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if(n == 2)
    {
        cout << 2 << endl;

        return 0;
    }

    int a[LEN], b[LEN], c[LEN];
    a[0] = 1, b[0] = 2;

    for(int i = 3; i <= n; i ++)
    {
        if(i mod 3 == 0)
            add(a, b, c);
        else if(i mod 3 == 1)
            add(b, c, a);
        else
            add(c, a, b);
    }

    if(n mod 3 == 0)
        print(c);
    if(n mod 3 == 1)
        print(a);
    if(n mod 3 == 2)
        print(b);

    return 0;
}