#include <iostream>
using namespace std;
class Trie
{
public:
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    node *trie;
    Trie()
    {
        trie = new node();
    }
    void insert(string word)
    {
        int i = 0;
        node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
            {
                it->next[word[i] - 'a'] = new node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }

        it->end = true;
    }
    bool search(string word)
    {

        int i = 0;
        node *it = trie;

        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
            {
                break;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        if (i == word.size())
        {
            return true;
        }
        bool temp2;
        if (it->end)
        {
           
            temp2 = search(word.substr(i, word.size()-1));
            return temp2;
        }
        return false;
    }
};

int main()
{
    Trie *root = new Trie();
    root->insert("i");
    root->insert("like");
    root->insert("samsung");
  
    cout << root->search("ilikesamsung") << endl;
    // cout << root->trie->next[11]->next[8]->next[10]->next[4]->end << endl;

    return 0;
}