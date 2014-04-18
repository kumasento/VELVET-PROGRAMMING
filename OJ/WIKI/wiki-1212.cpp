#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	freopen("wiki-1212.in", "r", stdin);
	int m, n; cin>>m>>n;

	int bi, li;
	bi = (m>n) ? m : n;
	li = (m<n) ? m : n;
	while(li != 0){
		int mod = bi % li;
		bi = (mod < li) ? li : mod;
		li = (mod < li) ? mod : li;
	}
	cout << bi << endl;

	return 0;
}