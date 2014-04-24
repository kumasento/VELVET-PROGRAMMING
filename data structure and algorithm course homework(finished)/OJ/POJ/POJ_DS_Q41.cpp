#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
int main(){
	int N; cin>>N;
	while(N != 0){
		char a[1500]; cin>>a;
		int num[26]; memset(num, 0, sizeof(num));
		
		int MAX_NUM = 1;
		char MAX_CHAR = a[0];
		for(int i = 0; i < strlen(a); i++){
			num[a[i]-'a']++;
			if(num[a[i]-'a']>MAX_NUM){
				MAX_NUM = num[a[i]-'a'];
				MAX_CHAR = a[i];
			}
			else if(num[a[i]-'a'] == MAX_NUM){
				if((MAX_CHAR-'a') > (a[i]-'a'))
					MAX_CHAR = a[i];
			}
		}	
		cout<<MAX_CHAR<<' '<<MAX_NUM<<endl;

		N--;
	}
	return 0;
}
