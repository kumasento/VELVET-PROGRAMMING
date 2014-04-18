#include <stdio.h>

#define N 10

int main(){
	int a[N] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int noswap = 0;
	while( !noswap ){
		noswap = 1;
		int i;
		for( i = 1 ; i < N ; i ++ ){
			if( a[i] > a[i-1] ){
				int temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;

				noswap = 0;
			}
		}
	}
	int i;
	for( i = 0; i < N; i++ )
		printf("%d ", a[i] );
	puts("");

	return 0;

}
