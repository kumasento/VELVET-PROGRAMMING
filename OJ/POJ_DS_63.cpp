#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>

#define MAXN 10010

using namespace std;

int main(){
	freopen("data_63.in","r",stdin);
	string st; int T = 1;
	while(cin>>st && st[0]!='#'){
		int h1 = 0, t1 = 0;
		int h2 = 0, t2 = 0;
		int sum[MAXN]; memset(sum, 0, sizeof(sum));
		int layer = 0;
		for(int i = 0; i < st.length(); i++){	
			if(st[i] == 'd'){
				t1 ++; 
				if(t1 > h1) h1 = t1;
				t2++; t2 += sum[t1-1];
				if(t2 > h2) h2 = t2;
			}
			else if(st[i] == 'u'){
				t1--; t2 --; t2 -= sum[t1];
				sum[t1+1] = 0;
				sum[t1]++;
			}
		}
		printf("Tree %d: %d => %d\n", T, h1, h2);
		T++;
	}
	return 0;
}