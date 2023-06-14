//在调IO配置的时候调出来的一键崩服

#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

int n;

int main()
{
    system("cat /root/workspace/code-server/io/answer | /root/workspace/code-server/executable_files/compare");

    if(cin >> n)
        cout << "have input" << endl;
    
    else
        cout << "no input" << endl;

    // system("g++ -g '${file}' -o ${workspaceRoot}/executable_files/'${fileBasenameNoExtension}' 
    // -std=c++14 -O2 -fsanitize=undefined -fsanitize=address && 
    // cat ${workspaceRoot}/io/input | ${workspaceRoot}/executable_files/'${fileBasenameNoExtension}' > ${workspaceRoot}/io/output");
}