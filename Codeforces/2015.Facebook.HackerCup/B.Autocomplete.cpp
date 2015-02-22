
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>

#define N 26

using namespace std;

// use Trie
struct Trie_node {
    int count;
    Trie_node * next[N];
    bool exist;
    Trie_node(): count(0), exist(false)
    { for (int i = 0; i < N; i++) next[i] = NULL; }
};

void Trie_insert(Trie_node *root, string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        char c = str[i];
        int idx = c - 'a';
        if (root->next[idx] == NULL)
            root->next[idx] = new Trie_node();
        root = root->next[idx];
        root->count ++;
    }
    root->exist = true;
}

int Trie_steps(Trie_node *root, string word)
{
    Trie_node *trie_node = root;
    int len = word.length();
    for (int i = 0; i < len; i++)
    {
        int idx = word[i] - 'a';
        root = root->next[idx];
        if (root->count == 1)
            return i+1;
    }
    return len;
}

void Trie_free(Trie_node *root)
{
    for (int i = 0; i < N; i++)
        if (root->next[i] != NULL)
            Trie_free(root->next[i]);
    delete root;
    return;
}


int main()
{
    freopen("B.Autocomplete.dat", "r", stdin);

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        // add to prefix "tree"?
        Trie_node *trie = new Trie_node();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            string word; cin >> word;
            Trie_insert(trie, word);
            sum += Trie_steps(trie, word);
        }

        Trie_free(trie);
        printf("Case #%d: %d\n", t, sum);
    }

    return 0;
}
