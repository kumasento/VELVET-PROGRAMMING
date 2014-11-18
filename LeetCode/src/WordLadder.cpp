#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) 
            return 0;

        int len = start.length();
        // initialize the queue
        queue< pair<string, int> > q; q.push(pair<string, int>(start, 0));
        // prevent the loop in the graph
        map<string, bool> m; m[start] = true;

        while (!q.empty()) {
            pair<string, int> front_pair = q.front(); q.pop();   
            string front_str = front_pair.first;
            int front_layer = front_pair.second;

            // find every possible move
            for (int i = 0; i < len; i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    string new_str = front_str;
                    if (new_str[i] == ch) 
                        continue;
                    new_str[i] = ch;

                    if (new_str == end) // found the answer;
                        return front_layer + 2;
                    if (dict.find(new_str) != dict.end() && !m[new_str]) {
                        m[new_str] = true;
                        q.push(pair<string, int>(new_str, front_layer+1));
                    }
                }
            }
        }

        return 0;
    }
private:
    inline int checkDiff(string str1, string str2, int len) {
        int dif_cnt = 0;
        for (int i = 0; i < len; i++) 
            if (str1[i] != str2[i])
                dif_cnt ++;
        return dif_cnt;
    }
};

int main(int argc, char *argv[]) {
    freopen(argv[1], "r", stdin);
    string start, end;
    while (cin>>start>>end) {
        unordered_set<string> dict;
        string dict_elem;
        int dict_size; cin>>dict_size;
        for (int i = 0; i < dict_size; i++) {
            cin>>dict_elem;
            dict.insert(dict_elem);
        }
        
        Solution sol;
        cout << sol.ladderLength(start, end, dict) << endl;
    }

    return 0;
}
