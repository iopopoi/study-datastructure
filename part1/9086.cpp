#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// ↓ 아래는 틀린 시도
// if 조건문에서 앞 뒤가 같은, 문자열 길이가 2이상인 경우
// 맨 앞 한 글자만 출력하게 한다.  
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    string _str;
    vector <string> str;
    cin >> n;
    while(n--){
        cin >> _str;
        str.push_back(_str); 
    }
    for(int i=0;i<str.size();i++){
        if(str[i].front() == str[i].back()){
          cout << str[i].front()<<"\n";
        }
      else cout << str[i].front() << str[i].back()<<"\n";
    }
}
///////////////////////////////////////////////
// ↓ 아래는 맞춘 시도 
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    string _str;
    vector <string> str;
    cin >> n;
    while(n--){
        cin >> _str;
        str.push_back(_str); 
    }
    for(int i=0;i<str.size();i++){
        if(str.size()==1){
          cout << str[i]<<"\n";
        }
      else cout << str[i].front() << str[i].back()<<"\n";
    }
}

