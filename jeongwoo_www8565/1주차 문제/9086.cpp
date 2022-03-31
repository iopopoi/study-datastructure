// 문제 : https://www.acmicpc.net/problem/9086
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int case_num;

    cin >> case_num;
    for (int i = 0; i < case_num; i++)
    {
        string S = "";
        cin >> S;
        cout << S[0] << S[S.size() - 1] << endl;
    }
}