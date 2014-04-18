#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main(){
	freopen("data_LA2088.in", "r", stdin);
	string str; cin>>str;
	while(str != string("END")){
		map<char, int> mmap; 
		for(int i = 0; i < str.length(); i++)
			mmap[str[i]]++;
		
		cin>>str;
	}
	return 0;
}