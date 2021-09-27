// we need an empty root node where the value of end is false 
// and we need it to access the other 26 variables of the endlish alphabets

#include <iostream>

using namespace std;
class Trie
{
    // we want to use both the class in every function so we make them as public
public:
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            // making the base case
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
                return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};
int main()
{
    Trie *val = new Trie();
    val->insert("anmol");
    val->insert("ronak");
    val->insert("vaibhav");
    val->insert("rajat");
    cout << val->search("mayank") << endl;
    cout << val->search("anmol") << endl;
    return 0;
}