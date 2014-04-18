#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-out.out", "w", stdout);
	int T; cin>>T; 
	int idx = 0;
	double C, F, X;
	while(idx < T){
		scanf("%lf%lf%lf", &C, &F, &X);

		int N_P = ceil((double) X/C);
		double INIT_RATE = 2;
		double NOW_RATE = INIT_RATE;
		double START_TIME = 0;

		double MIN_TIME = -1;
		for(int i = 0; i <= N_P; i++){
			double END_TIME = START_TIME + X/NOW_RATE;
			if(MIN_TIME == -1 || MIN_TIME > END_TIME) MIN_TIME = END_TIME;
			
			START_TIME += C/NOW_RATE;
			NOW_RATE += F;
		}
		printf("Case #%d: %.7f\n", idx+1, MIN_TIME );

		idx ++;
	}

	return 0;
}