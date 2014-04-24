#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

const int ranklist[6] = {1, 0, -1, 0, -1, 1};

int cal(int a, int b, char opr){
	switch(opr){
	case '+':
		return a+b;
	case '-':
		return b-a;
	case '*':
		return a*b;
	case '/':
		return b/a;
	}
};

int main(){
	int N; cin>>N;
	while(N != 0){
		char Str[600]; cin>>Str;
		char OprStack[600];
		int SuffixStack[600]; 
		int top_opr = -1, top_suf = -1;
		memset(OprStack, 0, sizeof(OprStack));
		memset(SuffixStack, 0, sizeof(SuffixStack));
		
		int IntStack[20];
		memset(IntStack, 0, sizeof(IntStack));
		int top_int = -1;

		for(int i = 0; i < strlen(Str); i++){
			/*
			cout<<"OprStack"<<endl;
			for(int j = 0; j <= top_opr; j++) cout<<OprStack[j]<<' ';
			cout<<endl;
			cout<<"SuffixStack"<<endl;
			for(int j = 0; j <= top_suf; j++) cout<<SuffixStack[j]<<' ';
			cout<<endl;
			*/
			char getc = Str[i];
			int getn = Str[i] - '0';
			if(getn >= 0 && getn <= 9){
				IntStack[++top_int] = getn;
				if((i == (strlen(Str)-1)) || ((i < (strlen(Str) - 1)) && (((Str[i+1] - '0') < 0) || ((Str[i+1] - '0') > 9)))){ 
					int index = 1;
					int Int = 0;
					while(top_int != -1){
						Int += IntStack[top_int--]*index;
						index *= 10;
					}
					SuffixStack[++top_suf] = Int;
				}
			}
			else{
				if(getc == ')'){
					while(OprStack[top_opr] != '('){
						char opr = OprStack[top_opr--];
						int a = SuffixStack[top_suf--];
						int b = SuffixStack[top_suf--];

						int ret = cal(a, b, opr);
						SuffixStack[++top_suf] = ret;
					}
					top_opr --;
				}
				else {
					int rankopr = (getc == '(') ? 2 : ranklist[getc-'*'];
					while(top_opr != -1 && OprStack[top_opr] != '(' && ranklist[OprStack[top_opr]-'*'] >= rankopr){
						char opr = OprStack[top_opr--];
						int a = SuffixStack[top_suf--];
						int b = SuffixStack[top_suf--];

						int ret = cal(a, b, opr);
						SuffixStack[++top_suf] = ret;
					}
					OprStack[++top_opr] = getc; 
				}
			}
		}

		while(top_opr != -1){
			char opr = OprStack[top_opr--];
			int a = SuffixStack[top_suf--];
			int b = SuffixStack[top_suf--];
	
			int ret = cal(a, b, opr);
			SuffixStack[++top_suf] = ret;			
		}
		cout<<SuffixStack[0]<<endl;

		N--;
	}

	return 0;
}
