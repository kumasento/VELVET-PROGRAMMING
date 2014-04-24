//Mayor's Poster

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 20010

using namespace std;

int P[MAXN];
struct Node{
	Node * ch[2];
	int a, b;
	int elem;
};

Node * null = new Node();
void Build( Node *& o, int a, int b ){
	o = new Node();
	o->a = a; o->b = b;
	o->ch[0] = o->ch[1] = null;
	o->elem = -1; // -1 means no poster here or it's not a complete poster
	if( a != b ){
		int mid = (a+b)/2;
		Build( o->ch[0], a, mid );
		Build( o->ch[1], mid+1, b );
	}
}
void Update( Node * &o, int a, int b, int i ){
	//cout << "---Update---" << endl;
	//cout << o->a << ' ' << o->b  << endl;
	//cout << a << ' ' << b << ' ' << i << endl;
	if( o->a == a && o->b == b ){
		//cout << "---in---" << endl;
		//cout << o->a << ' ' << o->b << endl;
		o->elem = i;
		return ;
	}

	int num = o->elem;

	o->elem = -1;
	
	int mid = (o->a + o->b)/2;
	if( a <= mid ){
		if( b <= mid ){
			Update( o->ch[0], a, b, i );
			if( num != -1 ){
				if( a != o->a )
					Update( o->ch[0], o->a, a, num );
				if( b != mid )
					Update( o->ch[0], b+1, mid, num );
				if( mid != o->b )
					Update( o->ch[1], mid+1, o->b, num );
			}
		}
		else{
			Update( o->ch[0], a, mid, i );
			Update( o->ch[1], mid+1, b, i );
			if( num != -1 ){
				if( a != o->a )
					Update( o->ch[0], o->a, a, num );
				if( b != o->b )
					Update( o->ch[1], b+1, o->b, num );
			}
		}
	}
	else{
		Update( o->ch[1], a, b, i );	
		if( num != -1 ){
			Update( o->ch[0], o->a, mid, num );
			if( a != mid+1 )
				Update( o->ch[1], mid+1, a, num );
			if( b != o->b )
				Update( o->ch[1], b+1, o->b, num );
		}
	}

}
void Print( Node * o ){
	if( o == null ) return ;
	cout << o->a << ' ' << o->b << ' ' << o->elem << endl;
	Print( o->ch[0] );
	Print( o->ch[1] );
}

int Query( Node * o, int i ){
	if( o == null )
		return 0; 
	if( o->elem == i )
		return 1;
	return Query( o->ch[0], i ) || Query( o->ch[1], i );
}

int main(){
	freopen( "data2.txt", "r", stdin );

	int t; cin >> t;
	while( t ){
		int n; cin >> n;
		memset( P, 0, sizeof(P) );
		
		int Itv[n][2];
		for( int i = 0; i < n; i ++ ){
			cin >> Itv[i][0] >> Itv[i][1];
			P[i*2] = Itv[i][0];
			P[i*2+1] = Itv[i][1];
		}
		int len = 

		Node * root  = new Node();
		Build( root, a, b );

		for( int i = 0; i < n; i ++ ){
			Update( root, Itv[i][0], Itv[i][1], i );
			//cout << "---Print---" << endl;
			//Print( root );

		}
		int sum = 0;
		for( int i = 0; i < n; i ++ ){
			if( Query( root, i ))
				sum ++;
		}
		cout << sum << endl;
		t--;
	}
	return 0;
}