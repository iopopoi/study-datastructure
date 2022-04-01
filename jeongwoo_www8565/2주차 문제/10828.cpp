#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, x;
    string st;
    stack<int> s;

    cin >> N;

    while (N--)
    {
        cin >> st;
        if (st == "push")
        {
            cin >> x;
            s.push(x);
        }
        else if (st == "pop")
        {
            if (!s.empty())
            {
                cout << s.top() << "\n";
                s.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else if (st == "size")
        {
            cout << s.size() << "\n";
        }
        else if (st == "empty")
        {
            cout << s.empty() << "\n";
        }
        else if (st == "top")
        {
            if (!s.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s.top() << "\n";
            }
        }
    }
}