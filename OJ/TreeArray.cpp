#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define MAXN 1000

using namespace std;

int a[MAXN],c[MAXN];

// 1D
int lowbit( int n ){ return n & (-n); }
void modify( int n, int delta ){
	while(n<=N){
		c[n]+=delta;
		n+=lowbit(n);
	}
}
int sum(int n){
	int ret = 0;
	while( n!=0 ){
		ret += c[n];
		n-=lowbit(n);
	}
	return ret;
}
//2D
int lowbit(int x){ return (x) & (-x); }
void modify(int x, int y, int delta){
	int i, j;
	for(i=x; i<=N; i+=lowbit(i))
		for(j=y; j<=N; j+=lowbit(j))
			c[i][j]+=delta;
}
int sum( int x, int y ){
	int ret = 0, i, j;
	for(i=x; i>0; i-=lowbit(i))
		for(j=y; j>0; j-=lowbit(j))
			ret+=c[i][j];
	return res;
}

int main(){

	return 0;
}