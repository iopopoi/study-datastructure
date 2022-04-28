// #include <iostream>
// #include <queue>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int N, ans;
int Map[21][21];
int chk[21][21]; // shark가 다음 먹을 물고기를 찾을 때 사용하는 chk배열
int dir[4][2] = {{-1, 0}, {0, -1},{0, 1}, {1, 0}};
struct SHARK{
    int size = 2;
    int cnt = 0;
    int y, x;// 상어의 현재 위치
}shark;

int next_fish(){ 
    /*
        상어가 다음으로 먹을 물고기를 찾는다. 해당 물고기를 먹는데 까지 걸리는 시간을 구한다.
        bfs를 이용한다. 상어는 위, 왼쪽, 오른쪽, 아래쪽 차례로 우선하여 탐색한다. : dir 배열이용.

        return
        0 : 먹을 수 있는 물고기가 없다. 
        else: 물고기를 먹는데까지 걸리는 시간
    */

    queue<pair<pair<int, int>,int> > q; // {{y, x}, time}
    priority_queue<pair<int,int> > pq; // 가까운 정점
    int time = 0; // 가장 가까운 물고기 까지의 거리
    q.push({{shark.y, shark.x}, 0});
    chk[shark.y][shark.x] = 1;
    while(!q.empty()){
        int y = q.front().first.first, x = q.front().first.second, t= q.front().second;
        q.pop();
        if(time != 0 && t > time) break;
        if(Map[y][x] != 0 && Map[y][x] < shark.size){ // y,x에 상어가 먹을 수 있는 물고기가 있다.
            if(time == 0) time = t;
            pq.push({-y, -x});
        }

        for(int i=0;i<4;i++){
            int ny = y + dir[i][0], nx = x + dir[i][1];
            if( ny < 0 || nx < 0 || ny >= N || nx >= N ) continue;
            if(Map[ny][nx] <= shark.size && chk[ny][nx] == 0){
                q.push({{ny, nx}, t + 1});
                chk[ny][nx] = 1;
            }
        }
    }
    if(time != 0){
        shark.y = -pq.top().first;
        shark.x = -pq.top().second;
        Map[shark.y][shark.x] = 0;
        if(++shark.cnt == shark.size){ // 상어가 물고기를 자신의 크기만큼 먹었으면 커진다.
            shark.size++;
            shark.cnt = 0;
        }
    }
    return time; 
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>> Map[i][j];
            if(Map[i][j] == 9){
                Map[i][j] = 0;
                shark.y = i;
                shark.x = j;
            }
        }
    }
    int re;
    while(1){
        memset(chk, 0, sizeof(chk));
        re = next_fish();
        // cout << re << " : ";
        if(re == 0) break;
        ans += re;
        // cout << shark.y << " : " << shark.x << " : " << ans<< "\n";
    }
    cout << ans;
}