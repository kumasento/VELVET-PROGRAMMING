#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("data_js01.in","r",stdin);
	string in; cin>>in;
	vector<string> sd; sd.clear();
	while(in[0]!='#'){ sd.push_back(in); cin>>in; }
	cin>>in;
	while(in[0]!='#'){
		vector<string> ls; ls.clear(); bool po = true;
		for(int i = 0; i < sd.size() && po; i++){
			if(sd[i] == in) { 
				printf("%s is correct\n", in.c_str()); 
				po = false;
			}
			if(sd[i].length() == in.length()){
				int cnt = 0;
				for(int j = 0; j < in.length(); j++)
					if(sd[i][j] == in[j])
						cnt++;
				if(cnt == sd[i].length()-1)
					ls.push_back(sd[i]);
			}
			else if(sd[i].length() == in.length()+1){
				for(int d = 0; d < sd[i].length(); d++){
					int ok = true;
					for(int j = 0; j < in.length() && ok; j++){
						int sd_j = (j>=d) ? j+1 : j;
						if(sd[i][sd_j] != in[j])
							ok = false;
					}
					if(ok) { ls.push_back(sd[i]); break; }
				}
			}
			else if(sd[i].length() == in.length()-1){
				for(int d = 0; d < in.length(); d++){
					int ok = true;
					for(int j = 0; j < sd[i].length() && ok; j++){
						int i_j = (j>=d) ? j+1 : j;
						if(sd[i][j] != in[i_j])
							ok = false;
					}
					if(ok) { ls.push_back(sd[i]); break; }
				}
			}
		}	
		if(po){
			printf("%s:", in.c_str());
			for(int i = 0; i < ls.size(); i++)
				printf(" %s", ls[i].c_str());
			printf("\n");
		}
		cin>>in;
	}

	return 0;
}