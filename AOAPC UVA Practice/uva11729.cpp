#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct soldier{
	int b, j;
	int id;
};
int cmp(const void * s1, const void * s2){
	return ((soldier*)s2)->j - ((soldier*)s1)->j;
}

int main(){
	freopen("11729.in", "r", stdin);

	int N; cin >> N;
	int T = 1;
	while( N != 0 ){
		soldier S[N];
		for(int i = 0; i < N; i++){
			cin >> S[i].b >> S[i].j;
			S[i].id = i;
		}
		qsort(S, N, sizeof(S[0]), cmp);

		int b_t = 0, w_t = 0;
		for(int i = 0; i < N; i++){	
			b_t += S[i].b;
			if(b_t + S[i].j > w_t)
				w_t = b_t + S[i].j;
		}

		cout << "Case " << T << ": " << w_t << endl;

		cin >> N;
		T++;
	}
	
	return 0;
}
