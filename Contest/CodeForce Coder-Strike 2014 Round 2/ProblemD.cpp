#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int64;

bool check(int64 ans, int *seq, int n){
	for(int i = 0; i < n; i++)
		cout << seq[i] << ' ';
	cout << endl; 
	
	int tmp_ans = seq[0];
	for(int i = 1; i < n; i++){
		if(seq[i] == tmp_ans) tmp_ans *= 2;
		else if(tmp_ans >= ans) return true;
		else if(tmp_ans < seq[i]) tmp_ans = seq[i];
		else{
			
		}
	}
	if(tmp_ans >= ans) return true;
	else return false;
}

int64 search(int * seq, int64 ans, int idx, int n, int *zero_pos, int zero_pos_bound){
	if(idx == zero_pos_bound) return (check(ans, seq, n)) ? 1 : 0;
	int sum = 0;
	for(int k = 2; k <= 4; k+= 2){
		seq[zero_pos[idx]] = k;
		if(check(ans, seq, zero_pos[idx+1]))
			sum += 1<<(zero_pos_bound-idx-1);
		else
			sum += search(seq, ans, idx+1, n, zero_pos, zero_pos_bound);
	}
	return sum;
}

int main(){
	freopen("D.in", "r", stdin);
	int n, k; cin>>n>>k;
	int64 ans = 1 << k;
	//cout << ans << endl;
	int seq[n]; memset(seq, 0, sizeof(seq));
	int zero_pos[n]; memset(zero_pos, 0, sizeof(zero_pos));
	int zero_pos_bound = 0;
	for(int i = 0; i < n; i++) {
		cin >> seq[i];
		if(seq[i] == 0) zero_pos[zero_pos_bound++] = i;
	}
	zero_pos[zero_pos_bound] = n;
	cout << search(seq, ans, 0, n, zero_pos, zero_pos_bound)%((int64)1000000000 + 7) << endl;

	return 0;
}