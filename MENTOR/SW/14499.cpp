/*
    14499. 주사위 굴리기
    
    주사위의 마주보는 면의 index 합은 7이다. (1번 면과 마주보는 면은 6번 면이다.)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
int y, x; // 주사위의 위치
int arr[21][21];
int dir[5][2] = {{0,0}, {0, 1}, {0, -1},{-1, 0}, {1, 0}};

int dice[7], Top=1, Right=3; // 주사위 1 ~ 6번 면에 적어져 있는 번호
vector <vector<int> > move_bot;

void move_dice(int D){
    /*
        주어진 방향으로 주사위를 이동시키고 주사위 윗면의 수를 출력한다.
    */
   if(D == 1){ // 동
    int temp = Top;
    Top = 7 - Right;
    Right = temp;
   }
   else if(D == 2){ // 서
    int temp = Top;
    Top = Right;
    Right = 7 - temp;
   }
   else if(D == 3){ // 북
    Top = move_bot[Top][Right];
   }
   else if(D == 4){ // 남
    Top = move_bot[Top][Right];
    Top = 7 - Top;
   }

   if(arr[y][x] == 0){
       arr[y][x] = dice[7 - Top];
   }
   else{
       dice[7 - Top] = arr[y][x];
       arr[y][x] = 0;
   }
   cout << dice[Top] << "\n";
}

int main(){
    cin >> N >> M >> y >> x >> K;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    
    move_bot.push_back({0});
    move_bot.push_back({0, 0, 3, 5, 2, 4, 0});// top : 1
    move_bot.push_back({0, 4, 0, 1, 6, 0, 3});// top : 2
    move_bot.push_back({0, 2, 6, 0, 0, 1, 5});// top : 3
    move_bot.push_back({0, 5, 1, 0, 0, 6, 2});// top : 4
    move_bot.push_back({0, 3, 0, 6, 1, 0, 4});// top : 5
    move_bot.push_back({0, 0, 4, 2, 5, 3, 0});// top : 6

    int D, nx, ny; // 명령: 이동 방향 동-1, 서-2, 북-3, 남-4
    for(int k=0;k < K; k++){
        cin >> D;
        ny = y + dir[D][0], nx = x + dir[D][1];
        // cout << D << ":" << y << " : "<< x << " : "<< ny << " : " << nx << "\n";
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        y = ny; x = nx;        
        move_dice(D);
    }
}