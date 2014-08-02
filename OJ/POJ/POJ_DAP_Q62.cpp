#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define MAXN 50010
#define MAXK 10
#define INF_MAX 0x3f3f3f3f

using namespace std;

int N, K;
struct point{
	long long p[MAXK];
	int id;
} T[MAXN], op, pp;
int split[MAXN], now, use[MAXN], id;
double var[MAXK];
long long ans;

bool cmp(point a, point b){
	return a.p[split[now]]<b.p[split[now]];
}

void build(int L, int R){
	if(L>R) return ;
	int mid = (L+R)>>1;
	for( int i = 0; i < K; i++){
		double sum=0.0, avg=0.0; var[i]=0.0;
		for(int j=L; j<=R; j++)
			sum += T[j].p[i];
		avg=sum/(R-L+1);
		for(int j=L; j<=R; j++)
			var[i]+=(T[j].p[i]-avg)*(T[j].p[i]-avg);
		var[i]/=(R-L+1);
	}
	split[now=mid]=0;
	for(int i=1; i<K; i++){
		if(var[split[mid]]<var[i])
			split[mid]=i;
	}

	nth_element(T+L, T+mid, T+R+1, cmp);
	//qsort(T+L, R-L, sizeof(T[0]), cmp);

	build(L,mid-1);
	build(mid+1,R);
}
void query(int L, int R){
	if(L>R) return;
	int mid = (L+R)>>1;

	long long dis = 0;
	for(int j=0; j<K; j++)
		dis+=(T[mid].p[j]-op.p[j])*(T[mid].p[j]-op.p[j]);

	if(dis<ans && !use[T[mid].id]){
		ans = dis;
		pp = T[mid];
		id = T[mid].id;
	}
	long long radius =(op.p[split[mid]]-T[mid].p[split[mid]])
						*(op.p[split[mid]]-T[mid].p[split[mid]]);
	if(op.p[split[mid]]<T[mid].p[split[mid]]){
		query(L, mid-1);
		if(radius<=ans)
			query(mid+1,R);
	}
	else{
		query(mid+1,R);
		if(radius<=ans)
			query(L,mid-1);
	}
}

int main(){	
	freopen("data_q62.in","r",stdin);
	while(scanf("%d%d", &N, &K) != EOF){

		for(int i = 1; i <= N; i++){
			T[i].id = i;
			for(int j = 0; j<K; j++)
				scanf("%lld",&T[i].p[j]);
		}

		build(1,N);
		int t; scanf("%d",&t);
		while(t--){
			for(int j = 0; j<K; j++)
				scanf("%lld", &op.p[j]);
			int m; scanf("%d",&m);
			cout << "the closest "<<m<<" points are:" << endl;

			memset(use,0,sizeof(use));
			while(m--){
				ans = (long long) INF_MAX * INF_MAX;
				query(1,N);
				for(int j=0; j<K; j++)
					printf("%lld%c",pp.p[j],((j!=K-1) ? ' ': '\n'));
				
				use[id] = 1;
			}
		}
	}

	return 0;
}