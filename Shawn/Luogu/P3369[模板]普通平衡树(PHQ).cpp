#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define mian main

using namespace std;

namespace PHQ
{
    int merge(int A, int B)
    {
        if(!A || !B)
            return A + B;
        if(fix[A] < fix[B])
        {
            ch[A][1] = merge(ch[A][1], B);
            update(A);
            return A;
        }
        else
        {
            ch[B][1] = merge(ch[B][1], B);
            update(B);
            return B;
        }
    }

    void split(int now, int k, int &x, int &y)
}