#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAXN 10010

using namespace std;

int A[MAXN];

int Partition( int x, int q, int r ){
	int i = q, j = r-1;
	while( i < j ){
		while(A[i] <= x) i++;
		while(A[j] > x) j--;
		if(i < j)
			swap(A[i], A[j]);
		else
			return j;
	}
	return j;
}

void QuickSort(int q, int r){
	if(q < r){
		int x = A[q];
		int p = Partition(x, q, r);
		swap(A[q], A[p]);
		QuickSort(q, p);
		QuickSort(p+1, r);
	}
}

int main(){
	freopen("2388.in", "r", stdin);
	int N; cin>>N;
	for( int i = 0; i < N; i++ )
		cin >> A[i];
	QuickSort(0, N);
	
	if(N%2 == 0)
		cout << (A[N/2] + A[N/2-1])/2 << endl;
	else
		cout << A[(N-1)/2] << endl;
	//cout << A[(int)floor((double) N/2)] << endl;
	return 0;
}