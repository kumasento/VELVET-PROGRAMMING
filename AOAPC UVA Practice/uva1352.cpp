#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int permute[24][6]={
{2, 1, 5, 0, 4, 3},
{2, 0, 1, 4, 5, 3},
{2, 4, 0, 5, 1, 3},
{2, 5, 4, 1, 0, 3},
{5, 1, 3, 2, 4, 0},
{1, 0, 3, 2, 5, 4},
{0, 4, 3, 2, 1, 5},
{4, 5, 3, 2, 0, 1},
{0, 1, 2, 3, 4, 5},
{4, 0, 2, 3, 5, 1},
{5, 4, 2, 3, 1, 0},
{1, 5, 2, 3, 0, 4},
{1, 3, 5, 0, 2, 4},
{0, 3, 1, 4, 2, 5},
{4, 3, 0, 5, 2, 1},
{5, 3, 4, 1, 2, 0},
{3, 4, 5, 0, 1, 2},
{3, 5, 1, 4, 0, 2},
{3, 1, 0, 5, 4, 2},
{3, 0, 4, 1, 5, 2},
{3, 4, 5, 0, 1, 2},
{3, 5, 1, 4, 0, 2},
{3, 1, 0, 5, 4, 2},
{3, 0, 4, 1, 5, 2},
};

int cube_check(int *p, int *q){
	for(int i = 0; i < 6; i++)
		if(q[i] != p[i])
			return 0;
	return 1;
}

// The input should be two vectors mapped to the color_map
// color_map is no need here
int check_res(int *p, int *q){
	int ok = 1;
	ok = cube_check(p, q);
	if(ok == 0){
		for(int i = 0; i < 24 && !ok; i++){
			int new_p[6]; 
			for(int k = 0; k < 6; k++)
				new_p[permute[i][k]] = p[k];
			ok = cube_check(new_p, q);
		}
	}
	return ok;
}

//calculate the best pose for p to be like q
int calculate(int *p, int *q){
	int min = 100;
	for(int i = 0; i < 24; i++){
		int new_p[6];
		for(int k = 0; k < 6; k++)
			new_p[permute[i][k]] = p[k];
		int cnt = 0;
		for(int k = 0; k < 6; k++)
			if(new_p[k] != q[k])
				cnt++;
		if(cnt < min)
			min = cnt;
	}
	return min;
}

int main(){
	freopen("1352.in", "r", stdin);

	int N; cin>>N;
	while( N != 0 ){
		int CUBE[N][6];

		//build color map and insert values
		map<string, int> color_map; int ID = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < 6; j++){
				string color; cin>>color;
				if(color_map.find(color) == color_map.end())
					color_map.insert(pair<string, int>(color, ID));
				CUBE[i][j] = color_map[color];
				ID++;
			}
		}

		int min = N * 6;
		for(int f = 0; f <= ID; f++){
			for(int r = 0; r <= ID; r++){
				for(int t = 0; t <= ID; t++){
					for(int d = 0; d <= ID; d++){
						for(int l = 0; l <= ID; l++){
							for(int b = 0; b <= ID; b++){
								printf("%d %d %d %d %d %d\n", f, r, t, d, l, b);
								int final[] = { f, r, t, d, l, b };
								int cnt = 0;
								for(int i = 0; i < N; i++){
									cnt += calculate(CUBE[i], final);
								}
								if(cnt < min)
									min = cnt;
							}
						}
					}
				}
			}
		}

		cout << min << endl;
		
		cin>>N;
	}
	return 0;
}