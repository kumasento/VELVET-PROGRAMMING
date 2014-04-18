#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	freopen("1474.in", "r", stdin);

	int decimal, notation;
	cin >> decimal >> notation;

	string result;
	while(decimal != 0){
		int mod = decimal % notation;
		decimal /= notation;

		char push_char;
		if(mod >= 0 && mod <= 9)
			push_char = '0'+mod;
		else
			push_char = 'A'+mod-10;

		result.push_back(push_char);
	}
	reverse(result.begin(), result.end());
	cout << result << endl;
	return 0;
}