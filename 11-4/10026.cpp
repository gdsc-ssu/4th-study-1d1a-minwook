#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void bfs(vector<vector<char> >& graph,vector<vector<bool> >& visited, int y, int x){
    queue<pair<int,int> > q;
    visited[y][x] = true;
    q.push(make_pair(y,x));

    while(!q.empty()){
        int uy = q.front().first;
        int ux = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ddy = uy + dy[i];
            int ddx = ux + dx[i];
            if(ddy<0 || ddx<0 || ddy>=N || ddx>=N || graph[ddy][ddx] != graph[y][x]){
                continue;
            }
            else{
                if(!visited[ddy][ddx]){
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

    cin >> N;
    vector<vector<char> > graph(N,vector<char>(N));
    vector<vector<bool> > visited(N,vector<bool>(N));

    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<N; j++){
            char ch = str[j];
            graph[i][j] = ch;
            visited[i][j] = false;
        }
    }
    
    int count = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                count ++;
                bfs(graph, visited, i, j);
            }
        }
    }

    cout << count << ' ';
    count = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j] == 'G') graph[i][j] = 'R';
            visited[i][j] = false;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                count ++;
                bfs(graph, visited, i, j);
            }
        }
    }
    
    cout << count << '\n';
    
    return 0;
}