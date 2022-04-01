#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() 
{
	cin.tie(nullptr);
	cout.tie(nullptr);

	string order;
	stack <int> s;
	int N, x;


	cin >> N;

	while (N--)
	{
		cin >> order;

		if (order.compare("push") == 0)
		{
			cin >> x;
			s.push(x);
		}
		else if (order.compare("pop") == 0) 
		{
			if (s.size() != 0) 
			{
				cout << s.top() << "\n";
				s.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (order.compare("size") == 0)
			cout << s.size() << "\n";
		else if (order.compare("empty") == 0)
			cout << s.empty() << "\n";
		else if (order.compare("top") == 0) 
		{
			if (s.size() != 0)
				cout << s.top() << "\n";
			else
				cout << -1 << "\n";
		}

	}

}