#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

#define MAXN 2000

using namespace std;

struct stuff{
	string type, name;
	int quality, price;
} S[MAXN];

int cmp(const void *a, const void *b){
	stuff *s1 = (stuff*)a, *s2 = (stuff*)b;
	return s1->price-s2->price;
}

int n, b;
int judge_ok(int m){
	int ok = 1;
	map<string,int> mmap; mmap.clear();
	for(int i = 0; i < n; i++)
		mmap[S[i].type] = 0;
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(!mmap[S[i].type] && S[i].quality >= m){
			mmap[S[i].type] = 1;
			sum += S[i].price;
			if(sum > b){ ok = 0; break; }
		}
	}
	return ok;
}

int main(){
	freopen("data_la3971.in","r",stdin);
	int T; cin>>T;
	while(T--){
		scanf("%d%d", &n, &b);
		memset(S, 0, sizeof(S));
		int minq = 1000000000, maxq = 0;
		for(int i = 0; i < n; i++){
			cin>>S[i].type>>S[i].name>>S[i].price>>S[i].quality;
			if(S[i].quality < minq) minq = S[i].quality;
			if(S[i].quality > maxq) maxq = S[i].quality;
		}
		qsort(S, n, sizeof(S[0]), cmp);

		int l = minq, r = maxq;
		
		while(l < r){
			int m = l + (r-l)/2;
			if(judge_ok(m)) l = m+1;
			else r = m;
		}
		if(judge_ok(l)) cout << l << endl;
		else cout << l-1 << endl;
		
	}
	return 0;
}