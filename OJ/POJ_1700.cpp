#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	freopen("data_1700.in", "r", stdin);
	int T; cin >> T;
	while(T--){
		int N; cin>>N;
		int A[N]; memset(A, 0, sizeof(A));
		for(int i = 0; i < N; i++) 
			cin >> A[i];
		sort(A, A+N, less<int>());
		
		int i = 0, j = N-1;
		int cnt = 0; 
		while(i != j){
			while(A[i]+A[])
		}
	}
	return 0;
}