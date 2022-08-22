#include <iostream>
using namespace std;

class Node
{
public:
    char c;
    int word_count;
    int word_ends;
    Node *children[26];

    Node(char c)
    {
        this->c = c;
        word_count = 0;
        word_ends = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('*');
    }

    void insertWord(string s)
    {
        char ch;
        Node *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            ch = s[i];
            if (!curr->children[ch - 'a'])
                curr->children[ch - 'a'] = new Node(ch);
            curr = curr->children[ch - 'a'];
            curr->word_count++;
        }
        curr->word_ends++;
    }

    bool isPresent(string s)
    {
        int idx;
        Node *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            idx = s[i] - 'a';
            if (!curr->children[idx] || curr->children[idx]->word_count == 0)
                return false;
            curr = curr->children[idx];
        }
        return curr->word_ends > 0;
    }

    void deleteWord(string s)
    {

        if(!isPresent(s))
            return ;

        int idx;
        Node *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            idx = s[i] - 'a';
            curr = curr->children[idx];
            curr->word_count--;
        }
        curr->word_ends--;
    }

    int noOfStringsWithPrefix(string s)
    {

        int idx;
        Node *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            idx = s[i] - 'a';
            if(!curr->children[idx] || curr->children[idx]->word_count == 0)
                return 0;
            curr = curr->children[idx];
        }

        return curr->word_count;
    }
};

int main()
{
    Trie T;
    T.insertWord("aryan");
    T.deleteWord("aryan");


    cout << T.noOfStringsWithPrefix("aryan") << endl;
    return 0;
}