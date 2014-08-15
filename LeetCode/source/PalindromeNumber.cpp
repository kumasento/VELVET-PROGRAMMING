#include <iostream>
#include <stdlib.h>

using namespace std;

bool isPalindrome(int x) {
	if (x < 0) return false;
        
    int start_pos = 1;
    int end_pos = 1;
    int tmp = x / 10;
    while (tmp != 0) {
        end_pos *= 10;
        tmp /= 10;
    }
    // here to decide how long the number is
    while (start_pos <= end_pos) {
        int start_digit = (x / start_pos) % 10;
        int end_digit = (x / end_pos) % 10;
        if (start_digit != end_digit)
            return false;
        start_pos *= 10;
        end_pos /= 10;
    }
    
    return true;
}

int main() {
	freopen("data/PalindromeNumber.in", "r", stdin);
	
	int num;
	while (cin>>num) {
		cout << isPalindrome(num) << endl;
	}	

    return 0;
}
