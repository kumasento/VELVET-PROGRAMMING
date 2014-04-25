#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>

#define MAXN 1010

using namespace std;

int main(){
	//freopen("Q2.in", "r", stdin);
	int n, s; scanf("%d%d", &n, &s);

	map<int, int> rmap;

	for(int i = 0; i < n; i++){
		int x, y, s0; scanf("%d%d%d", &x, &y, &s0);
		int rs = x*x + y*y;
		rmap[rs] += s0;
	}

	map<int, int>::iterator rmap_iter = rmap.begin();
	while(rmap_iter != rmap.end()){
		s += rmap_iter->second;
		if(s >= 1000000)
			break;
		rmap_iter ++;
	}
	if(rmap_iter == rmap.end())
		cout << -1 << endl;
	else 
		printf("%.7f\n", sqrt((double) rmap_iter->first));

	return 0;
}