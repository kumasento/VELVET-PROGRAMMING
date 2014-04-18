#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define MAXN 1000010

using namespace std;

int n[MAXN], len;

void getnext(string st){
	int i = 1, j = 0;
	memset(n, 0, sizeof(n));
	n[0] = -1;
	while(i < st.length()){
		if(j==-1 || st[i] == st[j])
			i++, j++, n[i]=j;
		else
			j = n[j];
	}
	return ;
}
int KMPmatch(string P, string T){
	int plen = P.length();
	int tlen = T.length();
	int i = 0, j = 0;
	while( j < plen && i < tlen ){
		if( j==-1 || T[i] == P[j])
			i++, j++;
		else
			j = n[j];
	}
	if(j >= plen)
		return i-plen;
	else
		return -1;
}

int main(){
	freopen("data_310.in", "r", stdin);
	int T = 0;
	while(scanf("%d", &len)==1 && len){
		string st; cin >> st;
		getnext(st);
		for(int i = 0; i < st.length(); i++)
			cout << n[i] << ' ';
		cout << endl;
		cout << "Test case #" << T << endl;
		for(int i = 1; i <= st.length(); i++){
			int tmp = i-n[i];
			cout << tmp << endl;
			if(i%tmp == 0 && i/tmp>1){
				cout << i << ' ' << i/tmp << endl;
			}
		}
		T++;
	}
	return 0;
}