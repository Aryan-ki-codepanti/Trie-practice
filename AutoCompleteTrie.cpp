#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    int we;
    int wc;
    TrieNode *children[26];

    TrieNode(char data)
    {
        this->data = data;
        we = 0;
        wc = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
    TrieNode *root;

    void DFS_helper(string currentString, TrieNode *curr)
    {
        if (curr->we > 0)
            cout << currentString << endl;

        for (int i = 0; i < 26; i++)
        {
            if (curr->children[i])
                DFS_helper(currentString + curr->children[i]->data, curr->children[i]);
        }
    }

    bool searchQuery(string s)
    {
        int idx;
        TrieNode *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            idx = s[i] - 'a';
            if (!curr->children[idx] || curr->children[idx]->wc == 0)
                return false;
            curr = curr->children[idx];
        }
        return curr->wc > 0;
    }

public:
    Trie()
    {
        root = new TrieNode('/');
    }

    void insert(string s)
    {
        int idx;
        TrieNode *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            idx = s[i] - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode(s[i]);
            curr = curr->children[idx];
            curr->wc++;
        }
        curr->we++;
    }

    void AutoComplete(string query)
    {
        if (!searchQuery(query))
        {
            cout << "No suggestions" << endl;
            return;
        }

        TrieNode *curr = root;
        int idx;
        for (int i = 0; i < query.length(); i++)
        {
            idx = query[i] - 'a';
            curr = curr->children[idx];
        }

        DFS_helper(query, curr);
    }

    void DFS()
    {
        DFS_helper("", root);
    }
};

int main()
{
    Trie t;
    t.insert("aryan");
    t.insert("aryanshi");
    t.insert("aruuu");
    t.insert("ams");
    t.insert("aaab");
    t.insert("aaababb");

    t.DFS();
    // t.AutoComplete("aa");
    // t.AutoComplete("man");
    return 0;
}