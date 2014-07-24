
/** 
 * The idea about the dp algorithm is:
 * dp[i] is the length of LPS end at pos i
 * update it by 
 * dp[i+1] = (str[i+1] == str[i-dp[i]-1]) ? dp[i]+1 : 
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>

#define MAXLEN 110000

using namespace std;

int main(){
	freopen("LPS.in", "r", stdin);

	string str; 
	while(cin>>str){	
		int n = str.length();
		int dp[MAXLEN][MAXLEN]; memset(dp, 0, sizeof(dp));

		int max_len = 0;
		for(int _i = 0; _i < n; _i++){
			for(int _j = _i; _j >= 0; _j --){
				if(_i == _j) 
					dp[_j][_i] = 1;
				else if(_i == _j + 1)
					dp[_j][_i] = (str[_j] == str[_i]) ? 1 : 0;
				else{
					int t_i = _i-1;
					int t_j = _j+1;
					if(str[_i] != str[_j])
						dp[_j][_i] = 0;
					else
						dp[_j][_i] = dp[t_j][t_i];
				}
				if(dp[_j][_i] == 1){
					int t_len = _i - _j + 1;
					//cout << _j << ' ' << _i << ' ' <<  str.substr(_j, t_len) << endl;
					if(t_len > max_len)
						max_len = t_len;
				}
			}
		}

		cout << max_len << endl;
	}

	return 0;
}
