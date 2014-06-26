#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>

#define MAXN 10010

using namespace std;

// START stores the initial position and direction
// RES stores the calculate result
// The key point is about how to build a connection among them
struct Ant{
	int id;
	int p; 
	int d;
} START[MAXN], RES[MAXN];


int cmp(const void *a1, const void *a2){
	return ((Ant*)a1)->p - ((Ant*)a2)->p;
}

int main(){
	freopen("10881.in", "r", stdin);
	int N; cin>>N;
	for(int I = 0; I < N; I++){
		memset(START, 0, sizeof(START));
		int L, T, n; cin>>L>>T>>n;
		for(int i = 0; i < n; i++){
			int p; char d; scanf("%d %c", &p, &d);
			START[i].id = i; START[i].p = p; START[i].d = (d == 'R') ? 1 : -1;
			RES[i].id = 0; RES[i].p = p + T * START[i].d; RES[i].d = START[i].d;
		}

		// The FIRST ant in the START array is not the one in the FIRST position
		// CONNECT: rank in START -> rank in POSITION
		qsort(START, n, sizeof(Ant), cmp);
		int CONNECT[n]; 
		for(int i = 0; i < n; i++)
			CONNECT[START[i].id] = i;
		
		// For the ants in the RES array, they keep the direction
		qsort(RES, n, sizeof(Ant), cmp);
		for(int i = 0; i < n-1; i++)
			if(RES[i].p == RES[i+1].p)
				RES[i].d = RES[i+1].d = 0;


		cout << "Case #" << I+1 << ":" << endl;
		for(int i = 0; i < n; i++){
			int idx = CONNECT[i];
			if(RES[idx].p < 0 || RES[idx].p > L) puts("Fell off");
			else printf("%d %s\n", RES[idx].p,
								   (RES[idx].d == 1) ? "R" :
								   ((RES[idx].d == 0) ? "Turning" : "L"));
		}
		printf("\n");
	}
	return 0;
}