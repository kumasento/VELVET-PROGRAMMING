#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	freopen("1475.in", "r", stdin);

	string ndec; int nota;
	cin >> ndec >> nota;

	int result = 0; int mul_num = 1;
	for(int i = 0; i < ndec.size(); i++){
		int idx = ndec.size()-i-1;
		int num = (ndec[idx] >= 'A') ? ndec[idx] - 'A' + 10 :
									  ndec[idx] - '0';
		result += num * mul_num;
		mul_num *= nota; 	
	}

	cout << result << endl;
	return 0;
}