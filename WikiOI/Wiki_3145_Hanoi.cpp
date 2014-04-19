#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int cnt = 0;
void move(int n, int a, int b, int c){
	if(n == 1){
		printf("%d from %c to %c\n", n, a, c);
	}
	else{
		move(n-1, a, c, b);
		printf("%d from %c to %c\n", n, a, c);
		move(n-1, b, a, c);
	}
}
void move1(int n, int a, int b, int c){
	if(n == 1){
		//printf("%d from %c to %c\n", n, a, c);
		cnt ++;
	}
	else{
		move1(n-1, a, c, b);
		//printf("%d from %c to %c\n", n, a, c);
		cnt ++;
		move1(n-1, b, a, c);
	}
}

int main(){
	freopen("3145.in", "r", stdin);
	int n; cin>>n;
	move1(n, 'A', 'B', 'C');
	cout << cnt << endl;
	move(n, 'A', 'B', 'C');
	return 0;
}