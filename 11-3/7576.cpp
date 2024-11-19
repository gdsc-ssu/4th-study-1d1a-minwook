#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
queue<pair<int,int> > q;

void bfs(vector<vector<int> >& box, vector<vector<bool> >& visited, vector<vector<int> >& distance, int y, int x){

    while(!q.empty()){
        int uy = q.front().first;
        int ux = q.front().second;
        visited[uy][ux] = true;
        q.pop();
        for (int i=0; i<4; i++){
            int ddy = uy + dy[i];
            int ddx = ux + dx[i];
            if (ddy < 0 || ddx < 0 || ddy >= N || ddx >= M || box[ddy][ddx] == -1 || box[ddy][ddx] == 1){
                continue;
            }
            else{
                if(!visited[ddy][ddx]){
                    distance[ddy][ddx] = distance[uy][ux] + 1;
                    visited[ddy][ddx] = true;
                    q.push(make_pair(ddy,ddx));
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    vector<vector<int> > box(N, vector<int>(M));
    vector<vector<bool> > visited(N, vector<bool>(M));
    vector<vector<int> > distance(N, vector<int>(M));

    int starty, startx;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int num;
            cin >> num;
            box[i][j] = num;
            visited[i][j] = false;
            distance[i][j] = 0;
            if(num == 1){
                q.push(make_pair(i,j));
            }
            if(num == -1){
                visited[i][j] = true;
            }
        }
    }

    if (!q.empty()){
        starty = q.front().first;
        startx = q.front().second;

        bfs(box, visited, distance, starty, startx);
    }

    // cout << "==============distance graph=================" <<'\n';
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++)
    //         cout << distance[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << "==============vistied graph=================" <<'\n';
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++)
    //         cout << visited[i][j] << ' ';
    //     cout << '\n';
    // }

    int sum = 0;
    int result = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j]){
                cout << "-1" << '\n';
                return 0;
            }
            sum += distance[i][j];
            if (result < distance[i][j]){
                result = distance[i][j];
            }
        }
    }

    if(sum == 0){
        cout << "0" << '\n';
    }
    else{
        cout << result << '\n';
    }

    return 0;
}