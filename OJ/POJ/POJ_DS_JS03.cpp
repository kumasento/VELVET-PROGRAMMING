#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int Find(int a, int p[], int r[]){
	int R = 0; int t = a;
	while(a!=p[a]){
		R += r[a];
		a = p[a];
	}
	p[t] = p[a];
	r[t] = R%2;
	return a;
}

void Union(int ra, int rb, int p[]){
	p[rb] = ra;

	return;
}

int main(){
	freopen("data_js03.in","r",stdin);
	int T; scanf("%d", &T);
	while(T--){
		int N, M; scanf("%d%d", &N, &M);
		
		int p[N+1]; memset(p,0,sizeof(p));
		for(int i = 1; i <= N; i++) p[i] = i;
		int r[N+1]; memset(r,0,sizeof(r));

		while(M--){
			char st[100]; scanf("%s", st);
			if(st[0] == 'D'){
				int a, b; scanf("%d%d", &a, &b);
				int pa = Find(a,p,r), pb = Find(b,p,r);
				Union(pa,pb,p);
				r[pb] = (r[a]+r[b]+1)%2;
			}
			else if(st[0] == 'A'){
				int a, b; scanf("%d%d", &a, &b);
				int pa = Find(a,p,r), pb = Find(b,p,r);
				if(pa == pb){
					if(r[a] == r[b])
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				}
				else 
					printf("Not sure yet.\n");
			}
			/*
			for( int i = 1; i <= N; i++ )
				cout << p[i] <<' ';
			cout << endl;	
			for( int i = 1; i <= N; i++ )
				cout << Find(i,p,r) <<' ';
			cout << endl;
			for( int i = 1; i <= N; i++ )
				cout << r[i] <<' ';
			cout << endl;
			cout << endl;
			*/
		}
	}

	return 0;
}