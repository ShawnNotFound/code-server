#include<bits/stdc++.h>
using namespace std;
char s[1000010]={'?'};
int p[1000010],n,ans;
void manacher(char *s,int n){
    for(int c=0,mx=0,i=1;i<=n;i++){
        p[i] = i < mx ? min(p[2 * c - i], mx - i) : 1;
        while(s[i + p[i]] == s[i - p[i]])
			++ p[i];
        if(i + p[i] > mx){
        	if(i & 1)
				for(int j = max(mx, i + 4); j < i + p[i]; j ++)
					if(!(j - i & 3) && p[i - (j - i) / 2] > (j - i) / 2)
						ans = max(ans, j - i);
			mx=i+p[i],c=i;
		}
    }
}

int main(){

	scanf("%d %s",&n,s + 1);
    
	for(int i=n;i;i--)
	{
		s[i * 2 + 1] = '#';
		s[i * 2] = s[i];
	}
	s[1]='#';
    
	manacher(s, 2 * n + 1);
    
	printf("%d\n", ans);
    
	return 0;
}