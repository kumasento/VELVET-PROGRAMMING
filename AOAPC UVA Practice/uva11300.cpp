#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int64;

int main(){
	freopen("11300.in", "r", stdin);

	int n;
	while( cin>>n ){
		int64 seq[n]; 
		for(int i = 0; i < n; i++)
			scanf("%lld", &seq[i]);
		sort(seq, seq + n);

		int64 mid;
		if( n % 2 == 0 )
			mid = (seq[(int)n / 2] + seq[(int)n / 2 - 1]) / 2;
		else 
			mid = seq[(n-1)/2];
		cout << mid << endl;

		int64 sum = 0;
		for(int i = 0; i < n; i++)
			sum += ( seq[i] - mid > 0 ) ? (seq[i] - mid) : (mid - seq[i]);

		cout << sum << endl;
	}	

	return 0;
}