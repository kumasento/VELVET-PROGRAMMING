#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

#define EPS 1e-12

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB; 

struct data{
	LL pos[10];
	int id;
} T[N], op, point;

int split[N], now, n, dimension;

bool use[N];
LL ans, id;
DB var[10];

bool cmp(data a, data b){
	return a.pos[split[now]]<b.pos[split[now]];
}

void build( int L, int R ){
	if( L > R )
		return ;
	int mid = (L+R) >> 1;
	for( int pos = 0; pos < dimension; pos ++ ){
		DB ave = var[pos] = 0.0;
		for( int i = L; i <= R; i++ )
			ave+=T[i].pos[pos];
		ave/=(R-L+1);
		for( int i = L; i <= R; i++ )
			var[pos]+=(T[i].pos[pos]-ave)*(T[i].pos[pos]-ave);
		var[pos]/=(R-L+1);
	}

	split[now=mid]=0;
	for( int i = 1; i < dimension; i++ )
		if(var[split[mid]]<var[i])
			split[mid] = i;

	nth_element( T+L, T+mid, T+R+1, cmp );

	build( L, mid-1 );
	build( mid+1, R ); 
}

void query( int L, int R ){
	if( L>R )
		return ;
	int mid = ( L+R )>>1;

	LL dis = 0;
	for( int i = 0; i < dimension; i++ )
		dis+=(op.pos[i]-T[mid].pos[i])*(op.pos[i]-T[mid].pos[i]);

	if( !use[T[mid].id] && dis < ans ){
		ans = dis;
		point = T[mid];
		id = T[mid].id;
	}
}

int main(){


	return 0;
}