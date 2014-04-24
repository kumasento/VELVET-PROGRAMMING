// This is a double sides queue

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 1000001

using namespace std;

// qmin and qmax are the two queues
// one is non-increase(qmin)
// the other is non-decrease(qmax)
// f and r is front and rear
int qmin[MAXN], qmax[MAXN], minf, minr, maxf, maxr;

// minlst and maxlst are both the 2-End queue structure
// and mint & maxt are the index
int minlst[MAXN], maxlst[MAXN], mint, maxt;

int arr[MAXN];


int main(){
	freopen("data.txt", "r", stdin);

	int n, k;
	scanf("%d%d", &n, &k);

	// init the variables
	minf = maxf = minr = maxr = 0;
	mint = maxt = 0;
	qmin[0] = qmax[0] = 0;

	memset( arr, 0, sizeof(arr) );
	scanf("%d", &arr[0]);
	if( k == 1 )
		minlst[mint++] = maxlst[maxt++] = arr[0];

	// finish the window
	for( int i = 1; i < k-1; i ++ ){
		scanf("%d", &arr[i]);

		// deal with the qmin[]
		// if the now arr[i] is bigger than the qmin's rear
		// so add it to the last
		if(arr[i] >= arr[qmin[minr]])
			qmin[++minr] = i;
		
		// else push the arr[i] to the right place
		else{
			while(arr[i] < arr[qmin[minr]] && minr >= minf)
				minr--;
			qmin[++minr] = i;
		}

		if(arr[i] <= arr[qmax[++maxr]])
			qmax[++maxr] = i;
		else{
			while( arr[i] > arr[qmax[maxr]] && maxr >= maxf )
				maxr--;
			qmax[++maxr] = i;
		}
	}

	// finish the next numbers
	int tmp;
	for( int i = (1>k-1) ? 1 : k-1; i < n; i ++ ){
		scanf("%d", &arr[i]);
		tmp = i-k+1;
		if(arr[i]>=arr[qmin[minr]])
			qmin[++minr] = i;
		else{
			while(arr[i]<arr[qmin[minr]] && minr >= minf)
				minr--;
			qmin[++minr] = i;
		}
		while( qmin[minf] < tmp )
			minf++;

		// here is the answer
		minlst[mint++] = arr[qmin[minf]];

		if(arr[i]<=arr[qmax[maxr]])
			qmax[++maxr] = i;
		else{
			while(arr[i] > arr[qmax[maxr]] && maxr >= maxf)
				maxr--;
			qmax[++maxr] = i;
		}
		while( qmax[maxf] < tmp )
			maxf++;
		maxlst[maxt++] = arr[qmax[maxf]];
	}

	printf("%d", minlst[0]);
	for(int i = 1;i < mint; i ++ )
        printf(" %d", minlst[i]);
    printf("\n");
    printf("%d",maxlst[0]);
    for(int i = 1;i < maxt; i ++ )
        printf(" %d", maxlst[i]);
    printf("\n");

	return 0;
}