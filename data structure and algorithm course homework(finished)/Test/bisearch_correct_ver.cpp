#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int _bisearch(int seq[], int _start, int _end, int _value){
	int _mid = (_start + _end) / 2;
	while(_start <= _end){
		_mid = (_start + _end) / 2;
		if(seq[_mid] > _value) _end = _mid - 1;
		else if( seq[_mid] < _value) _start = _mid + 1;
		else return _mid;
	}
	return -1;
}	

int cmp(const void *p1, const void *p2){
	return *(int *)p1 - *(int *)p2;
}

int main(){
	int seq[6] = { 1, -9, 7, 14, -24, 4};
	qsort(seq, 6, sizeof(int), cmp);
	cout <<_bisearch(seq,0,6,7)<<endl;

	return 0;
}
