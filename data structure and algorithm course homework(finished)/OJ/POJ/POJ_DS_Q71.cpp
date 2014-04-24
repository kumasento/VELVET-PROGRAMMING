// So sleepy.....

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>

#define MAXS 10000
#define MAXN 10000


using namespace std;

// this is the graph
vector<int> G[MAXN];
int P[MAXN];

// set a new edge
void Insert( int u, int v ){
	if(P[v] == -1) P[v] = u;
	G[u].push_back(v);
	//G[v].push_back(u);
}

int main(){
	freopen( "data.txt", "r", stdin );

	int step = 0; // 0: simple 1: R 2: nothing 3: back to 0
	
	stack<int> layers;
	vector<string> names;
	int num = 0, layer = 0;
	char line[MAXS], tmp[MAXS];
	int lineSize = MAXS;
	memset( G, 0, sizeof(G) );
	memset( P, -1, sizeof(P) );
	layers.push(0);

	int in = 0, t;
	int countn = 0;
	

	while( 1 ){
		
		//cout << layer << endl;
		// read
		memset( line, 0, sizeof(line) );
		memset( tmp, 0, sizeof(tmp) );
		cin.getline( line, lineSize, '\n' );
		sscanf( line, "%s", tmp );

		// handle
		if(!in){	
			sscanf(tmp, "%d", &t);

			in = 1;
		}
		int len = strlen(tmp);
		if( len == 0 )
			step ++;
		else if( tmp[0] == '!' ){
			break;
		}

		//cout << step << endl;

		switch( step ){
			case 0:
			{
				if( tmp[0] == '{' ) {layers.push(num); layer = num;}
				else if( tmp[0] == '}' ) { layers.pop(); layer = layers.top();} 
				else{
					int x;
					char name[MAXS];
					sscanf( tmp, "%s", name );
					string nn = string(name);
					int i = 0;
					for( i = 0; i < names.size(); i ++ ){
						if( names[i] == nn )
							break;
					}
					if( i == names.size() ){
						names.push_back(nn);
						x = names.size()-1;
					}
					else 
						x = i;

					//cout << "x: " << x << "str: " <<  << endl;
					//cout << "layer: " << layer << ' ' << "x: " << x << endl;
					Insert( layer, x );
					num = x;
				}
				break;
			}
			case 1:
			{
				if( len != 0 ){
					int R;
					char name[MAXS];
					sscanf( tmp, "%s", name );
					string nn = string(name);
					int i;
					for(i = 0; i < names.size(); i ++ ){
						if(nn == names[i])
							break;
					}
					R = i;
					int fa = P[R];
					//cout << "R: " << R << " fa: " << fa << endl;
					//for( r = 0; r < G[0].)
					int ok = 0, sum = 0;
					if( fa != -1)
						for( int i = 0; i < G[fa].size(); i ++ ){
							if(ok) {
								printf( "%s", names[G[fa][i]].c_str());
								sum ++;
							}
							if(G[fa][i] == R) ok = 1;
						}
					else printf("No");
					putchar('\n');
				}
				break;
			}
			case 2:
				break;
			case 3:
			{	
				// clean up
				num = 0; 
				layer = 0;
				memset( G, 0, sizeof(G) );
				memset( P, -1, sizeof(P) );
				step = 0;

				countn ++;
				if( countn == t )
					in = 0;
				break;
			}
		}
	}

	return 0;
}
