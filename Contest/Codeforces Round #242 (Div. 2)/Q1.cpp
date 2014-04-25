#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	//freopen("Q1.in", "r", stdin);
	int n; cin>>n;
	char hamsters[n+1]; memset(hamsters, 0, sizeof(hamsters));
	int X = 0, x = 0;
	for(int i = 0; i < n; i++){
		cin >> hamsters[i];
		if(hamsters[i] == 'x') x++;
		else X++;
	}
	int d = abs(x-X)/2;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(X > x){
			if(hamsters[i] == 'X'){
				hamsters[i] = 'x';
				cnt ++;
			}
		}
		else if(X < x){
			if(hamsters[i] == 'x'){
				hamsters[i] = 'X';
				cnt ++;
			}
		}
		if(cnt == d)
			break;
	}
	hamsters[n] = '\0';
	cout << d << endl;
	cout << hamsters << endl;
	return 0;
}