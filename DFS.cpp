//dir 상하좌우 인접한 값
//dfs 재귀함수로 했다가 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int arr[501][501];
int chk[501][501];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int dfs(int y, int x) {
    int re = 1;
    chk[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int yy = y+dir[i][0], xx = x+dir[i][1];
		if(yy<N && xx<M && yy>=0 && xx>=0) {
			if(arr[yy][xx]==1 && chk[yy][xx] == 0) {
				re += dfs(yy, xx);
			}
		}
	}
	return re;
}

int main(){
	int ans = 0;
	int cnt = 0;
	cin>>N>>M;
	for(int i = 0; i<N; i++) {
		for(int j = 0; j<M; j++) {
			cin>>arr[i][j];
		}
	}
	for(int i = 0; i<N; i++) {
		for(int j = 0; j<M; j++) {
			if(chk[i][j] == 0 && arr[i][j] ==1) {
				ans = max(ans, dfs(i, j));
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n"<<ans;
}
