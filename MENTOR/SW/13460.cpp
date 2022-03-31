#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
int Map[11][11];
pair<int,int> RED, BLUE, OUT;

string s;

int time, Ry, Rx, By, Bx, tox, toy, blocked;
int Rout=0, Bout=0;
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int main(){
    cin >> N >> M;

    // scan map and ball
    for(int i = 0;i<N;i++){
        cin >> s;
        for(int j=0; j<M; j++){
            if(s[j] == '#'){
                Map[i][j] = 1;
            }
            else if(s[j] =='R'){
                RED = {i, j};
            }
            else if(s[j] == 'B'){
                BLUE = {i, j};
            }
            else if(s[j] == 'O'){
                OUT = {i, j};
            }
        }
    }

    // play game
    queue<vector<int>> q; //time,  RED, BLUE
    q.push({0,RED.first, RED.second, BLUE.first, BLUE.second});

    while(!q.empty()){
        time = q.front()[0];
        RED = {q.front()[1], q.front()[2]};
        BLUE = {q.front()[3], q.front()[4]};
        q.pop();
        // 10번 이하로 움직여 빼낼 수 있는가.
        if(time >= 10) continue;

        // 4방향으로 기울인다.
        for(int i=0;i<4;i++){
            toy = dir[i][0]; tox = dir[i][1];

            // move RED
            Rout = 0; blocked = 0;
            Ry = RED.first; Rx = RED.second;
            while(Map[Ry][Rx]!=1){
                Ry = Ry + toy; Rx = Rx + tox;
                
                if(Ry == OUT.first && Rx == OUT.second){
                    Rout = 1;
                    Rx = M; Ry = N;
                    break;
                }
                if(Ry == BLUE.first && Rx == BLUE.second){
                    blocked = 1;
                    break;
                }
            }
            Ry = Ry - toy;  Rx = Rx - tox;

            // move BLUE
            By = BLUE.first; Bx = BLUE.second;
            Bout = 0;
            while(Map[By][Bx]!=1){
                By = By + toy; Bx = Bx + tox;
                
                if(By == OUT.first && Bx == OUT.second){
                    Bout = 1;
                    break;
                }
                if(By == Ry && Bx == Rx){
                    break;
                }
            }
            By = By - toy;  Bx = Bx - tox;

            // remove RED if BLUE previously blocked RED 
            if(blocked){
                while(Map[Ry][Rx]!=1){
                    Ry = Ry + toy; Rx = Rx + tox;
                    
                    if(Ry == OUT.first && Rx == OUT.second){
                        Rout = 1;
                        break;
                    }
                    if(Ry == By && Rx == Bx){
                        blocked = 1;
                        break;
                    }
                }
                Ry = Ry - toy;  Rx = Rx - tox;
            }
            if(Bout){
                continue;
            }
            else{
                if(Rout){
                    cout << time +1;
                    return 0;
                } 
                else{
                    q.push({time+1, Ry, Rx, By, Bx});
                }
            }
        }
    }
    cout << -1;
    return 0;
}