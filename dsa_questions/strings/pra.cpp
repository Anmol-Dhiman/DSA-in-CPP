#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    // string str;
    // getline(cin, str);
    // cout << str << endl;

    //    appending means adding one string in other string and this will change the first string
    string s1 = "family";
    string s2 = "ily";
    // s1.append(s2);
    cout << s1 << endl;
    // compare returns 0 if strings are equal and for unequal strings it give any number other then 0 based on the assci table of the characters.

    cout << s1.compare(s2) << endl;
    // empty() gives 0 if the string is empty
    cout << s1.empty() << endl;
    // count form the 0 base indexing
    cout << s1.erase(6, 12) << endl;
    // find function gives the index from where it find the first charachter of the word

    cout << s1.find("ily") << endl;
    cout << s1.length() << endl;
    cout << s1.insert(6, " man") << endl;
    string s3 = "123";
    int x = stoi(s3);
    string s4="jai shri ram";
    
    cout << x << endl;
    sort(s4.begin(), s4.end());
    cout << s4 << endl;
    return 0;
}