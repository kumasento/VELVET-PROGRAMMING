#include <iostream>
#include <algorithm>

#define N 100

using namespace std;

int a[100] = { 1, 2, 8, 7, 9, 5, 6, 4, 3, 66, 77, 33, 22, 11 };

void quicksort(int l, int r){
	if( l >= r ) return;
	int key = a[l];

	int i = l+1, j = r;
	while(1){
		while( a[j] > key ) j--;
		while( (a[i]<key) && (i<j) ) i++;
		if( i>=j ) break;
		swap(a[i],a[j]);
		if(a[i] == key) j--;
		else i++;
	}

	swap(a[l], a[j]);
	if(l < i-1) quicksort(l, i-1);
	if(r > j+1) quicksort(j+1, r);

	return ;
}

int main(){
	quicksort(0,13);
	int i = 0;
	for(; i < N; i++)
		cout << a[i] << ' ';

	cout << endl;

	return 0;
}
