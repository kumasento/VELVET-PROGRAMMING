#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	freopen("1098.in", "r", stdin);
	int N; cin>>N;
	int Cards[N]; memset(Cards, 0, sizeof(Cards));
	int sum = 0;
	for(int i = 0; i < N; i++){
		cin>>Cards[i];
		sum += Cards[i];
	}
	int Average = sum/N;
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(i > 0){
			// move to the left
			if(Cards[i-1] < Average){
				Cards[i] -= Average - Cards[i-1];
				Cards[i-1] = Average;
				cnt ++;
			}
		}
		if(i < N-1){
			// move to the right
			if(Cards[i] > Average){
				Cards[i+1] += Cards[i] - Average;
				Cards[i] = Average;
				cnt ++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}