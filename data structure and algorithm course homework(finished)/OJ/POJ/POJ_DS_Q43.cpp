#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

int Tint[110]; 
int Tchar[26]; 
int Dchar[26];
string S, D;

int TestMatch(int len, int s){
	if(s == len) return 1;
	int ok = 0;
	for(int i = 0; i < len; i++){
		if(Tint[i] == -1){ //if i doesnt have it's origin
			Tint[i] = s; // make s as i's origin
			int S_char = S[s]-'A', D_char = D[i]-'A';
			if(Tchar[S_char] == -1){
				if(!Dchar[D_char]){
					Tchar[S_char] = D_char;
					ok = TestMatch(len, s+1);
					Tchar[S_char] = -1;
				}
			}
			else if(Tchar[S_char] == D_char){
				ok = TestMatch(len, s+1);
			}
			Tint[i] = -1;
			if(ok) return 1;
		}	
	}
	return 0;
}

int main(){
	cin >> D >> S;
	
	int len = D.length();
	int ok = 0;
	memset(Tint, -1, sizeof(Tint));
	memset(Tchar, -1, sizeof(Tchar));
	memset(Dchar, 0, sizeof(Dchar));
	cout<<((TestMatch(len, 0)) ? "YES" : "NO");
	return 0;
}
