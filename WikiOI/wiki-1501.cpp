#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>

#define MAX_LAYER 100

using namespace std;

typedef pair<int, int> node;
typedef map<int, node> binary;

int width[MAX_LAYER];

int search_height(binary tree, int index, int h){
	node now_node = tree[index];
	int hl = 0, hr = 0;
	width[h] ++;
	if(now_node.first != 0)
		hl = search_height(tree, now_node.first, h+1);
	if(now_node.second != 0)
		hr = search_height(tree, now_node.second, h+1);
	return max(max(hl, hr), h);
}

int main(){
	freopen("1501.in", "r", stdin);

	int n; cin>>n;
	binary tree;
	for(int i = 1; i <= n; i++){
		int l, r; cin>>l>>r;
		tree[i] = node(l,r);
	}	

	memset(width, 0, sizeof(width));
	
	int h = search_height(tree, 1, 0) + 1;
	int w = 0;
	for(int i = 0; i < MAX_LAYER; i++)
		if(width[i] > w)
			w = width[i];
	cout << w << " " << h << endl;
	return 0;
}