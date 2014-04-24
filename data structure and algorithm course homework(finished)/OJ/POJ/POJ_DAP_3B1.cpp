// This is the list tree question

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define MAXN 30000

typedef long long LL;

using namespace std;

int N;
LL a[MAXN];

int l[MAXN], r[MAXN];

//struct 
typedef
struct _LT{
	struct _LT *ch[2];
	LL v;
	int d;
} LT, *PLT;

PLT head[MAXN];

void Merge( PLT LT1, PLT LT2 ){
	PLT t = LT1->ch[1]; // fetch the r child
	LT1->ch[1] = LT2; // set LT2 to the r child of LT1
	if( t == NULL )
		return ; // if LT2 doesnt have a r child;
				 // just Merge it
	PLT w = LT1;
	while( w->ch[1] != NULL && w->ch[1]->v > t->v ){
		// the condition is:
		// if the LT1 has r child AND
		// the r child has bigger value than t;

		// so the t's v will be bigger than the insert point
		w = w->ch[1];
	}
	if( w->ch[1] == NULL )
		w->ch[1] = t;
	else{
		PLT tmp = w->ch[1];
		w->ch[1] = t;

		// at the r point it cant be Merged
		// so exchange the Merge order.
		Merge( t, tmp );
	}
	return ;
};

PLT Pop( PLT t ){
	// reform the tree style by Pop procedure

	if( t->ch[0] == NULL && t->ch[1] != NULL )
		return t->ch[1];
	else if( t->ch[1] == NULL && t->ch[0] != NULL )
		return t->ch[0];
	else if( t->ch[0]->v < t->ch[1]->v ){
		// swap
		swap(t->ch[0], t->ch[1]);
	}

	// let the r child Merge into the l child.
	Merge( t->ch[0], t->ch[1] );
	
	return t->ch[0];
}

int Update( PLT t ){
	// Update by recursive
	if( t == NULL )
		return -1;
	int l1 = Update(t->ch[0]);
	int l2 = Update(t->ch[1]);
	t->d = min(l1,l2) + 1;

	// swap
	if( l1 < l2 ){
		swap(t->ch[0], t->ch[1]);
	}
	return t->d;
}

LL Build(){
	int index = 0;
	for( int i = 0; i < N; i ++, index++ ){
		head[index] = new LT;
		head[index]->d = 0;
		head[index]->ch[0] = head[index]->ch[1] = NULL;
		head[index]->v = a[i];
		//cout << a[i] << endl;
		l[index] = r[index] = i;
		// Merge
		while( index > 0 && head[index-1]->v >= head[index]->v ){
			Merge(head[index-1], head[index]);
			Update( head[index-1] );
			/*
			if((r[index]-l[index]+1)%2 == 1 && (r[index-1]-l[index-1]+1)%2 == 1){
				head[index-1] = Pop(head[index-1]);
				Update(head[index-1]);
			}
			*/
			
			r[index-1] = r[index];
			--index;
		}
	}
	LL sum = 0;

	for( int i = 0; i < index; i++ ){

		for( int j = l[i]; j <= r[i]; ++j ){
			sum += (abs(head[i]->v - a[j]));
		}
	}
	return sum;
}

int main(){
	freopen( "data.txt", "r", stdin );

	while( scanf("%d", &N) != EOF ){
		memset(a,0,sizeof(a));

		for( int i = 0; i < N; i ++ )
			scanf("%lld", &a[i]);
		
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));		
		LL sum = Build();
		//cout << sum << endl;
		// reverse
		
		for( int i = 0; i < N/2; ++i ){
			swap(a[i],a[N-i-1]);
		}
		
		//cout << a[6] << endl;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		sum = min( sum, Build() );
		
		printf("%lld\n", sum );
	}
	return 0;
}