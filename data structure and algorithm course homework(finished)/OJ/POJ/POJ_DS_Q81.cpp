#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <queue>

#define MAXN 300
#define INF 10000000

using namespace std;

int n, m;
int s, vv;
int Next[MAXN+1]; // get the Next edge's number
int First[MAXN+1]; // get the First edge

int u[MAXN+1];
int v[MAXN+1];
int w[MAXN+1];
int d[MAXN+1];
int fa[MAXN+1];

typedef pair<int, int> pii;
vector<string> NTS(MAXN);
map< string, int > STN; 

void Print( int x ){
	if( x == 0 )
		return;
	Print( fa[x] );
	if( fa[x] != 0 ){
		for( int e = First[fa[x]]; e != 0 ; e = Next[e] ){
			if( v[e] == x ){
				cout << '(' << w[e] << ')' << "->";
			}
		}
	}
	cout << NTS[x];
	if( x != vv ){
		cout << "->";
	}

}

int main(){
	freopen( "data2.txt", "r", stdin );

	int P; cin >> P;
	
	for( int i = 1; i <= P; i ++){
		cin >> NTS[i] ;
		STN.insert( pair<string,int>(NTS[i], i));
	}

	memset( First, 0, sizeof( First ) );
	int Q; cin >> Q;
	for( int i = 1; i <= Q; i ++ ){
		string s1, s2; cin >> s1 >> s2;
		
		u[i] = STN[s1]; v[i] = STN[s2]; 
		u[i+Q] = STN[s2]; v[i+Q] = STN[s1];
		
		Next[i] = First[u[i]]; First[u[i]] = i;
		Next[i+Q] = First[v[i]]; First[v[i]] = i+Q;
		
		cin >> w[i]; 
		w[i+Q] = w[i];
	}

	int R; cin >> R;
	for( int j = 1; j <= R; j ++ ){
		string S, V;
		cin >> S >> V;
		s = STN[S]; vv = STN[V];
		
		d[s] = 0; fa[s] = 0;
		for( int i = 1; i <= P; i ++ ){
			if( i != s ){
				d[i] = INF;
				fa[i] = 0;
			}
		}

		priority_queue< pii, vector<pii>, greater<pii> > q;
		bool done[MAXN+1];
		memset( done, false, sizeof(done) );
		q.push(make_pair(d[s], s));

		while( !q.empty() ){
			pii uu = q.top(); q.pop();
			int x = uu.second;
			if( done[x] ) continue;
			if( x == vv ){
				break;
			}
			done[x] = true;
			for( int e = First[x]; e != 0; e = Next[e] ){
				if(d[v[e]] > d[x] + w[e]){
					d[v[e]] = d[x] + w[e];
					fa[v[e]] = x;
					q.push(make_pair(d[v[e]] , v[e]));
				}
			}
		}
		Print(vv);
		cout << endl;

	}
	return 0;

}