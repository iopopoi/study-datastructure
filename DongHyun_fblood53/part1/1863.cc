#include <iostream>
#include <stack>

using namespace std;

int main() 
{
	int N, cnt = 0;
	stack <int*>s;
	cin >> N;
	int** arr = new int* [N];

	for (int i = 0; i < N; i++)            // 숫자들 넣어두기
	{
		arr[i] = new int[2];
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < N; i++)            // 확인
	{
		if (s.empty())                     // 비었다면 스택에 추가
			s.push(arr[i]);
		else                               // 변곡점이 내려갈 떄 건물 개수 카운트
		{
			if (s.top()[1] < arr[i][1])                               
				s.push(arr[i]);
			else if (s.top()[1] > arr[i][1])
			{
				while (!s.empty() && s.top()[1] > arr[i][1])    // 스택에서 앞으로 올 건물보다 크다면 빼주면서 카운트
				{
					cnt++;
					s.pop();
				}
				if (s.empty() || s.top()[1] != arr[i][1])       // 같은 크기 건물은 넣지 않는다.
					s.push(arr[i]);
			}
		}
	}
	
	while (!s.empty())             // 만약 스택에 남은 건물들이 전부 우상향일 경우
	{
		if (s.top()[1] != 0)       // 크기가 0이 아니라면 카운트
			cnt++;
		s.pop();
	}
	

	cout << cnt << "\n";

	for (int i = 0; i < N; i++)
		delete[] arr[i];
	delete[] arr;

}