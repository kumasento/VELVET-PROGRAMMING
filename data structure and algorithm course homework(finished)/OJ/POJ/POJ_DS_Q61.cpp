// Nice noon!
// But I wanna go to the washroom -.-

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class MinHeap{
public:
	vector<int> HeapArray;
	int CurrentSize;
	int MaxSize;

	MinHeap( const int n );
	inline int parent( int pos );
	inline int left( int pos );
	void SiftDown( int i );
	void SiftUp( int position );
	void BuildHeap();
	void DeleteLeastNumber();
	void InsertNumber( int num );
	void PrintHeap();
};

void MinHeap::PrintHeap(){
	for( int i = 0; i < CurrentSize; i++ ){
		cout << HeapArray[i] <<' ';
	}
	cout << endl;
}
MinHeap::MinHeap( const int n ){
	HeapArray.clear();
	MaxSize = n;
	CurrentSize = 0;
}
inline int MinHeap::parent( int pos ){
	return pos >> 1;
}
inline int MinHeap::left( int pos ){
	return ( pos << 1 ) + 1;
}
void MinHeap::SiftDown( int pos ){
	// father position
	int i = pos;
	// less value point
	int j = left(i);
	int tmp = HeapArray[i];

	while( j < CurrentSize ){ //when there is no child less than tmp, quit
		if( ( j < CurrentSize - 1 ) && ( HeapArray[j] > HeapArray[j+1] ) )
			j++;
		if( tmp > HeapArray[j] ){ // now the head can sift down
			HeapArray[i] = HeapArray[j];
			i = j;
			j = left(i);
		}
		else 
			break;
	}

	HeapArray[i] = tmp;
}
void MinHeap::SiftUp( int position ){
	int tmppos = position;
	int tmp = HeapArray[tmppos];
	//cout << "P" << parent(tmppos) << endl;
	while( (tmppos > 0) && ( HeapArray[ parent(tmppos) ] > tmp ) ){
		HeapArray[tmppos] = HeapArray[parent(tmppos)];
		tmppos = parent(tmppos);
	}
	HeapArray[tmppos] = tmp;
}
void MinHeap::InsertNumber( int num ){
	HeapArray.push_back(num);
	CurrentSize ++;
	//PrintHeap();	
	SiftUp( CurrentSize-1 );

	//PrintHeap();
}
void MinHeap::DeleteLeastNumber(){
	HeapArray[0] = HeapArray[CurrentSize-1]; // get a number larger than the biggest one;
	SiftDown( 0 );
	CurrentSize --;
	HeapArray.erase( HeapArray.end()-1 );
	//PrintHeap();
}
void MinHeap::BuildHeap(){
	for( int i = CurrentSize / 2 - 1; i >= 0 ; i-- )
		SiftDown(i);
}

int main(){
	int t; cin >> t;
	while( t ) {
		int n; cin >> n;
		MinHeap heap( 10000 );
		while( n ){
			
			int type; cin >> type;
			if( type == 1 ){
				int num; cin >> num;
				// insert function
				heap.HeapArray.push_back(num);
				heap.CurrentSize ++;
			}
			else if ( type == 2 ){
				// erase function
				heap.BuildHeap();
				cout << heap.HeapArray[0] << endl;
				heap.DeleteLeastNumber();
				//cout << heap.CurrentSize << endl;
			}
			//heap.PrintHeap();
			n --;
		}

		t --;
	}

	return 0;
}
