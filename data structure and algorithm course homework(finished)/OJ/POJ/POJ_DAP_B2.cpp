// I'm a fucking genius!

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 500005

using namespace std;

struct Unit{
	long num;
	long id;
};
int C[MAXN];
Unit a[MAXN];
int f[MAXN];
long n;

// first declare the lowbit
long lowbit( long x ){
	return x & ( -x );
}
// then the sum and add ope
long sum( long x ){
	long ret = 0;
	while( x > 0 ){
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}
void add( long x , long v ){
	C[x] += v;
	while( x <= n ){
		x+=lowbit(x);
		C[x] += v;
	}
}
int cmp( const void * a, const void * b ){
	return (((Unit *)a)->num) - (((Unit *)b)->num);
}

using namespace std;

int main(){
	freopen( "data2.txt", "r", stdin );

	// get n and n != 0
	while( scanf("%ld", &n) == 1 && n ){

		long ans = 0;
		memset( C, 0 , sizeof( C ));

		for( int i = 1; i <= n; i ++ ){
			scanf( "%ld", &a[i].num );
			a[i].id = i;
		}

		qsort( a+1, n, sizeof(a[0]), cmp);

		for( int i = 1; i <= n; i ++ ){
			f[a[i].id] = i;
		}

		for(int i = n; i >= 1; i--){
            add( f[i],1 );
            ans += sum( f[i]-1 );
        }

        // ans is so large
        printf("%ld\n",ans);
	}

	return 0;
}