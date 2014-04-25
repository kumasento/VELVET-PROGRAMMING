#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXH 30010

using namespace std;

int main(){
	freopen("1044.in", "r", stdin);
	vector<int> seq; int tmp; 
	while(scanf("%d", &tmp) == 1)
		seq.push_back(tmp);
	//int size = seq.size();
	//int dp[size+1]; memset(dq, 0, sizeof(dp));
	vector<int> discrete_height(seq.begin(), seq.end());
	sort(discrete_height.begin(), discrete_height.end());

	int dp[MAXH]; memset(dp, 0, sizeof(dp));
	for(int i = 0; i < seq.size(); i++){
		int height = seq[i];
		int hstart = lower_bound(discrete_height.begin(), discrete_height.end(), height) - 
					discrete_height.begin();
		

		for(int hid = hstart; hid < discrete_height.size(); hid++){
			if(discrete_height[hid] >= height){
				dp[discrete_height[hid]] ++;
			}
		}
	}
	
	return 0;
}	