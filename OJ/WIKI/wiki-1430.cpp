#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	freopen("wiki-1430.in", "r", stdin);

	int N; cin>>N;
	int upper_bound = (int)(sqrt((double) N));

	int ok = 1;
	for(int i = 2; i <= upper_bound; i++){
		if(N % i == 0){
			cout << "\\n" << endl;
			ok = 0;
			break;
		}
	}
	if(ok)
		cout << "\\t" << endl;

	return 0;
}