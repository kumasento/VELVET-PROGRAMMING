
#define MAXN 100

int wa[MAXN], ws[MAXN];

void da( int *r, int *sa, int n, int m){
	int i, *x=wa;
	for( i = 0; i < m; i++ ) ws[i] ++;
	for( i = 0; i < n; i++ ) ws[x[i] = r[i]] ++;
	for( i = 1; i < m; i++ ) ws[i] += ws[i-1];
	for( i = n-1; i >= 0; i-- ) sa[--wa[x[i]]] = i;

}
