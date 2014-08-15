#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

#define MAXM 100

using namespace std;

/*
 * This program needs high precise arithmetic operation:
 * Try to use class:
 */

class bign{
public:
	string num;
	bign(){}
	bign(int num){
		char A[100]; memset(A, 0, sizeof(A)); 
		sprintf(A, "%d", num);
		this->num = string(A);
	}
	bign operator+ (const bign &b) const{
		bign c;
		int l1 = this->num.length(), l2 = b.num.length();
		int g = 0; int idx = 0;
		while(g || idx < l1 || idx < l2){
			int p1 = 0, p2 = 0;
			if(idx < l1) p1 = this->num[l1-idx-1]-'0';
			if(idx < l2) p2 = b.num[l2-idx-1]-'0';
			idx ++;

			int ans = p1 + p2 + g;
			int digit = ans % 10;
			g = ans/10;
			c.num.push_back(digit+'0');
		}
		reverse(c.num.begin(), c.num.end());
		return c;
	} 
	bign operator* (const bign &b) const{
		bign c(0);
		string str1 = this->num, str2 = b.num;
		if(str1.length() < str2.length())
			swap(str1, str2);
		for(int i = 0; i < str2.length(); i++){
			int p = str2[str2.length()-i-1]-'0';
			int g = 0; int idx = 0;
			bign tmp_bign;
			while(g || idx < str1.length()){
				int q = 0;
				if(idx < str1.length()) q = str1[str1.length()-idx-1]-'0';
				idx ++;
				int ans = p * q + g;
				int digit = ans%10;
				g = ans/ 10;
				tmp_bign.num.push_back(digit+'0');
			}
			reverse(tmp_bign.num.begin(), tmp_bign.num.end());
			for(int j = 0; j < i; j++)
				tmp_bign.num.push_back('0');
			
			c = c + tmp_bign;
		}
		return c;
	}
	bool operator < (const bign& b) const{//重载<号运算
	    if(this->num.length() != b.num.length()) return this->num.length() < b.num.length();
	    for(int i = 0; i < this->num.length(); i++)
	      if(this->num[i] != b.num[i]) return this->num[i] < b.num[i];
	    return false;
  }
};

int main(){
	freopen("1166.in", "r", stdin);
	int n, m; cin>>n>>m;
	int M[n][m]; memset(M, 0, sizeof(M));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>M[i][j];

	//cout << ((bign(46) < bign(48)) ? 1 : 0) << endl;

	// This version doesnt have the high precise arithmetic part
	bign ans(0);
	for(int w = 0; w < n; w++){
		bign dp[MAXM][MAXM]; memset(dp, 0, sizeof(dp));
		bign t(2);
		for(int k = 0; k < m-1; k++)
			t = t * bign(2);
		for(int i = 0; i < m; i++){
			bign n1(M[w][i]);
			dp[i][i] = n1 * t;
		}

		for(int k = 2; k <= m; k++){
			t = bign(2);
			for(int i = 0; i < m-k; i++)
				t = bign(2) * t;
			for(int i = 0; i <= m-k; i++){
				bign n1(M[w][i]), n2(M[w][i+k-1]);
				bign r1 = dp[i+1][i+k-1] + n1*t;
				bign r2 = dp[i][i+k-2] + n2*t;
				dp[i][i+k-1] = (r1 < r2) ? r2 : r1; 
				//cout << r1.num << ' ' << r2.num << ' ' << dp[i][i+k-1].num << endl;
			}
		}
		ans = ans + dp[0][m-1];
	}

	cout << ans.num << endl;
	return 0;
}