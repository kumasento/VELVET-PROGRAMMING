#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn=200010;
const int maxd=20;

vector<int> son[maxn];

int dp[maxn][maxd];

int fun(int u,int cost){
	if(dp[u][cost])return dp[u][cost];
	int sz=son[u].size();
	if(sz==0){
		dp[u][cost]=cost;
		return cost;
	}
	int re=cost;
	for(int i=0;i<sz;i++){
		int MIN=1000000000;
		for(int j=1;j<maxd;j++){
			if(j==cost)continue;
			MIN=min(MIN,fun(son[u][i],j));
		}
		re+=MIN;
	}
	dp[u][cost]=re;
	return re;
}

int main(){
    freopen("gifting.full.in", "r", stdin);
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		memset(son,0,sizeof(son));
		memset(dp,0,sizeof(dp));

		cas++;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int p;
			scanf("%d",&p);
			son[p].push_back(i);
		}

		int ans=1000000000;
		for(int i=1;i<maxd;i++){
			ans=min(ans,fun(1,i));
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
