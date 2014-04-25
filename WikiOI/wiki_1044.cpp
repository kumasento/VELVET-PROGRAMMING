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
	
	int size = seq.size();
	int dp[size + 1]; memset(dp, 0, sizeof(dp));

	/*
	 *	at each point, check the dp value of all the points
	 * 	following which is lower that current height.
	 * 	
	 * 	Assume that the current point should be choosed.
	 */	

	for(int i = size - 1; i >= 0; i--){
		int max = 0;
		for(int j = i; j < size; j++){
			if(seq[j] <= seq[i] && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;
	}

	int total_max = 0;
	for(int i = 0; i < size; i++)
		if(total_max < dp[i])
			total_max = dp[i];

	cout << total_max << endl;

	int mark[size+1]; memset(mark, 0, sizeof(mark));
	int sum = 0;
	while(1){
		sum ++;
		memset(dp, 0, sizeof(dp));
		int trace[size + 1]; memset(trace, 0, sizeof(trace));
		int idx = size - 1; 

		for(int i = size - 1; i >= 0; i--){
			if(mark[i] == 0){
				int max = 0; int tmp = i;
				for(int j = i; j < size; j++){
					if(mark[j] == 0 && seq[j] <= seq[i] && dp[j] > max){
						tmp = j;
						max = dp[j];
					}
				}
				idx = i;
				dp[i] = max + 1;
				trace[i] = tmp;
			}
		}
		/*
		 *	find the point you choose in dp
		 */
		int cnt = 0;
		/*
		for(int i = 0; i < size; i++)
			cout << trace[i] << ' ';
		cout << endl;
		*/
		while(trace[idx] != idx && mark[idx] == 0){
			cnt ++;
			mark[idx] = 1;
			idx = trace[idx];
		}
		//cout << cnt << endl;
		//cout << idx << endl;

		mark[idx] = 1;
		/*
		for(int i = 0; i < size; i++)
			cout << mark[i] << ' ';
		cout << endl;
		*/
		if(cnt == 0)
			break;
	}
	cout << sum-1 << endl;

	return 0;
}	