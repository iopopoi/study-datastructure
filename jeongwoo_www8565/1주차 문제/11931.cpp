// 참고: https://m.blog.naver.com/ndb796/221227975229 / sort 함수 다루기
// 문제: https://www.acmicpc.net/problem/11931

#include <iostream>
#include <algorithm>

using namespace std;

bool inve(int a, int b) { return a > b; }

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int arr[n];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, inve);

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";

    return 0;
}

/* 첫번째 시간초과 코드
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int case_len;
    cin >> case_len;

    int arr[case_len];

    sort(arr, arr + case_len);

    for (int i = 0; i < case_len; i++)
    {
        cin >> arr[i];
        arr[i] = -1 * arr[i];
    }

    sort(arr, arr + case_len);

    for (int j = 0; j < case_len; j++)
    {
        cout << -1 * arr[j] << endl;
    }
}
*/

/* 두번째 시간초과 코드
#include <iostream>
#include <algorithm>

using namespace std;

bool inve(int a, int b)
{
    return a > b;
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int case_len;
    cin >> case_len;

    int arr[case_len];

    sort(arr, arr + case_len);

    for (int i = 0; i < case_len; i++)
        cin >> arr[i];

    sort(arr, arr + case_len, inve);

    for (int i = 0; i < case_len; i++)
        cout << arr[i] << endl;
}
*/