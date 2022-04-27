#include<iostream>
#include <algorithm>
using namespace std;


struct Matrix{
  int map[21][21];
};

int N, mm, spot;
Matrix field;

Matrix moveD(Matrix M){
  for(int i=0;i<N;i++){
    spot = N-1;
    for(int j=N-1;j>=0;j--){
      if(M.map[j][i] != 0 && j != spot){
        if(M.map[j][i] == M.map[spot][i]){
          M.map[spot][i] *= 2;
          M.map[j][i] = 0;
          spot --;
        }
        else if(M.map[spot][i] == 0){
          M.map[spot][i] = M.map[j][i];
          M.map[j][i] = 0;
        }
        else{
          spot--;
          M.map[spot][i] = M.map[j][i];
          spot != j ? (M.map[j][i] = 0) : 1;
        }
      }
    }
  }
  return M;
}

Matrix moveL(Matrix M){
  for(int i=0;i<N;i++){
    spot = 0;
    for(int j=0;j<N;j++){
      if(M.map[i][j] != 0 && j != spot){
        if(M.map[i][j] == M.map[i][spot]){
          M.map[i][spot] *= 2;
          M.map[i][j] = 0;
          spot ++;
        }
        else if(M.map[i][spot] == 0){
          M.map[i][spot] = M.map[i][j];
          M.map[i][j] = 0;
        }
        else{
          spot++;
          M.map[i][spot] = M.map[i][j];
          spot != j ? (M.map[i][j] = 0) : 1;
        }
      }
    }
  }
  return M;
}

Matrix moveR(Matrix M){
  for(int i=0;i<N;i++){
    spot = N-1;
    for(int j=N-1;j>=0;j--){
      if(M.map[i][j] != 0 && j != spot){
        if(M.map[i][j] == M.map[i][spot]){
          M.map[i][spot] *= 2;
          M.map[i][j] = 0;
          spot--;
        }
        else if(M.map[i][spot] == 0){
          M.map[i][spot] = M.map[i][j];
          M.map[i][j] = 0;
        }
        else{
          spot--;
          M.map[i][spot] = M.map[i][j];
          spot != j ? (M.map[i][j] = 0) : 1;
        }
      }
    }
  }
  return M;
}

Matrix moveU(Matrix M){
  for(int i=0;i<N;i++){
    spot = 0;
    for(int j=0;j<N;j++){
      if(M.map[j][i] != 0 && j != spot){
        if(M.map[j][i] == M.map[spot][i]){
          M.map[spot][i] *= 2;
          M.map[j][i] = 0;
          spot ++;
        }
        else if(M.map[spot][i] == 0){
          M.map[spot][i] = M.map[j][i];
          M.map[j][i] = 0;
        }
        else{
          spot++;
          M.map[spot][i] = M.map[j][i];
          spot != j ? (M.map[j][i] = 0) : 1;
        }
      }
    }
  }
  return M;
}



int BF(Matrix m, int time){
  int re=0;
  if(time == 5){
    mm = 0;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        mm = max(mm, m.map[i][j]);
    return mm;
  }
  re = max(BF(moveU(m), time+1), BF(moveD(m), time+1));
  re = max(BF(moveL(m), time+1), re);
  re = max(BF(moveR(m), time+1), re);
  return re;
}

void p(Matrix m){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << m.map[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> field.map[i][j];
    }
  }

  cout << BF(field, 0);
//   p(moveU(field));
}