#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int main(){
	//freopen("CF224Ad.in", "r", stdin);
	int cl, cr; cl = cr = 0;
	string Scale; cin >> Scale;
	int inl = 1; 
	for(int i = 0; i < Scale.length(); i++){
		if(inl && Scale[i] == '|') inl = 0;
		else if (inl) cl++;
		else cr++;
	}
	string Str; cin >> Str;
	int cnt = Str.length();
	int d = abs(cl-cr);
	
 	if(cnt < d) cout << "Impossible" << endl;
	else if(cnt == d){
		if(cl < cr) Scale = Str + Scale;
		else Scale = Scale + Str;
		cout << Scale << endl;
	}
	else {
		if((cnt-d)%2) cout << "Impossible" << endl;
		else{
			if(cl < cr) Scale = Str.substr(0, d)+Scale;
			else Scale = Scale + Str.substr(0, d);
			int t = (cnt-d)/2;
			Scale = Str.substr(d, t) + Scale;
			Scale = Scale + Str.substr(d+t, t);
			cout << Scale << endl;
		}
	}
	return 0;
}