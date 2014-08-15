#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int binary_search(vector<int> &numbers, int val) {
    int l = 0, r = numbers.size() - 1;
    int mid;
    while (l <= r) {
        mid = (l+r) / 2;
        if (numbers[mid] == val) return mid;
        else if (numbers[mid] < val) l = mid + 1;
        else if (numbers[mid] > val) r = mid - 1;
    }
    return -1;
}


int main(int argc, char *argv[]) {
    freopen(argv[1], "r", stdin);

    int num; 
    while (cin >> num) {
        vector<int> numbers; 
        for (int i = 0; i < num; i++) {
            int N; cin>>N;
            numbers.push_back(N);
        }
        int val; cin>>val;
        cout << binary_search(numbers, val) << endl;
    }

    return 0;
}
