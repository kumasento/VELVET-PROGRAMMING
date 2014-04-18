#include <stdio.h>
#define N 10

int main(){
	int a[N] = { 13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10 };

	int gap = 0;
	while( gap < N )
		gap = gap*3+1;
	while( gap > 0 ){
		int i , j;
		for( i = gap; i < N; i ++ ){
			int num = a[i];
			j = i-gap;
			while( (j>=0) && (a[j]>num) ){
				a[j+gap] = a[j];
				j = j-gap;
			}
			a[j+gap] = num;
		}
		gap--;
	}

	int i = 0;
	for( i = 0; i < N; i++ ){
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}
