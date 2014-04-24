#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main(){
	string dst, src;
	cin >> dst >> src;

	sort(dst.begin(), dst.end()); 
	sort(src.begin(), src.end());
	
	int cal[2][26];
	memset(cal, 0, sizeof(cal));
	for(int i = 0; i < dst.length(); i++){
		cal[0][dst[i]-'A']++;
		cal[1][src[i]-'A']++;
	}

	sort(cal[0], cal[0]+26);
	sort(cal[1], cal[1]+26);

	int ok = 1;
	for(int i = 0; i < 26; i++){
		if(cal[0][i] > cal[1][i])
			ok = 0;
	}

	cout << ((ok) ? "YES" : "NO");
	return 0;
}
