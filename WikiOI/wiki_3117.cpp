#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string high_precise_add(string n1, string n2){
	int l1 = n1.length(), l2 = n2.length();
	int g = 0; int idx = 0;
	string str;
	while(g || idx < l1 || idx < l2){
		int p1, p2; p1 = p2 = 0;
		if(idx < l1) p1 = n1[idx] - '0';
		if(idx < l2) p2 = n2[idx] - '0';
		int ans = p1 + p2 + g;
		int digit = ans % 10;
		g = ans / 10;
		str.push_back(digit + '0');
		idx ++;
	}

	reverse(str.begin(), str.end());
	return str;
}
string high_precise_multi(string n1, string n2){
	//pre-execute
	if(n1.length() < n2.length()) swap(n1, n2);
	string ans; ans.push_back('0');
	int idx = 0; 
	while(idx < n2.length()){
		string tmp; 
		int p2 = n2[idx] - '0';
		int g = 0; int i = 0;
		for(int t = 0; t < idx; t++)
			tmp.push_back('0');
		while( g || i < n1.length() ){
			int p1 = 0;
			if(i < n1.length()) p1 = n1[i] - '0';
			int ans = p1 * p2 + g;
			int digit = ans % 10;
			g = ans / 10;
			tmp.push_back(digit + '0');
			i++;
		}
		
		//cout << tmp << endl;
		ans = high_precise_add(tmp,ans);
		reverse(ans.begin(), ans.end());
		idx ++;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	freopen("3117.in", "r", stdin);
	string n1, n2; cin>>n1>>n2;
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	cout << high_precise_multi(n1, n2) << endl;
	return 0;
}