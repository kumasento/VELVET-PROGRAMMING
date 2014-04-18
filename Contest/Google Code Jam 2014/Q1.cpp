#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out_1.out", "w", stdout);
	int T; cin>>T;
	for(int idx = 0; idx < T; idx++){
		int Ans1, Ans2;
		int MAT1[4][4], MAT2[4][4];
		cin>>Ans1;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				cin>>MAT1[i][j];
		cin>>Ans2;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				cin>>MAT2[i][j];
	
		int cnt = 0, tmp_ans = -1;
		for(int j1 = 0; j1 < 4; j1++)
			for(int j2 = 0; j2 < 4; j2++){
				if(MAT1[Ans1-1][j1] == MAT2[Ans2-1][j2]){
					tmp_ans = MAT1[Ans1-1][j1];
					cnt ++;
				}
			}

		if(cnt == 0)
			printf("Case #%d: Volunteer cheated!\n", idx+1);
		else if(cnt == 1)
			printf("Case #%d: %d\n", idx+1, tmp_ans );
		else
			printf("Case #%d: Bad magician!\n", idx+1);
	}

	return 0;
}