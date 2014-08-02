#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int cnt;

void merge(string &str, int x, int y){
	int len = y-x;
	int mid = (x+y)>>1;
	if(len == 1) return ;
	if(len == 2){
		if(str[y-1]<str[x]){ swap(str[y-1],str[x]); cnt ++; }
		return ;
	}
	merge(str, x, mid);
	merge(str, mid, y);
	string t;
	int i = x, j = mid;
	while( i < mid && j < y ){
		if(str[i] <= str[j])
			t.push_back(str[i++]);
		else{
			t.push_back(str[j++]);
			cnt += (mid-i);
		}
	}
	while(i<mid){
		t.push_back(str[i++]);
	}
	while(j<y){
		t.push_back(str[j++]);
	}
	str.replace(x,len,t);
	return ;
}

int main(){
	freopen("data_102.txt", "r", stdin );
	int n, m; cin >> n >> m;
	multimap<int, string> Map;
	for( int i = 0; i < m; i ++ ){
		string str; cin >> str;
		cnt = 0;
		string tmp = str;
		merge(tmp, 0, tmp.length());
		pair<int,string> p(cnt, str);
		Map.insert(p);
	}
	multimap<int,string>::iterator i = Map.begin();
	while( i != Map.end() ){
		cout << i->first << endl;
		cout << i->second << endl;
		i++;
	}
	return 0;
}
