#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

/*
 *为什么是低效率的：
	主要是重复的运算——比如重复计算一些已经计算过的子序列的和
 */
int 
_Algo_for(int seq[], int N = 6 ){
	int _max = 0;
	for(int i = 0; i < N; i++){
		for(int j = i; j < N; j++){
			int _sum = 0;
			for(int k = i; k <= j; k++) _sum += seq[k];
			if(_sum > _max) _max = _sum;
		}
	}
	return _max;
};

int 
_Algo_divide(int seq[], int start, int end, int N = 6){
	if(N == 0) return 0;
	if(N == 1) return seq[0];
	int mid = (start + end) / 2;
	int _left_part, _right_part;
	_left_part = _Algo_divide(seq,start,mid,mid-start);
	_right_part = _Algo_divide(seq,mid,end,end-mid);
	int _max = max(_left_part, _right_part);
	int _left_ptr = mid;
	for(; _left_ptr >= 0; _left_ptr --){ 
		/* 这个写法还是有好多重复计算
		 * 应该是分别写出左右的带边界和
		 * 分别取出最大值以后再进行比较
		 */
		int _nowSum = 0;
		for(int i = 0; i + _left_ptr < end; i++){
			_nowSum += seq[i + _left_ptr];
			if(_nowSum > _max) _max = _nowSum;
		}
	}
	return _max;
};

//最优雅的算法！
int 
_Algo_best(int seq[], int N = 6){
	int ThisSum = 0, MaxSum = 0;
	for(int i = 0; i < N; i++){
		ThisSum += seq[i];
		int tmpSum = ThisSum;
		if(ThisSum > MaxSum) MaxSum = ThisSum;
		else if(ThisSum < 0) ThisSum = 0;
		printf("%d\t%d\t%d\n", tmpSum, i, ThisSum);
	}
	return MaxSum;
};

int main(){
	int seq[6] = { -2, 11, -100, 13, -5, -2};
	for(int i = 0; i < 4; i++){
		if(i == 0) cout<<_Algo_for(seq)<<endl;
		else if(i == 1) cout<<_Algo_divide(seq,0,6,6)<<endl;
		else if(i == 2) cout<<_Algo_best(seq)<<endl;
		//else if(i == 3)
	}
	return 0;
}
