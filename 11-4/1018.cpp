#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string WB[8]={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

string board[50];

int countWB(int y, int x){
    int count = 0;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[y+i][x+j] != WB[i][j]) count++;
        }
    }

    return count;
}

int countBW(int y, int x){
    int count = 0;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[y+i][x+j] != BW[i][j]) count++;
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> N >> M;
    cin.ignore();

    int mincnt = 10000;

    for(int i=0; i<N; i++){
        getline(cin, board[i]);
    }

    for(int i=0; i+8<=N; i++){
        for(int j=0; j+8<=M; j++){
            int temp = min(countWB(i,j), countBW(i,j));
            if (temp < mincnt) mincnt = temp;
        }
    }

    cout << mincnt << '\n';

    return 0;
}