//Ceasar Code
//Julius You Are Great!!!!!!!

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main(){
	string INPUT; getline(cin,INPUT);
	while(INPUT != "ENDOFINPUT"){
		getline(cin,INPUT);//COMMAND

		for(int i = 0; i < INPUT.length(); i++){
			int bias = INPUT[i]-'A';
			if(bias >= 0 && bias <= 25){
				if(bias - 5 >= 0) printf("%c",INPUT[i]-5);
				else printf("%c", INPUT[i]-5+26);
			}
			else printf("%c", INPUT[i]);
		}
		cout<<endl;

		getline(cin,INPUT);//END 
		getline(cin,INPUT);//START OR ENDOFINPUT 
	}
	return 0;
}
