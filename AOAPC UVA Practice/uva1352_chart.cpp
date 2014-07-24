#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int _right[] = { 4, 0, 2, 3, 5, 1 };
int _up[] = { 2, 1, 5, 0, 4, 3 };

string pos[] = {"front", "right", "up", "down", "left", "back"};

//T is the rotate template
void rotate(int *T, int *p){
	int q[6]; // Here q is a temperory parameter
	memcpy( q, p, sizeof(q) );


	for(int i = 0; i < 6; i++)
		p[i] = T[q[i]];
}

void visualize(int *q){
	for(int i = 0; i < 6; i++)
		printf("%s: %d\n", pos[i].c_str(), q[i]+1);
	printf("\n");
}

void enumerate_permutation(){
	int p0[6] = { 0, 1, 2, 3, 4, 5 }; // initial positions
	printf("int permute[24][6]={\n");
	for(int i = 0; i < 6; i++){
		int p[6]; memcpy(p, p0, sizeof(p));
		if(i == 0) rotate(_up, p);
		if(i == 1) { rotate(_up, p); rotate(_up, p); }
		if(i == 3) { rotate(_right, p); rotate(_right, p); rotate(_right, p); rotate(_up, p); }
		if(i == 4) { rotate(_right, p); rotate(_right, p); rotate(_up, p); }
		if(i == 5) { rotate(_right, p); rotate(_right, p); rotate(_up, p); }
		for(int j = 0; j < 4; j++){
			printf("{%d, %d, %d, %d, %d, %d},\n", p[0], p[1], p[2], p[3], p[4], p[5]);
			rotate(_right, p);
		}
	}
	printf("};\n");
}

int main(){
	enumerate_permutation();
	return 0;
}