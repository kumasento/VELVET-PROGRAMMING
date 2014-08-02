#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 100000

using namespace std;

struct cow{long A, B; int id;} a[MAXN];

int cmp_A( const void * a, const void * b ){
	struct cow * p1 = (struct cow*) a, *p2 = (struct cow*) b;
	return p2->A-p1->A; 
} 
int cmp_B( const void * a, const void * b ){
	struct cow * p1 = (struct cow*) a, *p2 = (struct cow*) b;
	return p2->B-p1->B; 
} 

int main(){
	int N,K; cin >> N >> K;
	memset(a, 0, sizeof(a));

	for(int i = 0; i < N; i++ ){
		cin>>a[i].A>>a[i].B;
		a[i].id = i+1;
	}

	qsort(a,N,sizeof(a[0]),cmp_A);
	qsort(a,K,sizeof(a[0]),cmp_B);

	cout << a[0].id << endl;

	return 0;
}