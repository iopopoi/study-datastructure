#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string str;
	int stick_count = 0, sol = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] == '(')
			stick_count += 1;
		if (str[i] == ')' && str[i - 1] == '(') 
		{
			stick_count -= 1;
			sol += stick_count;
		}
		else if (str[i] == ')' && str[i - 1] == ')') 
		{
			stick_count -= 1;
			sol += 1;
		}
	}

	cout << sol << "\n";
}