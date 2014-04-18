#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define MAXN 100010

using namespace std;

int N, K;
int qmax[MAXN], qmin[MAXN], maxf, maxr, minf, minr;
int minlst[MAXN], maxlst[MAXN], mint, maxt;
int a[MAXN];

int main(){
	freopen("data_2823.in","r",stdin);
	scanf("%d%d", &N, &K);
	maxf=maxr=minf=minr=mint=maxt=0;
	qmin[0]=qmax[0]=0;
	scanf("%d", &a[0]);
	if(K==1){
		minlst[mint++]=a[0];
		maxlst[maxt++]=a[0];
	}
	for(int i = 1; i < K-1; i++){
		scanf("%d",&a[i]);
		if(a[i]>=a[qmin[minr]]) qmin[++minr]=i;
		else{
			while(a[i]<a[qmin[minr]] && minr>=minf) minr--;
			qmin[++minr]=i;
		}
		if(a[i]<=a[qmax[maxr]]) qmax[++maxr]=i;
		else{
			while(a[i]>a[qmax[maxr]] && maxr>=maxf) maxr--;
			qmax[++maxr]=i;
		}
	}
	for(int i=(1>K-1)?1:K-1; i<N; i++){
		scanf("%d", &a[i]);
		int tmp=i-K+1;
		if(a[i]>=a[qmin[minr]]) qmin[++minr]=i;
		else{
			while(a[i]<a[qmin[minr]] && minr>=minf) minr--;
			qmin[++minr]=i;
		}
		while(qmin[minf]<tmp) minf++;
		minlst[mint++]=a[qmin[minf]];

		if(a[i]<=a[qmax[maxr]]) qmax[++maxr]=i;
		else{
			while(a[i]>a[qmax[maxr]] && maxr>=maxf) maxr--;
			qmax[++maxr]=i;
		}
		while(qmax[maxf]<tmp) maxf++;
		maxlst[maxt++]=a[qmax[maxf]];
	}
	printf("%d", minlst[0]);
	for(int i=1; i<mint; i++)
		printf(" %d", minlst[i]);
	printf("\n");
	printf("%d", maxlst[0]);
	for(int i=1; i<maxt; i++)
		printf(" %d", maxlst[i]);
	printf("\n");

	return 0;
}