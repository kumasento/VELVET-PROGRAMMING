#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string high_precise_subtraction(string n1, string n2){
	/*
	 *	Here are some rules:
	 *	1. need to set the big one in n1 and small one in n2
	 *	2. when the digit of n1 is smaller than the digit in n2, add n1 10 and 
	 *	substract 1 from n1 + 1
	 */
	 string str; int l = n1.length();
	 int idx = 0, g = 0;
	 while(g || idx < l){
	 	int p1 = n1[idx]-'0';
	 	int p2 = n2[idx]-'0';
	 	//cout << p1 << ' ' << p2 << endl;
	 	int ans = p1 - p2;
	 	if(ans < 0) { ans += 10; n1[idx+1] --; }
	 	str.push_back(ans % 10 + '0');
	 	g = ans / 10;
	 	//cout << str[idx] << endl;
	 	idx ++;
	 }
	 reverse(str.begin(), str.end());
	 int start = 0;
	 for(int i = 0; i < str.length(); i++){
	 	if(str[i] == '0') start++;
	 	else break;
	 }
	 str = str.substr(start, str.length()-start);
	 return str;
}

int main(){
	freopen("3115.in", "r", stdin);
	string n1, n2; cin>>n1>>n2;
	int length = max(n1.length(), n2.length());
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	while(n1.length() < length) n1.push_back('0');
	while(n2.length() < length) n2.push_back('0');
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	int sig = 0;
	if(n1 < n2) { swap(n1, n2); sig = 1; }
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	//cout << n1 << ' ' << n2 << endl;
	string ans = high_precise_subtraction(n1, n2);
	if(sig) ans.insert(ans.begin(), '-');
	cout << ans << endl;
	return 0;
}