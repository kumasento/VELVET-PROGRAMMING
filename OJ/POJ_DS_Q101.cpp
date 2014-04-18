#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long cnt;

void merge( int a[], int x, int y ){
	int len = y-x;
	if( len == 1)
		return ;
	if( len == 2 ){
		if(a[x] > a[y-1]){
			swap(a[x],a[y-1]);
			cnt++;
		}
		return ;
	}
	
	int mid = (x+y)>>1;
	int l1 = mid-x, l2 = y-mid;
	int a1[l1], a2[l2];
	memset( a1, 0, sizeof(a1));
	memset( a2, 0, sizeof(a2));
	for( int i = x; i < mid; i++ )
		a1[i-x] = a[i];
	for( int j = mid; j < y; j++ )
		a2[j-mid] = a[j];

	merge( a1, 0, l1 );
	merge( a2, 0, l2 );
	int index = 0;
	int i = 0, j = 0;
	while( index < len ){
		if( i < l1 ){
			if( j < l2 ){
				if( a1[i] < a2[j] )
					a[index] = a1[i++];
				else{
					a[index] = a2[j++];
					cnt ++;
				}
			}
			else{
				a[index] = a1[i++];
				cnt ++;
			}
		}
		else{
			if( j < l2 )
				a[index] = a2[j++];
		}
		index ++;
	}
	return ;
}

int main(){
	int N; cin >> N;
	while( N ){
		int a[N]; memset(a, 0, sizeof(a));;
		for( int i = 0; i < N; i++ )
			cin >> a[i];
		cnt = 0;
		merge( a, 0, N );
		cout << cnt << endl;

		cin >> N;
	}

	return 0;
}
