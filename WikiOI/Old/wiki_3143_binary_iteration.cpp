#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cstdio>

using namespace std;

typedef pair<int, int> node;
typedef map<int, node> binary;

void frontIter(binary tree, int index){
	if(index == 0) return;
	frontIter(tree, tree[index].first);
	frontIter(tree, tree[index].second);
	cout << index << ' ';
	return;
}
void MiddleIter(binary tree, int index){
	if(index == 0) return;
	MiddleIter(tree, tree[index].first);
	cout << index << ' ';
	MiddleIter(tree, tree[index].second);
	return;
}
void BackIter(binary tree, int index){
	if(index == 0) return;
	cout << index << ' ';
	BackIter(tree, tree[index].first);
	BackIter(tree, tree[index].second);
	return;
}


int main(){
	freopen("3143.in", "r", stdin);
	int n; cin>>n;
	binary tree;
	for(int i = 1; i <= n; i++){
		int l, r; cin>>l>>r;
		tree[i] = node(l,r);
	}

	BackIter(tree, 1);
	cout << endl;
	MiddleIter(tree, 1);
	cout << endl;
	frontIter(tree, 1);
	cout << endl;

	return 0;
}