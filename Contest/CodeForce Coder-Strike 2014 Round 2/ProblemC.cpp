#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int64;

int main(){
	//freopen("C.in", "r", stdin);
	int n, m; cin>>n>>m;
	int64 A[n]; memset(A, 0, sizeof(A));
	int B[m]; memset(B, 0, sizeof(B));
	int64 sum = 0;
	for(int i = 0; i < n; i++) { cin>>A[i]; sum += A[i]; }
	for(int i = 0; i < m; i++) cin>>B[i];

	int64 max_ans = 0;
	int64 auction_problems[m];
	int64 auction_sum = 0;
	for(int i = 0; i < m; i++){
		auction_problems[i] = A[B[i]-1];
		auction_sum += auction_problems[i];
	}
	max_ans = sum - auction_sum;

	sort(auction_problems, auction_problems+m, less<int64>());
	int upper_ptr = m-1, lower_ptr = 0;
	
	for(int i = 0; i < m; i++){
		int ptr = upper_bound(auction_problems, auction_problems+m, max_ans) - auction_problems;
		if(ptr == lower_ptr){ // cant choose price
			max_ans += auction_problems[upper_ptr--];
		}
		else{
			max_ans *= 2; lower_ptr ++;
		}
	}
	cout << max_ans << endl;
 	return 0;
}