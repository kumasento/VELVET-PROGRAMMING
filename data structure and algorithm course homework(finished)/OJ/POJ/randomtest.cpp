#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int n = 100, m = 10000;

double D_Rand(){
	return (double)rand() / RAND_MAX;
}
int I_Rand( ){
	return (int) (D_rand() * (m-1) + 0.5);
}

int main(){
	srand(time(0));

	return 0;
}