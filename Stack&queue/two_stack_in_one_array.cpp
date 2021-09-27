#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;
    st.push(1);
    st.push(1);
    st.push(1);
    
    st.pop();
    while (!st.empty())
    {
        cout << st.pop() << endl;
    }

    return 0;
}