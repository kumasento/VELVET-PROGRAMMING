#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>

#define MAXN 100010

using namespace std;

int f[MAXN], r[MAXN];

int Find(int x){
	if(f[x] == x) return x;
	int tx = f[x];
	f[x] = Find(f[x]);
	r[x] = (r[tx] + r[x]) % 2;
	return f[x];
}
void Union(int x, int y){
	int ra = Find(x), rb = Find(y);
	if(ra == rb) return ;
	f[rb] = ra;
	r[rb] = (r[x]+r[y]+1)%2;
}

int main(){
	freopen("data_103.in","r",stdin);
	int T; scanf("%d", &T);
	int N, M; 
	while(scanf("%d%d", &N, &M) == 2){
		memset(f, 0, sizeof(f));
		memset(r, 0, sizeof(r));
		for(int i = 1; i <= N; i++)
			f[i] = i;
		while(M--){
			char X[2]; int A, B;
			scanf("%s%d%d", X, &A, &B);
			int ra = Find(A), rb = Find(B);
			//cout << ra << ' ' << rb << endl;
			if(X[0] == 'A'){
				if(ra == rb){
					if((r[A]+r[B])%2)
						puts("In different gangs.");
					else 
						puts("In the same gang.");
				}
				else
					puts("Not sure yet.");
			}
			else if(X[0] == 'D'){
				Union(A, B);
			}
		}
	}

	return 0;
}