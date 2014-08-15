#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	freopen("1044.in", "r", stdin);
	vector<int> q; int tmp;
	while(scanf("%d", &tmp) == 1)
		q.push_back(tmp);

	int n = q.size();
	int dp1[n]; memset(dp1, 0, sizeof(dp1));
	int dp2[n]; memset(dp2, 0, sizeof(dp2));
	for(int i = n-1; i >= 0; i--){
		int max1 = 0, max2 = 0;
		for(int j = i; j < n; j++){
			if(q[j] <= q[i] && max1 < dp1[j])
				max1 = dp1[j];
			if(q[j] > q[i] && max2 < dp2[j])
				max2 = dp2[j];
		}
		dp1[i] = max1 + 1;
		dp2[i] = max2 + 1;
	}
	int max1 = 0, max2 = 0;
	for(int i = 0; i < n; i ++){
		if(max1 < dp1[i])
			max1 = dp1[i];
		if(max2 < dp2[i])
			max2 = dp2[i];
	}

	cout << max1 << endl << max2 << endl;

	return 0;
}