// 문제: https://www.acmicpc.net/problem/11650
// make_pair은 utility 필요없음. Pair 쓸때만

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int case_len;
    cin >> case_len;

    vector<pair<int, int> > vec;

    for (int i = 0; i < case_len; i++)
    {
        int x, y;
        cin >> x >> y;

        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < case_len; i++)
        cout << vec[i].first << " " << vec[i].second << "\n";

    return 0;
}