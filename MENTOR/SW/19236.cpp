/*
    19236. 청소년 상어 - 상어가 먹을 수 있는 물고기의 최댓값을 구해보자
*/

#include <iostream>

using namespace std;

int shark[3]; //상어의 위치 (x, y), 상어의 방향

struct INFO{
    int fishs[17][2]; // 1~16번 물고기의 위치
    int Map[5][5][2]; // 각 칸에 있는 물고기의 번호, 방향
};

int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

int move_shark(INFO info){
    /*
        상어가 움직여서 먹을 수 있는 물고기 번호의 합의 최댓값을 구한다.

        return max값
    */
   INFO move_F;
   move_F = move_fish()


}

int main(){
    INFO info;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>> info.Map[i][j][0] >> info.Map[i][j][1];
            info.fishs[info.Map[i][j][0]][0] = i;
            info.fishs[info.Map[i][j][0]][1] = j;
        }
    }
    cout << move_shark(info);
}