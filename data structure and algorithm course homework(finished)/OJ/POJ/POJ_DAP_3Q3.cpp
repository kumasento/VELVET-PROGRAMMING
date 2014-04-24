// k-monotonic

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define MAXN 3000

using namespace std;

int arr[MAXN];
int now[MAXN], sum[MAXN], del[MAXN], alt[MAXN];
int l[MAXN], r[MAXN];
int I, n, k;

typedef struct _node{
	struct  _node* ch[2];
	int d, v;
} LT, *PLT;

PLT head[MAXN];

void lt_merge( PLT lt1, PLT lt2 ){
	PLT t = lt1->ch[1];
	lt1->ch[1] = lt2;
	if( t == NULL )
		return ;
	PLT w = lt1;
	while( w->ch[1] != NULL && w->ch[1]->v > t->v )
		w = w->ch[1];
	if( w->ch[1] == NULL )
		w->ch[1] = t;
	else{
		PLT tmp = w->ch[1];
		w->ch[1] = t;

		lt_merge( t, tmp );
	}
	return ;
}
PLT lt_pop(PLT t){
	if( t->ch[0] != NULL && t->ch[1] == NULL )
		return t->ch[0];
	if( t->ch[0] == NULL && t->ch[1] != NULL )
		return t->ch[1];
	if( t->ch[0]->v < t->ch[1]->v )
		swap(t->ch[0], t->ch[1]);
	lt_merge(t->ch[0], t->ch[1]);
	return t->ch[0];
}
int lt_update(PLT t){
	if( t == NULL )
		return -1;
	int l1 = lt_update(t->ch[0]);
	int l2 = lt_update(t->ch[1]);
	t->d = min(l1,l2) + 1;

	if( l1 < l2 )
		swap( t->ch[0], t->ch[1] );
	return t->d;
}
void lt_build(){
	head[I]->v = arr[0];
	head[I]->d = 0;
	head[I]->ch[0] = head[I]->ch[1] = NULL;
	now[I] = 1; sum[I] = arr[0];
	del[I] = 0; alt[I] = 0;
	l[I] = r[I] = I;

	for( int i = 1; i < n; i ++ ){
		PLT tnow = new LT;
		head[I+1]->v = arr[i];
		head[I+1]->d = 0;
		head[I+1]->ch[0] = head[I+1]->ch[1] = NULL;
		now[I+1] ++; sum[I+1] += arr[i];
		l[I+1] = r[I+1] = i;

		if(head[I+1]->v < head[I]->v){
			lt_merge(head[I], head[I+1]);
			now[I] += now[I+1]; sum[I] += sum[I+1];
			now[I+1] = sum[I+1] = del[I+1] = alt[I+1] = 0;
			r[I] = r[I+1];

			while(now[I] > (r[I]-l[I])/2){
				sum[I] -= head[I]->v;
				alt[I] += head[I]->v;
				now[I] --; del[I] ++;

				head[I] = lt_pop(head[I]);
			}
		}
	}	
}

int main(){
	scanf("%d%d", &n, &k);
	while(!(n==0 && k==0)){
		memset( arr, 0, sizeof(arr) );
		for(int i = 0; i < n; i ++)
			scanf("%d", &arr[i]);

		memset( now, 0, sizeof(now) );
		memset( sum, 0, sizeof(sum) );
		memset( del, 0, sizeof(del) );
		memset( alt, 0, sizeof(alt) );
		memset( l, 0, sizeof(l) );
		memset( r, 0, sizeof(r) ); 

		I = 0;
		lt_build();
		int Sum = 0; 
		for( int i = 0; i < I; i ++ ){
			Sum += abs(alt[I]+sum[I]-head[I]->v*(now[I]+del[I]));
		}
		printf("%d\n", Sum);
	}

	return 0;
}