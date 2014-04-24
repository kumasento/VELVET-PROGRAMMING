#include<iostream>
#include<cstring>

#define MAX_NUM 2200

using namespace std;

int main(){
	int t; cin>>t;
	while(t > 0){
		int chart[MAX_NUM]; memset(chart, 0, sizeof(chart));
		int front, rear; front = rear = 0;
		int n; cin>>n;
		int sum_queue_like, sum_stack_like; 
		sum_queue_like = sum_stack_like = 0;
		while(n > 0){
			int type, val; cin>>type>>val;
			if(type==1){ chart[rear++] = val; }
			else if(type==2){
				
			}
			n--;
		}
		t--;
	}
}
