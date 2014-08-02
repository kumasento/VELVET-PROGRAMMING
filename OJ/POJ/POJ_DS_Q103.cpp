#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<string, int> Map;
map<char, char> Alp;

int main(){
	freopen("data_103.txt","r",stdin);
	Alp['A']=Alp['B']=Alp['C']=Alp['2']='2';
	Alp['D']=Alp['E']=Alp['F']=Alp['3']='3';
	Alp['G']=Alp['H']=Alp['I']=Alp['4']='4';
	Alp['J']=Alp['K']=Alp['L']=Alp['5']='5';
	Alp['M']=Alp['N']=Alp['O']=Alp['6']='6';
	Alp['P']=Alp['R']=Alp['S']=Alp['7']='7';
	Alp['T']=Alp['U']=Alp['V']=Alp['8']='8';
	Alp['W']=Alp['X']=Alp['Y']=Alp['9']='9';
	Alp['0']='0'; Alp['1']='1';
	int n; cin >> n;
	for( int i = 0; i < n; i++ ){
		string st,a; cin >> st;
		for( int j = 0; j < st.length(); j++ )
			if(st[j] != '-')
				a.push_back(Alp[st[j]]);
		//cout << a << endl;
		Map[a] ++;
	}
	map<string,int>::iterator i = Map.begin();
	int cnt = 0;
	while( i != Map.end() ){
		if( i->second != 1 ){
			string t = i->first;
			cout << t.substr(0,3)<<'-'<<t.substr(3,4)<<' ';
			cout << i->second << endl;
			cnt++;
		}
		i++;
	}
	if(!cnt)
		cout << "No duplicates." << endl;
	return 0;
}