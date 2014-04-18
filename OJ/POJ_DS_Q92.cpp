#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int cmp( const void *a, const void *b ){
	return (*(int*)a)-(*(int*)b);
}

int main(){
	int N; cin >> N;
	int a[N];
	memset(a, 0, sizeof(a));
	for( int i = 0; i < N; i++ ){
		cin>>a[i];
	}
	qsort(a, N, sizeof(int), cmp);
	cout << a[(N-1)/2];

	return 0;
}