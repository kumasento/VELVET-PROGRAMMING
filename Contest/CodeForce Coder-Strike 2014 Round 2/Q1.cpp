#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main(){
	//freopen("Q1.in", "r", stdin);
	int n, m, min, max; 
	cin>>n>>m>>min>>max;
	
	int tmp_min, tmp_max; tmp_min = 220; tmp_max = -1;
	for(int i = 0; i < m; i++){
		int tmp_val; cin>>tmp_val;
		if(tmp_val > tmp_max) tmp_max = tmp_val;
		if(tmp_val < tmp_min) tmp_min = tmp_val;
	}
	int cnt = 0;
	if(tmp_min != min) cnt ++;
	if(tmp_max != max) cnt ++;

	if(cnt > n-m || tmp_min < min || tmp_max > max)
		cout << "Incorrect" << endl;
	else
		cout << "Correct" << endl;

	return 0;
}