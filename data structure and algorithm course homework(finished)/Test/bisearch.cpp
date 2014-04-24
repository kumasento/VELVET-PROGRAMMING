#include<iostream>
#include<cstdlib>

using namespace std;

//interface: search in linear int array;
//failed: this is not bisearch. 
//bisearch is a kind of "find" algorithm, the value it returns is a boolean;
int _bisearch(int _a[],int _start, int _end, int _value);

int main(){
	int _a[10] = {1,3,2,4,7,9,23,44,13,55};
	int _pos = _bisearch(a, 0, 9, 23);

	return 0;
}
