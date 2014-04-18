#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
	freopen("square_detector.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int T, N; cin >> T;
	for( int i = 1; i <= T; i ++ ){
		int N; cin >> N;
		int a[N][N]; memset( a, 0, sizeof(a) );
		for( int x = 0; x < N; x++ ){
			for( int y = 0; y < N; y++ ){
				char ch; cin >> ch;
				if(ch == '#') a[x][y] = 1;
				else if(ch == '.') a[x][y] = 0;
			}
		}

		int OK = 1, IS = 0, DONE = 0;
		int Y = -1;
		int LEN = -1, HEIGHT = 0;
		for( int x = 0; x < N && OK; x++ ){
			IS = 0; DONE = 0;
			int SUM = 0; 
			for( int y = 0; y < N; y++ ){
				if(DONE){
					if(a[x][y] == 1){ OK = 0; break; }
					
				}
				else if(!IS){
					if(a[x][y] == 1){
						if(Y == -1)// no top point
							Y = y;
						else{
							if(y != Y){ OK = 0; break; }
						}
						IS = 1;
						SUM ++;
					}
				}
				else{
					if(a[x][y] == 1) SUM ++;
					else DONE = 1;
				}
				//printf("(%d,%d): IS: %d, DONE: %d, SUM: %d, LEN: %d, OK: %d\n",
				//	x,y,IS,DONE,SUM,LEN,OK);
			}
			
			if(SUM != 0){
				if(LEN == -1) {
					LEN = SUM; 
				 	HEIGHT ++; 
				}
				else if(LEN != SUM) { OK = 0; break; }
				else HEIGHT ++;
			}
		}
		if( HEIGHT != LEN )
			OK = 0;
		printf("Case #%d: %s\n", i, (OK) ? "YES" : "NO");
	}

	return 0;

}
