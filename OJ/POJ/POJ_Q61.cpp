#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>

#define MAXN 600
#define MAXL 2000

using namespace std;

int N, a[MAXN][MAXN], num[MAXL]; 
int ii;
struct node{
	int info[3];
	struct node *ch[4];
};
void buildtree(node *tree, int x, int y, int l){
	if(l == 1){
		tree->info[0]=1;
		tree->info[1]=a[x][y];
		tree->info[2]=1;
		return;
	}

	int tmp = a[x][y], ok=1;
	for(int tx=x; tx<x+l && ok; tx++)
		for(int ty=y; ty<y+l && ok; ty++)
			if(a[tx][ty]!=tmp)
				ok = 0;
	if(ok){
		tree->info[0]=1;
		tree->info[1]=tmp;
		tree->info[2]=1;
		return ;
	}

	for(int t=0; t<4; t++)
		tree->ch[t]=new node();
	tree->info[0]=0;
	tree->info[2]=1;

	buildtree(tree->ch[0],x,y,l/2);
	buildtree(tree->ch[1],x,y+l/2,l/2);
	buildtree(tree->ch[2],x+l/2,y,l/2);
	buildtree(tree->ch[3],x+l/2,y+l/2,l/2);
	return;
}
void printtree(node* tree){
	//bfs
	queue<node*> q;
	q.push(tree);
	while( !q.empty() ){
		node *t = q.front(); q.pop();
		if(t->info[0]){ num[ii++]=0; num[ii++]=t->info[1]; }
		else{
			num[ii++] = 1;
			for(int k=0; k<4; k++)
				q.push(t->ch[k]);
		}
	}
	return ;
}

int main(){
	freopen("data_q61.in","r",stdin);
	int k; cin>>k;
	while( k-- ){
		memset(a, 0, sizeof(a)); 
		cin>>N;
		for(int x=0; x<N; x++)
			for(int y=0; y<N; y++)
				cin>>a[x][y];
		node* tree = new node();
		buildtree(tree,0,0,N);
		ii = 0;
		memset(num,0,sizeof(num));
		printtree(tree);
		
		int c=0, cnt=0, ans[MAXL], w = 0;
		memset(ans,0,sizeof(ans));
		for(int i=0; i<ii; i++){
		 	cnt+=num[ii-i-1]*pow(2,c);
		 	c++;
		 	if(c==4){ c = 0; ans[w++]=cnt; cnt = 0; }
		}
		if(c!=0)
			ans[w++]=cnt;
		for(int i=0; i<w; i++){
			int t = ans[w-i-1];
			if( t>=0 && t<=9 )
				cout << t;
			else{
				char ch;
				switch(t){
					case 10:
					ch='A';
					break;
					case 11:
					ch='B';
					break;
					case 12:
					ch='C';
					break;
					case 13:
					ch='D';
					break;
					case 14:
					ch='E';
					break;
					case 15:
					ch='F';
					break;
				}
				cout<<ch;
			}
		}
		cout << endl;
	}

	return 0; 
}