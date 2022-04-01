#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() 
{
	int N;
	stack <char> s;
	string str;
	cin >> N;

	while (N--)
	{
		cin >> str;

		for (int i = 0; i < str.size(); i++) 
		{
			if (s.empty())
				s.push(str[i]);
			else if (str[i] == '(')
				s.push(str[i]);
			else 
			{
				if (s.top() == '(')
					s.pop();
			}
		}
		if (s.size() == 0) cout << "YES" << "\n";
		else cout << "NO" << "\n";

		for (; s.size() != 0;)
			s.pop();
	}

}