#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define N 100

using namespace std;

struct coord{ int x, y, z; } a[N];
struct bond{ int p1, p2; double w; } b[2*N];

int main(){
	freopen("data_Q91.in", "r", stdin);

	int n; cin >> n;
	memset(a, 0, sizeof(a));

	for( int i = 0; i < n; i++ )
		cin >> a[i].x >> a[i].y >> a[i].z;

	int index = 0;
	for( int i = 0; i < n-1; i++ ){
		for( int j = i+1; j < n; j++ ){
			b[index].p1 = i; 
			b[index].p2 = j;
			b[index].w = sqrt(
				pow((a[i].x-a[j].x),2) + pow((a[i].y-a[j].y),2) 
				+pow((a[i].z-a[j].z),2));
			index ++;
		}
	}

	int noswap = 0;
	while( !noswap ){
		noswap = 1;
		for( int i = 0; i < index-1; i++ ){
			if(b[i].w < b[i+1].w){
				swap(b[i],b[i+1]);
				noswap = 0;
			}
		}
	}

	for( int i = 0; i < index; i++ ){
		int i1 = b[i].p1, i2 = b[i].p2;
		printf("(%d,%d,%d)-(%d,%d,%d)=%.2f\n", 
			a[i1].x, a[i1].y, a[i1].z, a[i2].x, a[i2].y, a[i2].z,
			b[i].w);
	}

	return 0;
}