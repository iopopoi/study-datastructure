/*
    16235. 나무 재테크
    N : map의 크기
    M : 심은 나무의 수
    K: K년 후에 몇그루의 나무가 살아남은 나무의 수는?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N, M, K;  
int A[11][11]; // 겨울에 받는 영양분
int Map[11][11]; // map의 각지역의 영양분을 말한다.
int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int yy, xx;

void Spring(){
    
}

void Summer(){

}

void Fall(){

}

void Winter(){

}

int main(){
    cin >> N >> M >> K;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }

    int x, y, z;
    for(int i=0;i<M;i++){
        cin >> y >> x >> z;
    }
    // 가장 처음에 양분은 모든 칸에 5만큼 들어있다.
    memset(Map, 5,sizeof(Map));

    for(int i=0;i<K;i++){
        Spring();
        Summer();
        Fall();
        Winter();
    }
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        }
    }
    cout << cnt;
}