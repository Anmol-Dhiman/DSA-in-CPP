// question: -
/*Given an array of words, find all shortest unique
prefixes to represent each word in the given array. Assume that no word is prefix of another. 
Examples: 
 

Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove = dov 
             duck = du
             z   => zebra 

Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
Output: geeksf, geeksg, geeksq}*/

#include <iostream>
using namespace std;

class Trie
{
    // we want to use both the class in every function so we make them as public
public:
    class node
    {
    public:
        int frequency;
        node *next[26];
        node()
        {
            // making the base case
            frequency = 1;
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
        trie->frequency = 0;
    }
    void insertion(string word)
    {
        node *temp = trie;
        int i = 0;
        while (i < word.size())
        {
            if (temp->next[word[i] - 'a'] == NULL)
            {
                temp->next[word[i] - 'a'] = new node();
            }
            else
            {
                temp->next[word[i] - 'a']->frequency++;
            }

            temp = temp->next[word[i] - 'a'];
            i++;
        }
    }
    void findprefix(string word)
    {
        node *root = trie;
        int i = 0;
        char prefix[100];
        int count = 0;
        while (i < word.size())
        {
            if (root->next[word[i] - 'a']->frequency == 1)
            {
                prefix[count] = (word[i] - 'a') + 97;
                count++;
                prefix[count] = '\0';
                break;
            }
            else
            {
                prefix[count] = (word[i] - 'a') + 97;
                count++;
            }
            root = root->next[word[i] - 'a'];
            i++;
        }
        // for printing like this we need to consider the whole ASCII table
        cout << prefix << endl;
    }
    void prefix(string arr[], int size)
    {

        for (int i = 0; i < size; i++)
        {
            insertion(arr[i]);
        }

        for (int i = 0; i < size; i++)
        {
            findprefix(arr[i]);
        }
    }
};

int main()
{
    Trie *root = new Trie();
    string arr[]{"dog", "dove", "duck", "zebra"};
    root->prefix(arr, 4);

    return 0;
}