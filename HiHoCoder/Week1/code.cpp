#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestPalindrome(string s)
{
    int n = s.length();
    vector<int> p(n, 0);
    int id = 0, mx = 0;
    
    for (int i = 1; i < n; i++)
    {
        p[i] = (mx > i) ? min(p[2*id-i], mx-i) : 1;
        while (s[i+p[i]] == s[i-p[i]]) p[i] ++;
        if (i + p[i] > mx)
            mx = i+p[i], id = i;
    }
    
    int max_len = 0;
    for (int i = 0; i < n; i++)
        max_len = max(max_len, p[i]-1);
        
    return max_len;
}

int main()
{
    freopen("palindrome.dat", "r", stdin);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        string s; cin >> s;
        string ss;
        ss.push_back('$');
        for (int i = 0; i < s.length(); i++)
        {
            ss.push_back('#');
            ss.push_back(s[i]);
        }
        ss.push_back('#');
        
        cout << longestPalindrome(ss) << endl;
    }
    
    return 0;
}
