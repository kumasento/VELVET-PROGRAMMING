#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	freopen("Q2.in", "r", stdin);

	int T; cin>>T;
	for(int t = 1; t <= T; t++){
		int N; cin>>N;
		long long triple_same = (N*(N+1))*(N*(N+1))/4;
		long long all_diff = 0;
		for(int i = 1; i <= N-2; i++){
			for(int j = i+1; j <= N-1; j++){
				for(int k = j+1; k <= N; k++ ){
					all_diff += i * j * k;
				}
			}
		}
		all_diff *= 6;

		printf("Case %d: %lld\n", t, (all_diff+triple_same) % (1000000000+7));
	}

	return 0;
}