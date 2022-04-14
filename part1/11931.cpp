#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,a;
    vector<int>v;
    cin >> N;

    while(N--){
        cin >>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        v[i] = -v[i];
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        v[i] = -v[i];
        cout << v[i] << "\n";
    }

}
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, a;
    vector<int> v;
    cin >> N;

    while(N--){
        cin >> a;
        v.push_back(-a);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size();i++){
        cout << -v[i] << "\n";
    }
}
*/