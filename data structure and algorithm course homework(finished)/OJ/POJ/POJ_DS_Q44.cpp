#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int next[1000100];

int * get_next( const char * str){
	int j, k;

	int len = strlen( str );
	// now start
	next[0] = -1; // only the start is -1 
	j = 0; k = -1;
	while( j < len - 1 ){ // j add first 
		while( k >= 0 && str[k] != str[j] ) // why next[0] = -1 ? to be an end mark
			k = next[k]; 
		j ++; k ++;
		next[j] = k;
	}
	
	//for(int i = 0; i <len; i++ ) cout << next[i] <<' ';
	//cout << endl;
}

int main(){
	int Case = 0;
	int N; cin >> N;
	while(N){
		Case++;
		printf("Test case #%d\n", Case);
		
		string S; cin>>S;
	
		memset( next, 0, sizeof( next ) );
		get_next( S.c_str() );
		for( int i = 1; i <= N; i++ ){
			// i is the length of test prefix

			int bias = i - next[i];
			if( i % bias == 0 && i/bias > 1 ){
				cout << i << ' ' << i/bias << endl;
			}
		}

		cout << endl;
		cin>>N;
	}
	return 0;
}
