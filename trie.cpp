#include <iostream>
using namespace std;

struct Node
{
    char c;
    int word_ends;
    Node *children[26];
};

Node *getNode(char c)
{
    Node *node = new Node();
    node->c = c;
    node->word_ends = 0;
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

void insertWord(Node *root, string s)
{

    Node *curr;
    curr = root;
    char ch;
    for (int i = 0; i < s.length(); i++)
    {
        ch = s[i];
        if (!curr->children[ch - 'a'])
            curr->children[ch - 'a'] = getNode(ch);
        curr = curr->children[ch - 'a'];
    }
    curr->word_ends += 1;
}

bool isPresent(Node *root, string s)
{
    Node *curr;
    curr = root;
    char ch;

    for (int i = 0; i < s.length(); i++)
    {
        ch = s[i];
        if (!curr->children[ch - 'a'])
            return false;
        curr = curr->children[ch - 'a'];
    }
    return curr->word_ends > 0;
}

void deleteWord(Node *root, string s)
{
    Node *curr;
    curr = root;
    char ch;
    for (int i = 0; i < s.length(); i++)
    {
        ch = s[i];
        if(!curr->children[ch - 'a'])
            return;
        curr = curr->children[ch - 'a'];
    }

    if(curr->word_ends == 0)
        return;
    curr->word_ends--;
}

int main()
{
    Node *root = getNode('/');
    insertWord(root, "applet");
    insertWord(root, "apple");
    insertWord(root, "app");

    cout << isPresent(root, "aryan") << endl;
    cout << isPresent(root, "app") << endl;
    cout << isPresent(root, "apples") << endl;
    cout << isPresent(root, "apple") << endl;

    cout << "Deleting app" << endl;
    deleteWord(root, "app");
    cout << isPresent(root, "app") << endl;
    return 0;
}