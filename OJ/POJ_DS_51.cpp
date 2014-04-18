#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define MAXN 100010
#define fa(x) ((((x)+1)>>1)-1)
#define l(x) ((x)*2+1)
#define r(x) ((x)*2+2)

using namespace std;

int a[MAXN];
int len;

void SiftDown(int x){
	int i = x, j = l(x), tmp = a[i];
	while(j < len){
		if(j < len-1 && a[j]>a[j+1]) j++;
		if(tmp>a[j]){ a[i] = a[j]; i = j; j = l(j); }
		else break;
	}
	a[i] = tmp;
}
void SiftUp(int x){
	int i = x, j = fa(x), tmp = a[x];
	while(j >= 0){
		if(a[j]>tmp){ a[i] = a[j]; i = j; j = fa(j); }
		else break;
	}
	a[i] = tmp;
}
void Insert(int n){
	a[len++] = n;
	SiftUp(len-1);
}
int Delete(){
	int t = a[0];
	a[0] = a[len-1];
	len--;
	SiftDown(0);
	return t;
}

int main(){
	freopen("data_51.in","r",stdin);
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		memset(a, 0, sizeof(a));
		len = 0;
		while(n--){
			int type; scanf("%d", &type);
			if(type == 1){
				int u; scanf("%d", &u);
				Insert(u);
			}	
			else if(type == 2){
				int ans = Delete();
				cout << ans << endl;
			}
			/*
			for(int i = 0; i < len; i++)
				cout << a[i] <<' ';
			cout << endl;	
			*/
		}
	}
	return 0;
}