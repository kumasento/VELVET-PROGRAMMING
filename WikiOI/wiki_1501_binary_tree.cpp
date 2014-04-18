#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> node;
map<int, node> binary_tree;

int l_ptr, r_ptr;
int depth;
void search_binary_tree(int nid){
	node n = binary_tree[nid];
	
}

int main(){
	freopen("1501.in", "r", stdin);
	int n; cin>>n;
	for(int i = 1; i <= n; i++){
		int l, r; cin >> l >> r;
		binary_tree[i] = node(l, r);
	}


	return 0;
}