// 문제: https://www.acmicpc.net/problem/10814
// vector와 make_pair의 조합 참고하기 좋음.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool inve(pair<int, string> x, pair<int, string> y)
{
    return x.first < y.first;
}

int main(void)
{

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int case_len;
    cin >> case_len;

    vector<pair<int, string> > v(case_len);

    for (int i = 0; i < case_len; i++)
        cin >> v[i].first >> v[i].second;

    stable_sort(v.begin(), v.end(), inve);

    for (int i = 0; i < case_len; i++)
        cout << v[i].first << " " << v[i].second << "\n";
}