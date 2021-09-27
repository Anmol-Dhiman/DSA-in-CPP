// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to evaluate a postfix expression.

    int calculate(int b, int c, char a)
    {
        if (a == '+')
        {
            return b + c;
        }
        else if (a == '-')
        {
            return c - b;
        }
        else if (a == '*')
        {
            return b * c;
        }
        else if (a == '/')
        {
            return c / b;
        }
        else 
        {
            return c % b;
        }
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        int temp1;
        int temp2;
        for (int i = 0; i < S.length(); i++)
        {
            if (S.at(i) >= 0 && S.at(i) <= 9)
            {
                st.push(S.at(i) - '0');
            }
            else
            {
                temp1 = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                st.push(calculate(temp1, temp2, S.at(i)));
            }
        }
        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}
// } Driver Code Ends