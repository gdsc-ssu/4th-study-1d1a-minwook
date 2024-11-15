#include <iostream>
#include <vector>

using namespace std;

int N, M;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void dfs(vector<vector<char> >& school, int y, int x, int& count,int N, int M){
    if(school[y][x] == 'P')
        count++;
    school[y][x] = 'X';
    
    for (int i=0; i<4; i++){
        int ddy = dy[i] + y;
        int ddx = dx[i] + x;
        if (ddy<0 || ddx<0 || ddy >= N || ddx >= M || school[ddy][ddx] == 'X'){
            continue;
            
        }
        if (school[ddy][ddx] != 'X'){
            dfs(school, ddy, ddx, count,N, M);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<vector<char> > school(N, vector<char>(M));
    int myy = 0;
    int myx = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char ch;
            cin >> ch;
            if( ch == 'I'){
                myy = i;
                myx = j;
            }
            school[i][j] = ch;
        }
    }

    int count =0;

    dfs(school, myy, myx, count, N, M);

    if (count == 0){
        cout << "TT" << '\n';
    }
    else {
        cout << count << '\n';
    }

    return 0;
}