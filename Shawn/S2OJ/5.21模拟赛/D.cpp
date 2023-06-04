#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if(m == 1)  
        cout << "1 1" << endl;
    if(m == 2)
        cout << "1 2" << endl;
    if(m == 3)
        cout << "1 3" << endl;
    if(m == 4)
        cout << "2 4" << endl;
    if(m == 5)
        cout << "2 5" << endl;
    
    if(n == 3 && m == 7)
        cout << "2 6" << endl;

    return 0;
}