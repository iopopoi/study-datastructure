#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b){
    if(a.first == b.first){
        return 1;
    }
    else return a.first < b.first;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n,age;
    string name;
    vector <pair<int,string>> v;
    cin >> n;
    while(n--){
        cin >> age >> name;
        v.push_back({age,name});
    }
    stable_sort(v.begin(),v.end(),cmp);
    // ↑ 이녀석 하나 바꾸니 해결되었다
    for(int i=0;i<v.size();i++){
        cout << v[i].first <<" "<<v[i].second <<"\n";
    }
}