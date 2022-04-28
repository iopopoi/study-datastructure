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
int A[11][11], need[11][11]; // 겨울에 받는 영양분
int Map[11][11]; // map의 각지역의 영양분을 말한다.
int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int yy, xx;


typedef struct TREE{
    int y, x, age;
}Tree;

vector< vector < vector<int> > > forest(11, vector<vector<int>>(11)); // ages

vector<Tree> dead_trees;

void Spring(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(forest[i][j].size()>0){
                if(need[i][j]<=Map[i][j]){
                    Map[i][j] -= need[i][j];
                    need[i][j] += forest[i][j].size();
                    for(int k=0;k<forest[i][j].size();k++)
                        forest[i][j][k]++;
                }
                else{
                    sort(forest[i][j].begin(), forest[i][j].end());
                    for(int k=0;k<forest[i][j].size();k++){
                        if(forest[i][j][k] <= Map[i][j]){
                            Map[i][j] -= forest[i][j][k]; //나무의 나이만큼 영양분 소모
                            forest[i][j][k] ++; // 나이 증가
                            need[i][j]++;
                        }
                        else{
                            while(forest[i][j].size()>k){
                                dead_trees.push_back({i, j, forest[i][j][forest[i][j].size()-1]});
                                need[i][j] -= forest[i][j][forest[i][j].size()-1];
                                forest[i][j].pop_back();
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Summer(){
    int i = dead_trees.size()-1;
    for(; i >= 0 ; i--){
        Map[dead_trees[i].y][dead_trees[i].x] += dead_trees[i].age/2;
        dead_trees.pop_back();
    }
}

void Fall(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<forest[i][j].size();k++){
                if(forest[i][j][k]%5==0){
                    for(int x=0;x<8;x++){
                        yy = i + dir[x][0];
                        xx = j + dir[x][1];
                        if(yy <0 || xx < 0 || yy >= N || xx >= N) continue;
                        forest[yy][xx].push_back(1);
                        need[yy][xx]++;
                    }
                }
            }
        }
    }
}

void Winter(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            Map[i][j] += A[i][j];
}


int main(){
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
            need[i][j] = 0;
            Map[i][j] = 5;
        }
    }

    int x, y, z;
    for(int i=0;i<M;i++){
        cin >> y >> x >> z;
        forest[y-1][x-1].push_back(z);
        need[y-1][x-1] += z;
    }

    int cnt = 0;
    for(int k=0;k<K;k++){
        Spring();
        Summer();
        Fall();
        Winter();
    }
    cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cnt += forest[i][j].size();
        }
    }
    cout << cnt;
}