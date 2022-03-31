// 문제: https://www.acmicpc.net/problem/10825
// vector< 구조체이름 > 이런 형태도 쌉가능..

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    int kor, eng, math;
    string name;
};

bool cmp(Person a, Person b)
{
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math)
        return a.name < b.name;
    if (a.kor == b.kor && a.eng == b.eng)
        return a.math > b.math;
    if (a.kor == b.kor)
        return a.eng < b.eng;

    return a.kor > b.kor;
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int case_len;
    cin >> case_len;

    vector<Person> v(case_len);

    for (int i = 0; i < case_len; i++)
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;

    stable_sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < case_len; i++)
        cout << v[i].name << "\n";
}