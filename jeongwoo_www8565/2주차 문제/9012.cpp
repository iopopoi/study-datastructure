// 문제: https://www.acmicpc.net/problem/9012
// C++에서 큰따옴표와 작은따옴표의 차이..?

/*
   문자열을 입력받음 - string으로
   string의 인덱스를 반복문으로 돌려서 바로바로 바교함.
   (일 경우에는 stack에 저장
   )일 경우에는 empty인지 확인하고 (가 있다면 내보냄.



   스택으로 (이 나오면 넣음
   )가 나오면 스택에서 (를 내보냄

   어짜피 (가 먼저 들어와야 비교를 할 수 있기 때문에
   )이 먼저 들어온 경우에는 비교할 필요 없음 - 무조건 no
   이는 empty 상황일때 )이 들어오는 상황과 동일 - 무조건 no
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
stack<char> s;
string str;

void func(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty() || str[i] == '(')
            s.push(str[i]);
        else if (s.top() == '(')
            s.pop();
    }
    if (s.empty())
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";
    while (!s.empty())
        s.pop();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        func(str);
    }
}