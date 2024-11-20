#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int N, M;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void bfs(vector<vector<int> >& miro, vector<vector<int> >&distance, vector<vector<int> >& visited, int y, int x){
    queue<pair<int,int> > q;
    visited[y][x] = 1;
    q.push(make_pair(y,x));
    
    while(!q.empty()){
        int uy = q.front().first;
        int ux = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ddy = uy + dy[i];
            int ddx = ux + dx[i];

            if(ddy<0 || ddx<0 || ddy>=N || ddx>=M || miro[ddy][ddx] == 0){
                continue;
            }
            if(!visited[ddy][ddx]){
                distance[ddy][ddx] = distance[uy][ux] + 1;
                visited[ddy][ddx] = 1;
                q.push(make_pair(ddy,ddx));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin.ignore();

    vector<vector<int> > miro(N,vector<int>(M));
    vector<vector<int> > distance(N,vector<int>(M));
    vector<vector<int> > visited(N,vector<int>(M));


    for(int i=0; i<N; i++){
        string str;
        getline(cin, str);
        for(int j=0; j<M; j++){
            int num = str[j] - '0';
            miro[i][j] = num;
            visited[i][j] = 0;
            distance[i][j] = 0;
            if(num == 0){
                visited[i][j] = 1;
            }
        }
    }
    distance[0][0] = 1;
    
    bfs(miro, distance, visited, 0, 0);

    cout << distance[N-1][M-1] << '\n';

    return 0;
}