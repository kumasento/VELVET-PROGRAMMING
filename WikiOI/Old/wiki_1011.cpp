#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int f(int n){
	int res = 1;
	for(int k = 1; k <= (n/2); k++)
		res += f(k);
	return res;
}

int main(){
	freopen("1011.in", "r", stdin);

	int n; cin>>n;
	cout << f(n) << endl;

	return 0;
}