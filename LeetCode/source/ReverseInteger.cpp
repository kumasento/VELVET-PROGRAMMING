#include <iostream>
#include <stack>

using namespace std;

int reverse(int x) {
    int sign = (x < 0) ? -1 : 1;
    x = sign * x;
    // Now get the main part of the integer
    
    stack<int> digits;
    while (x != 0) {
        digits.push(x % 10);
        cout << x % 10 << endl;
        x /= 10;
    }
    int ans = 0;
    int cnt = 1;
    while (!digits.empty()) {
        ans += digits.top() * cnt;
        digits.pop();
        cnt *= 10;
    }
    return ans * sign;
}

int main() {
    int num;
    while (cin>>num) {
        cout << reverse(num) << endl;
    }
}
