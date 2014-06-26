#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	freopen("1388.in", "r", stdin);
	int n, m; 
	while(cin>>n>>m){
		double ans = 0.0;
		for(int i = 1; i < n; i++){
			double pos = (double)i / n * (n + m);
			ans += abs(pos - floor(pos+0.5)) / (n + m);
		}
		printf("%.4lf\n", ans * 10000);
	}	
	return 0;
}