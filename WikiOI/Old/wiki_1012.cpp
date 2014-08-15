#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	freopen("1012.in", "r", stdin);
	int x0, y0; scanf("%d%d", &x0, &y0);
	if(y0 % x0 != 0) 
		cout << "0" << endl;
	else{
		int k = 0, n = y0/x0;
		for(int i = 2; i <= n; i++){
			int start = 0;
			while(n != i){
				if(n%i == 0){
					n /= i;
					if(start == 0)
						k++, start = 1;
				}
				else
					break;
			}
		}
		cout << (2<<k) << endl;
	}
	return 0;
}