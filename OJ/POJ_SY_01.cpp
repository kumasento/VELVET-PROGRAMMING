#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
	freopen("data_sy1.in", "r", stdin);
	int N; scanf("%d", &N);
	map<string, vector<int> > mmap;
	for(int j = 1; j <= N; j++){
		int nc; scanf("%d", &nc);
		for(int i = 0; i < nc; i++){
			string st; cin>>st;
			if(find(mmap[st].begin(), mmap[st].end(), j)==mmap[st].end())
				mmap[st].push_back(j);
		}
	}
	int M; cin>>M;
	while(M--){
		string st; cin>>st;
		sort(mmap[st].begin(), mmap[st].end());
		for(int j = 0; j < mmap[st].size(); j++)
			cout << mmap[st][j] << ((j==mmap[st].size()-1) ? '\n' : ' ');
		if(!mmap[st].size())
			cout << "NOT FOUND\n";
	}
	return 0;
}