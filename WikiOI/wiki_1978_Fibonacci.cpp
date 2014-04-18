#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdlib>

using namespace std;

int f(int n){
	if( n == 1 ) return 1;
	if( n == 0 ) return 0;
	else return f(n-1) + f(n-2);
}

int main(){
	freopen("1978.in", "r", stdin);
	int n; cin >> n;
	cout << f(n) << endl;
	return 0;	
}