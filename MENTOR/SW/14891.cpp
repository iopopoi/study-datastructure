/*
    14891. 톱니바뀌
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// N: 0, S : 1 , 12시 방향의 극 부터 들어옴(2, 6번이 만난다.)
deque<int> dq[4];
int K, num, dir, ch, ans, chk[4];
string s;

int find_dir(int chan){
    if( abs(num-chan) % 2 == 0)// 돌리는 톱니바뀌랑 다른 방향으로 돈다. 
        return dir;
    else// 같은 방향으로 돈다.
        return -dir;
}

void order(int turn, int chan){
    if(turn == 1){
        dq[chan].push_front(dq[chan][7]);
        dq[chan].pop_back();
    }
    else{
        dq[chan].push_back(dq[chan][0]);
        dq[chan].pop_front();
    } 
}

int main(){
    for(int i=0;i<4;i++){
        cin >> s;
        for(int j=0;j<8;j++){
            dq[i].push_back(s[j]-'0');
        }
    }

    cin >> K;
    while(K--){
        cin >> num >> dir;

        for(int i=0;i<3;i++){
            if(dq[i][2] != dq[i+1][6]) chk[i]=1;
            else chk[i] = 0;
        }
        num --;
        ch = num;
        while(ch > 0 && chk[ch-1]){
            ch --;
            order(find_dir(ch), ch);
        }

        order(dir, num);

        ch = num;
        while(ch < 3 && chk[ch]){
            ch++;
            order(find_dir(ch), ch);
        }
    }

    int s=1;
    for(int i=0;i<4;i++){
        if(dq[i][0] == 1) ans += s;
        s *= 2;
    }

    cout << ans;
}