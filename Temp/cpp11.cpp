
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> strs;
    strs.push_back(string("hello world!"));
    strs.push_back(string("hello world!"));
    strs.push_back(string("hello world!"));

    for (const auto& str : strs)
        cout << str << endl;

    return 0;
}
