/*
    19236. 청소년 상어 - 상어가 먹을 수 있는 물고기의 최댓값을 구해보자
*/

#include <iostream>
#include <algorithm>

using namespace std;

int y, x, d;

struct INFO{
    int fishes[17][2]; // 1~16번 물고기의 위치, 없으면 -1
    int Map[5][5][2]; // 각 칸에 있는 물고기의 번호, 방향
};

struct SHARK{
    int y,x,d,num_sum;
};

int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};


INFO move_fish(INFO info, SHARK shark){

    for(int i=1;i<=16;i++){
        if(info.fishes[i][0] != -1){
            //  i번 물고기가 있을때
            y = info.fishes[i][0];
            x = info.fishes[i][1];
            d = info.Map[y][x][1];
            int yy = y + dir[d][0], xx = x + dir[d][1];
            int cnt=1; 
            while(yy<0 || xx <0 || yy >= 4 || xx >= 4 || (yy == shark.y && xx == shark.x)){
                if(cnt++ > 8) break;
                d = (d+1) % 8; // 방향 바꿈
                yy = y + dir[d][0];
                xx = x + dir[d][1];
            }
            if(cnt > 8) continue;

            if(info.Map[yy][xx][0] != 0){
                info.fishes[info.Map[yy][xx][0]][0] = y;
                info.fishes[info.Map[yy][xx][0]][1] = x;
                info.Map[y][x][0] = info.Map[yy][xx][0];
                info.Map[y][x][1] = info.Map[yy][xx][1];
            }
            else{
                info.Map[y][x][0] = 0;
                info.Map[y][x][1] = -1;
            }
            info.fishes[i][0] = yy;
            info.fishes[i][1] = xx;
            info.Map[yy][xx][0] = i;
            info.Map[yy][xx][1] = d;

        }
    }
    return info;
}
int move_shark(INFO info, SHARK shark){
    /*
        상어가 움직여서 먹을 수 있는 물고기 번호의 합의 최댓값을 구한다.

        return max값
    */
    shark.num_sum += info.Map[shark.y][shark.x][0]; // 먹은 물고기 번호 더함
    shark.d = info.Map[shark.y][shark.x][1];
    info.fishes[info.Map[shark.y][shark.x][0]][0] = -1; // 먹은 물고기 정보 지우기
    info.Map[shark.y][shark.x][0] = 0; // 상어가 이동한 칸의 물고기 없음
    info.Map[shark.y][shark.x][1] = -1; // ,,
    INFO move_F;
    move_F = move_fish(info, shark);
    int sy, sx;
    sy = shark.y; 
    sx = shark.x; 
    int SS = shark.num_sum;
    while (1)
    {
        sy += dir[shark.d][0];
        sx += dir[shark.d][1];
        if(sy < 0 || sx < 0 || sy >= 4 || sx >=4 ) break;
        if(move_F.Map[sy][sx][0] == 0) continue;
        shark.num_sum = max(shark.num_sum, move_shark(move_F, {sy, sx, shark.d, SS}));
    }
    return shark.num_sum;

}

int main(){
    INFO info;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>> info.Map[i][j][0] >> info.Map[i][j][1];
            info.Map[i][j][1]--;
            info.fishes[info.Map[i][j][0]][0] = i;
            info.fishes[info.Map[i][j][0]][1] = j;
        }
    }
    // 상어
    SHARK shark = {0, 0, 0, 0};
 
    // 상어가 움직여 물고기를 먹는다.
    cout << move_shark(info, shark);
}