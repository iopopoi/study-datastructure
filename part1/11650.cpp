/**
 * @file 11650.cpp
 * @name 좌표 정렬
 * 
 * @ first try
 * pairt <int,vector<int,int>> 를 정의함
 * 이렇게 하면 sort 를 사용하기 어렵기에 
 * 두 번째 시도의 자료형을 사용하는게 좋았음
 * 
 * @ second try
 * vector <int,pair<int,int>>
 */
/**
 * @file 11650.cpp
 * @name 좌표 정렬
 * 
 * @ first try
 * pairt <int,vector<int,int>> 를 정의함
 * 이렇게 하면 sort 를 사용하기 어렵기에 
 * 두 번째 시도의 자료형을 사용하는게 좋았음
 * 
 * @ second try
 * vector <int,pair<int,int>>
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n,a,b;
    // pair <int,vector<int,int> m;
    vector <pair<int,int>> m;
    cin >> n;
    for(int i =n;i>0;i--){
        cin >> a >> b;
        m.push_back({a,b}); 
    }
    sort(m.begin(),m.end());
    for (int i = 0; i < n; i++) {
		cout << m[i].first << ' ' << m[i].second << '\n';
	}
	return 0;
    
}