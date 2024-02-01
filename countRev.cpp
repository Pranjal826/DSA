#include <iostream>
#include <stack>
using namespace std;

int countRev(string s)
{
    int count = 0;
    stack<char> st;
    if (s.size() % 2 != 0)
        return -1;

    else
    {
        for (char ch = 0; ch < st.size(); ch++)
        {
            if (ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }

            while (!st.empty())
            {
                char ch1 = st.top();
                st.pop();
                char ch2 = st.top();
                st.pop();
                if (ch1 == ch2)
                {
                    count++;
                }
                else
                {
                    count += 2;
                }
            }
        }
    }
    return count;
}
int main()
{
    string s;
    cin >> s;
    cout << countRev(s);
    return 0;
}