#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 100001

using namespace std;

struct Node{
	int a, b;
	int *data;
	Node *ch[2];
};

Node *null = new Node();

void Build( Node * &o, int a, int b, int * A ){
	o = new Node();
	o->ch[0] = o->ch[1] = null;
	o->a = a; o->b = b;
	o->data = (int *) malloc(sizeof(int)*(b-a+2));
	memset( o->data, 0 , sizeof(int)*(b-a+2));

	int len = b-a+1;
	
	if( len == 1 ){
		o->data = (int *) malloc(sizeof(int) * 2);
		o->data[1] = A[a];
		return ;
	}	

	int mid = a+( b-a )/2;

	Build( o->ch[0], a, mid, A );
	Build( o->ch[1], mid+1, b, A );
	
	int l1 = mid - a + 1, l2 = b - mid ;
	int i1 = 1, i2 = 1;
	
	int i = 1;
	while( i1 <= l1 && i2 <= l2 ){
		int v1 = o->ch[0]->data[i1], v2 = o->ch[1]->data[i2];
		if( v1 < v2 )
			o->data[i++] = o->ch[0]->data[i1++];
		else
			o->data[i++] = o->ch[1]->data[i2++];			
	}
	while( i1 <= l1 )
		o->data[i++] = o->ch[0]->data[i1++];
	while( i2 <= l2 )
		o->data[i++] = o->ch[1]->data[i2++];
}

int Query( Node * o, int x, int y, int num ){ // calculate the number less than 'num' in this field
	if( o == null ) return 0;
	if( o->a > y || o->b < x ) return 0;
	if( o->a >= x && o->b <= y ){
		int sum = 0;
		for( int i = 1; i <= (o->b - o->a + 1); i ++ ){
			if( o->data[i] >= num )
				break;
			sum ++;
		}
		//cout << "sum : "<<sum <<endl;
		return sum;
	}
	else{
		int ld = Query( o->ch[0], x, y, num );
		int rd = Query( o->ch[1], x, y, num );
		return ld + rd;
	}	
}

void Print(Node * o){
	if( o == null ) return;
	for( int i = 1; i <= (o->b-o->a+1); i++ ){
		cout << o->data[i] <<' ';
	}
	cout << endl;
	Print( o->ch[0] );
	Print( o->ch[1] );
	return ;
}

int cmp( const void * a, const void * b ){
	return *(int *) a - *(int *) b;
}

int main(){
	freopen( "data2.txt", "r", stdin );
	int n, m;
	scanf( "%d%d", &n, &m );
	int A[n]; 
	memset( A, 0, sizeof(A) );
	
	for( int i = 1; i <= n; i ++ )
		scanf("%d", &A[i]);

	// build tree
	Node * root = null;
	Build( root, 1, n, A );
	//Print( root );
	//cout << endl;
	qsort( A+1, n, sizeof(int), cmp );

	while( m ){
		int x, y, k;
		scanf( "%d%d%d", &x, &y, &k );
		int a1 = 0, a2 = n+1;
		while( a2 != a1 + 1 ){
			int mid = a1 + ((a2-a1)>>1);
			//cout <<"mid:"<< mid << endl;
			int c = Query( root, x, y, A[mid] );
			//cout << "c:"<< c << endl;
			if( c >= k ) 
				a2 = mid;
			else if ( c < k ) 
				a1 = mid;
		}
		printf("%d\n", A[a1]);

		m--;
	}

	return 0;
}