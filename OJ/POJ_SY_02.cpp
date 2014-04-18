#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){
	freopen("data_sy2.in","r",stdin);
	int N; scanf("%d", &N);

	map<int, vector<int> > mmap; 
	for(int i = 1; i <= N; i++){
		int ci; scanf("%d", &ci);
		for(int j = 1; j <= ci; j++){
			int d; scanf("%d", &d);
			if(!mmap[d].size())
				mmap[d].resize(1000);
			mmap[d][i]=1;
		}
	}
	int M; scanf("%d", &M);
	while(M--){
		int check[N+1];
		for(int i = 1; i <= N; i++) scanf("%d", &check[i]);
		map<int, vector<int> >::iterator iter = mmap.begin();
		int cnt = 0;
		while(iter != mmap.end()){
			int ok = 1;
			for(int i = 1; i <= N && ok; i++){
				switch(check[i]){
					case 1:
						if(!(iter->second)[i])
							ok = 0;
						break;
					case 0:
						break;
					case -1:
						if((iter->second)[i])
							ok = 0;
						break;
				}	
			}
			if(ok){
				cnt++;
				printf("%d ",iter->first);
			}
			iter++;
		}
		if(!cnt)
			printf("NOT FOUND");
		printf("\n");
	}
	return 0;
}