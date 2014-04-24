#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(){
	int t; cin>>t;
	while(t > 0){
		int n; cin>>n;
		int Linear[1500];
		memset(Linear, 0, sizeof(Linear));
		int front, rear, top; 
		front = 0;
		rear = top = -1;

		int isStack = -1;
		while(n > 0){
			int type, val;
			cin>>type>>val;
			if(type == 1){
				rear ++;
				top ++;
				Linear[rear] = val;
			}
			else if(type == 2 && isStack == -1){
				if(Linear[top] != val) { isStack = 0;}
				else if(Linear[front] != val){ isStack = 1;}
				else{ top --; front ++; }
			}
			n--;
		}
		if(isStack) cout<<"Stack"<<endl;
		else cout<<"Queue"<<endl;
		t--;
	}

	return 0;
}
