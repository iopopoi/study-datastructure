// 문제: https://www.acmicpc.net/problem/10845

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    queue<int> q;
    string command;

    for (int i = 0; i < N; i++)
    {
        cin >> command;
        if (command == "push")
        {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (command == "pop")
        {
            if (q.size() == 0)
            {
                cout << "-1"
                     << "\n";
            }
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (command == "size")
        {
            cout << q.size() << "\n";
        }
        else if (command == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if (command == "front")
        {
            if (q.size() == 0)
            {
                cout << "-1"
                     << "\n";
            }
            else
            {
                cout << q.front() << "\n";
            }
        }
        else if (command == "back")
        {
            if (q.size() == 0)
            {
                cout << "-1"
                     << "\n";
            }
            else
            {
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}